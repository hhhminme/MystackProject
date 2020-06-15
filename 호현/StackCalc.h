#pragma once
#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;

class MyStack {
public:
    int tos;        // top of stack
    int* data;    // T 타입의 배열. 스택의 크기는 100
    unsigned capacity;
    MyStack() {
        tos = -1;
        data = new int[100];
    }
    ~MyStack() { delete[] data; }
    void push(int element); // 원소 element를 data [] 배열에 삽입
    int pop(); //  스택의 탑에 있는 데이터를 data[] 배열에서 리턴
    int getTos() { return tos; }
};


template<class T>
class Calcul {
protected:
    T a, b;
public:
    virtual T show(T a, T b) = 0;
};

template<class T>
class Adder :public Calcul<T> {
public:
    T show(T a, T b) { return a + b; }
};

template<class T>
class Substracter :public Calcul<T> {
public:
    T show(T a, T b) { return a - b; }
};

template<class T>
class Mutltiple :public Calcul<T> {
public:
    T show(T a, T b) { return a * b; }
};

template<class T>
class Division :public Calcul<T> {
public:
    T show(T a, T b) { return a / b; }
};

void MyStack::push(int element) {
    if (tos == 99) {
        cout << "Stack Full" << endl;
        exit(-1);
    }
    data[++tos] = element;  // data 배열에 element 저장
}

int MyStack::pop() {
    if (tos == -1) {
        cout << "Stack empty" << endl;
        exit(-1);
    }

    return data[tos--];
}

// Stack Operations 
MyStack* createStack(unsigned capacity) {
    MyStack* pstack = new MyStack;

    if (!pstack)
        return NULL;

    pstack->tos = -1;
    pstack->capacity = capacity;
    pstack->data = new int[(pstack->capacity) * sizeof(int)];

    return pstack;
}
int isEmpty(MyStack* pstack)
{
    return pstack->tos == -1;
}
char peek(MyStack* pstack)
{
    return pstack->data[pstack->tos];
}
char pop(MyStack* pstack)
{
    if (!isEmpty(pstack))
        return pstack->data[pstack->tos--];
    return '$';
}
void push(MyStack* pstack, char op)
{
    pstack->data[++pstack->tos] = op;
}
// A utility function to check if the given character is operand 
int isOperand(char ch)
{
    // return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    return (ch >= '0' && ch <= '9');
}
// A utility function to return precedence of a given operator 
// Higher returned value means higher precedence 
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// The main function that converts given infix expression 
// to postfix expression.  
int infixToPostfix(char* exp)
{
    int i, k;

    // Create a stack of capacity equal to expression size  
    MyStack* pstack = createStack(strlen(exp));
    if (!pstack) // See if stack was created successfully  
        return -1;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output. 
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (exp[i] == '(')
            push(pstack, exp[i]);

        // If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
        else if (exp[i] == ')')
        {
            while (!isEmpty(pstack) && peek(pstack) != '(')
                exp[++k] = pop(pstack);
            if (!isEmpty(pstack) && peek(pstack) != '(')
                return -1; // invalid expression              
            else
                pop(pstack);
        }
        else // an operator is encountered 
        {
            while (!isEmpty(pstack) && Prec(exp[i]) <= Prec(peek(pstack)))
                exp[++k] = pop(pstack);
            push(pstack, exp[i]);
        }

    }

    // pop all the operators from the stack 
    while (!isEmpty(pstack))
        exp[++k] = pop(pstack);

    exp[++k] = '\0';
    cout << "후위 표기식으로 변환: " << exp << endl;
    return 0;
}


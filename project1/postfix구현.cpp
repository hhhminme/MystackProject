#include <iostream>
#include <cctype>
#define STACK_ARRAY_SIZE 100

using namespace std;

template <class T>
class MyStack {
	T data[STACK_ARRAY_SIZE];
	int tos; //top of stack
public:
	MyStack();
	void push(T element);
	T pop();
	T peek(); //peek 
	T isEmpty();
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	
	data[++tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	if (tos == -1) {
		cout << "stack empty\n";
		return 0;
	}
	T retData;
	retData = data[tos--];
	return retData;
}

template<class T>
T MyStack<T>::peek() { /// peek임 
	return data[tos];
}

template<class T>
T MyStack<T>::isEmpty() {
	return tos == -1; // tos가 -1이면 1
}
class Calculator {
public:
	int a, b;
	virtual int calc(int a, int b) = 0;
};

class Add : public Calculator {
public:
	int calc(int a, int b) {
		return a + b;
	}
};

class Subtract : public Calculator {
public:
	int calc(int a, int b) {
		return a - b;
	}
};

class Division : public Calculator {
public:
	int calc(int a, int b) {
		return a / b;
	}
};

class Multiply : public Calculator {
public:
	int calc(int a, int b) {
		return a * b;
	}
};

class Opercalc {
public:
	int Prec(char ch);
	int isOperand(char ch);
};

int Opercalc::Prec(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	}
	return -1;
}

int Opercalc::isOperand(char ch) {
	return (ch >= '0' && ch <= '9');
}

int main() {
	int i, k;
	MyStack<char>Stack;
	MyStack<int> ipStack;

	Opercalc op;
	Add adder;
	Subtract subtractor;
	Division divisior;
	Multiply multiplier;

	char exp[] = "3+4/4*3-2*5";

	for (i = 0, k = -1; exp[i]; i++) {
		if (op.isOperand(exp[i]))
			exp[++k] = exp[i];

		else if (exp[i] == '(')
			Stack.push(exp[i]);

		else if (exp[i] == ')')
		{
			while (!Stack.isEmpty() && Stack.peek() != '(')
				exp[++k] = Stack.pop();
			if (!Stack.isEmpty() && Stack.peek() != '(')
				return -1; // invalid expression              
			else
				Stack.pop();
		}
		else // an operator is encountered 
		{
			while (!Stack.isEmpty() && op.Prec(exp[i]) <= op.Prec(Stack.peek()))
				exp[++k] = Stack.pop();
			Stack.push(exp[i]);
		}
	}

	while (!Stack.isEmpty())
		exp[++k] = Stack.pop();

	exp[++k] = '\0';
	printf("%s\n", exp);

	for (i = 0; exp[i]; i++) {
		if (exp[i] == ' ') continue;

		else if (isdigit(exp[i])) {
			ipStack.push(exp[i]-'0');
		}

		else {
			int val2 = ipStack.pop();
			int val1 = ipStack.pop();
			
			switch (exp[i])
			{
			case '+':
				ipStack.push(adder.calc(val1, val2));
				break;
			case '-':
				ipStack.push(subtractor.calc(val1, val2));
				break;
			case '*':
				ipStack.push(multiplier.calc(val1, val2));
				break;
			case '/':
				ipStack.push(divisior.calc(val1, val2));
				break;
			}
		}
	}
	cout << "result : " << ipStack.pop() << endl;
	
}
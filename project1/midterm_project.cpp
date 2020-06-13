#include <iostream>
#include <cctype>
#define STACK_ARRAY_SIZE 100
#define VALUE_SIZE 100
using namespace std;

template <class T>
class MyStack {
	T data[STACK_ARRAY_SIZE];
public:
	int tos; //top of stack
	MyStack();
	void push(T element);
	T pop();
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
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack empty\n";
		return 0;
	}
	retData = data[tos--];
	return retData;
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
int main() {

	char exp[] = "4/2+3";

	MyStack<int> ipStack;
	MyStack<char> cpStack;

	Add adder;
	Subtract subtractor;
	Division divisior;
	Multiply multiplier;

	int i;

	for (i = 0; exp[i]; i++) {
		if (exp[i] == ' ') continue;

		else if (isdigit(exp[i])) {
			int num = 0;

			while (isdigit(exp[i])) {
				num = num * 10 + (int)(exp[i] - '0');
				i++;
			}
			i--;
			ipStack.push(num);
		}

		else {
			cpStack.push(exp[i]);
		}

	}

	while (!(cpStack.tos == -1)) {

		int val1 = ipStack.pop();
		int val2 = ipStack.pop();

		switch (cpStack.pop())
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

	cout << "result : " << ipStack.pop() << endl;


	return 0;
}
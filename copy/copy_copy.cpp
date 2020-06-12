#include <iostream>
#include <cctype> 

#define ARRAY_MAX 128

template <class T>
class MyStack {
	int tos; //스택 상단
	T data[ARRAY_MAX];
public:
	MyStack(); 
	void push(T element);
	T pop();
};

template <class T> 
MyStack<T>::MyStack(){ //생성자
	tos = -1; 
}

template <class T>
void MyStack<T>::push(T element) { 
	if (tos == ARRAY_MAX - 1) {
		cout << "stack pull";
		return -1;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData; 
	if (tos == -1) {
		cout << "stack empty";
		return 0;
	}
	retData = data[tos--];
	return retData;
}

class calculator {

};


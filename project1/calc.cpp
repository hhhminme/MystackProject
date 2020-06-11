//class Calculator {
//public:
//	virtual int add(int a, int b) = 0;
//	virtual int subtract(int a, int b) = 0;
//	virtual int multiple(int a, int b) = 0;
//	virtual int divide(int a, int b) = 0;
//};
//
//class stackCalc : public Calculator {
//public:
//	int add(int a, int b) { return a + b; }
//	int subtract(int a, int b) { return a - b; }
//	int multiple(int a, int b) { return a * b; }
//	int divide(int a, int b) { return a / b; }
//
//};
//
//
//// 원래 오리지널 코드 
//class Calculator {
//
//protected:
//	int a;
//	int b;
//	virtual int calc(int a, int b) = 0; // 두 정수의 합 리턴
//public:
//	int run(int a, int b) {
//		this->a = a; this->b = b;
//		calc(a, b);
//	}
//};
//
//class Add : public Calculator {
//protected:
//	int calc(int a, int b) { // 순수 가상 함수 구현
//		return a + b;
//	}
//};
//
//class Subtract : public Calculator {
//protected:
//	int calc(int a, int b) { // 순수 가상 함수 구현
//		return a - b;
//	}
//};
//
//class Division : public Calculator {
//protected:
//	int calc(int a, int b) { // 순수 가상 함수 구현
//		return a - b;
//	}
//};
//
//class Multiply : public Calculator {
//protected:
//	int calc(int a, int b) { // 순수 가상 함수 구현
//		return a - b;
//	}
//};
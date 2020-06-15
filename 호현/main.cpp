#include"StackCalc.h"

int main() {
    MyStack stack;       // 두 피연산자의 값을 저장하는 스택

    Adder<int> add;
    Substracter<int> sub;
    Mutltiple<int> mul;
    Division<int> div;

    char exp[] = "3+4/4*3-2*5"; // 우선순위 안 따짐   --> 5
    char op;    // 연산자 저장

    cout << "수식: " << exp << endl;

    if (infixToPostfix(exp) == -1) {
        cout << "잘못된 수식입니다." << endl;
        return 0;
    }

    for (int i = 0; i < strlen(exp); i++) {
        if (isdigit(exp[i]))    // 읽은 값이 숫자이면
            stack.push(exp[i] - '0');       // 스택에 푸시
        else {
            // 스택에 있는 두 개의 정수를 빼서 연산자와 계산 후 다시 스택에 저장
            op = exp[i];
            int num1, num2;
            num2 = stack.pop();
            num1 = stack.pop();

            if (op == '+')
                stack.push(add.show(num1, num2));
            else if (op == '-')
                stack.push(sub.show(num1, num2));
            else if (op == '*')
                stack.push(mul.show(num1, num2));
            else if (op == '/')
                stack.push(div.show(num1, num2));
            else {
                cout << "Invalid input" << endl;
                exit(-1);
            }
        }
    }

    cout << "계산 결과는 " << stack.pop() << endl;
    return 0;
}
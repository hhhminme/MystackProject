#include"StackCalc.h"

int main() {
    MyStack stack;       // �� �ǿ������� ���� �����ϴ� ����

    Adder<int> add;
    Substracter<int> sub;
    Mutltiple<int> mul;
    Division<int> div;

    char exp[] = "3+4/4*3-2*5"; // �켱���� �� ����   --> 5
    char op;    // ������ ����

    cout << "����: " << exp << endl;

    if (infixToPostfix(exp) == -1) {
        cout << "�߸��� �����Դϴ�." << endl;
        return 0;
    }

    for (int i = 0; i < strlen(exp); i++) {
        if (isdigit(exp[i]))    // ���� ���� �����̸�
            stack.push(exp[i] - '0');       // ���ÿ� Ǫ��
        else {
            // ���ÿ� �ִ� �� ���� ������ ���� �����ڿ� ��� �� �ٽ� ���ÿ� ����
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

    cout << "��� ����� " << stack.pop() << endl;
    return 0;
}
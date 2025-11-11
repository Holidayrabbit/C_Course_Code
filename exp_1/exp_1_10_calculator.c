#include <stdio.h>

int main() {
    double operand1, operand2, result;
    char operator;

    printf("请输入一个形式如\"操作数 运算符 操作数\"的四则运算表达式:\n");
    printf("例如: 10+2 或 10/2\n");
    printf("请输入: ");

    scanf("%lf%c%lf", &operand1, &operator, &operand2);

    switch (operator) {
        case '+':
            result = operand1 + operand2;
            printf("%.2f + %.2f = %.2f\n", operand1, operand2, result);
            break;
        case '-':
            result = operand1 - operand2;
            printf("%.2f - %.2f = %.2f\n", operand1, operand2, result);
            break;
        case '*':
            result = operand1 * operand2;
            printf("%.2f * %.2f = %.2f\n", operand1, operand2, result);
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
                printf("%.2f / %.2f = %.2f\n", operand1, operand2, result);
            } else {
                printf("错误: 除数不能为0!\n");
            }
            break;
        default:
            printf("错误: 不支持的运算符 '%c'\n", operator);
            printf("支持的运算符: +, -, *, /\n");
            break;
    }

    return 0;
}
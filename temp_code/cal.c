#include <stdio.h>

int main() {
    // 定义两个操作数和一个运算符
    int num1;
    int num2;
    char op;
    // 读取输入的表达式
    scanf("%d%c%d", &num1, &op, &num2);
    // scanf_s("%d%c%d", &num1, &op, 1, &num2);


    // 根据不同的运算符执行相应运算
    switch (op) {
    case '+':
        printf("%d\n", num1 + num2);
        break;
    case '-':
        printf("%d\n", num1 - num2);
        break;
    case '*':
        printf("%d\n", num1 * num2);
        break;
    case '/':
        // 注意：这里假设除数num2不为0，实际使用中可增加除数为0的判断
        printf("%d\n", num1 / num2);
        break;
    default:
        printf("无效的运算符\n");
    }

    return 0;
}
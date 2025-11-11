#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    printf("请输入一个字符: ");
    ch = getchar();

    if (isalpha(ch)) {
        // 如果是英文字母，转换为大写
        printf("大写字母: %c\n", toupper(ch));
    } else if (isdigit(ch)) {
        // 如果是数字，打印二进制形式
        int digit = ch - '0';
        printf("二进制形式: ");
        for (int i = 3; i >= 0; i--) {
            printf("%d", (digit >> i) & 1);
        }
        printf("\n");
    } else {
        // 其他字符，打印ASCII码
        printf("ASCII码: %d\n", ch);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int len, is_palindrome = 1;

    printf("请输入一个字符串：");
    scanf("%s", str);

    len = strlen(str);

    // 检查回文
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - 1 - i])) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

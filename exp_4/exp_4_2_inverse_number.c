/*
 * 实验4-2: 数字字符串逆序
 * 功能: 输入一个数字字符串，输出其逆序
 *       例如: "123" -> "321", "-123" -> "-321"
 */

#include <stdio.h>
#include <string.h>

// 计算字符串长度
int str_len(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// 数字字符串逆序函数
void inverse_number(char* str, char* str_inv) {
    int len = str_len(str);
    int start = 0;
    int j = 0;

    // 如果是负数，先复制负号
    if (str[0] == '-') {
        str_inv[0] = '-';
        start = 1;
        j = 1;
    }

    // 从后往前复制数字
    for (int i = len - 1; i >= start; i--) {
        str_inv[j++] = str[i];
    }
    str_inv[j] = '\0';
}

int main() {
    char str[100], str_inv[100];

    printf("请输入一个数字字符串: ");
    scanf("%s", str);

    inverse_number(str, str_inv);

    printf("原字符串: %s\n", str);
    printf("逆序后: %s\n", str_inv);

    return 0;
}

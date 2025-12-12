/*
 * 实验4-1: 复制元音字母
 * 功能: 将一个字符串中的元音字母（a、e、i、o、u）复制到另一个字符串中
 */

#include <stdio.h>
#include <string.h>

// 判断是否为元音字母
int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// 复制元音字母函数
void copy_vowel(char* str, char* str_inv) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_vowel(str[i])) {
            str_inv[j++] = str[i];
        }
    }
    str_inv[j] = '\0';  // 添加字符串结束符，如果不手动添加 '\0'，str_inv 就 不是一个合法的字符串
}

int main() {
    char str[100], str_inv[100];

    printf("请输入一个字符串: ");
    fgets(str, sizeof(str), stdin);

    // 去除换行符
    str[strcspn(str, "\n")] = '\0';

    copy_vowel(str, str_inv);

    printf("原字符串: %s\n", str);
    printf("元音字母: %s\n", str_inv);

    return 0;
}

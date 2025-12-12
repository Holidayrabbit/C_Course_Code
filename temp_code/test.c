#include <stdio.h>
#include <string.h>

// 功能函数：指针判断回文（返回1是回文，0不是）
int is_palindrome(char* str) {
    if (str == NULL || *str == '\0') return 0; // 空字符串不是回文

    char *left = str;                  // 左指针：指向字符串开头
    char *right = str + strlen(str) - 1; // 右指针：指向字符串末尾（排除'\0'）

    // 左右指针向中间移动，比较字符
    while (left < right) {
        if (*left != *right) return 0; // 字符不相等，不是回文
        left++;
        right--;
    }
    return 1; // 所有对称字符相等，是回文
}

int main() {
    char str[100];
    printf("请输入一个字符串（如level）：");
    // getchar(); // 吸收scanf可能残留的换行符
    fgets(str, sizeof(str), stdin); // 读取含空格的字符串（更安全）

    // 去除fgets读取的换行符（若存在）

    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    // 调用判断函数并输出结果
    if (is_palindrome(str)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
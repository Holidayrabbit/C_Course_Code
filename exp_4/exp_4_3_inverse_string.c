/*
 * 实验4-3: 单词逆序输出
 * 功能: 将一个字符串按照单词（而非字母）逆序输出
 *       例如: "I am a student" -> "student a am I"
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

// 字符串逆序函数（逆序指定范围）
void reverse_range(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 单词逆序函数
void inverse_string(char* str, char* str_inv) {
    int len = str_len(str);

    // 先复制字符串
    for (int i = 0; i <= len; i++) {
        str_inv[i] = str[i];
    }

    // 第一步：逆序整个字符串
    reverse_range(str_inv, 0, len - 1);

    // 第二步：逆序每个单词
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (str_inv[i] == ' ' || str_inv[i] == '\0') {
            reverse_range(str_inv, start, i - 1);
            start = i + 1;
        }
    }
}

int main() {
    char str[200], str_inv[200];

    printf("请输入一个字符串: ");
    fgets(str, sizeof(str), stdin);

    // 去除换行符
    str[strcspn(str, "\n")] = '\0';

    inverse_string(str, str_inv);

    printf("原字符串: %s\n", str);
    printf("单词逆序后: %s\n", str_inv);

    return 0;
}

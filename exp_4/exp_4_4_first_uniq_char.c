/*
 * 实验4-4: 找第一个只出现一次的字符
 * 功能: 给定一个字符串，找出第一个只出现一次的字符的索引
 *       如果不存在则返回-1
 *       例如: "leetcode" -> 0, "loveleetcode" -> 2
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

// 找第一个只出现一次的字符
int first_uniq_char(char* str) {
    int len = str_len(str);
    int count[256] = {0};  // 用于统计每个字符出现的次数

    // 第一遍遍历：统计每个字符出现的次数
    for (int i = 0; i < len; i++) {
        count[(unsigned char)str[i]]++;
    }

    // 第二遍遍历：找第一个只出现一次的字符
    for (int i = 0; i < len; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return i;
        }
    }

    return -1;  // 不存在只出现一次的字符
}

int main() {
    char str[100];
    int result;

    printf("请输入一个字符串: ");
    scanf("%s", str);

    result = first_uniq_char(str);

    if (result == -1) {
        printf("不存在只出现一次的字符\n");
    } else {
        printf("第一个只出现一次的字符是 '%c'，索引为 %d\n", str[result], result);
    }

    return 0;
}

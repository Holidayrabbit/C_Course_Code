#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char *left, *right;
    int isPalindrome = 1;

    printf("请输入一个字符串: ");
    scanf("%s", str);

    // 设置指针：left指向字符串开头，right指向字符串结尾
    left = str;
    right = str + strlen(str) - 1;  //char类型占用1个字节

    // 从两端向中间比较
    while (left < right) {
        if (*left != *right) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

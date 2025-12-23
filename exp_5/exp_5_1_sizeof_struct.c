/*
 * 实验5-1: 结构体内存对齐
 * 求 sizeof(struct A)和 sizeof(struct B),并解释原理
 */

#include <stdio.h>

struct A {
    int a;    // 4 bytes
    char b;   // 1 byte
    short c;  // 2 bytes
};

struct B {
    char b;   // 1 byte
    int a;    // 4 bytes
    short c;  // 2 bytes
};

int main() {
    printf("结构体内存对齐示例:\n");
    printf("================================\n\n");

    // 计算并输出结构体大小
    printf("sizeof(struct A) = %lu bytes\n", sizeof(struct A));
    printf("sizeof(struct B) = %lu bytes\n\n", sizeof(struct B));

    // 详细解释原理
    printf("原理解释:\n");
    printf("--------------------------------\n");
    printf("结构体 A 的内存布局:\n");
    printf("  int a:    4 bytes (偏移量 0-3)\n");
    printf("  char b:   1 byte  (偏移量 4)\n");
    printf("  padding:  1 byte  (偏移量 5, 为了对齐short)\n");
    printf("  short c:  2 bytes (偏移量 6-7)\n");
    printf("  总大小:   8 bytes (已按最大成员int的4字节对齐)\n\n");

    printf("结构体 B 的内存布局:\n");
    printf("  char b:   1 byte  (偏移量 0)\n");
    printf("  padding:  3 bytes (偏移量 1-3, 为了对齐int)\n");
    printf("  int a:    4 bytes (偏移量 4-7)\n");
    printf("  short c:  2 bytes (偏移量 8-9)\n");
    printf("  padding:  2 bytes (偏移量 10-11, 整体对齐到4的倍数)\n");
    printf("  总大小:   12 bytes\n\n");

    printf("内存对齐规则:\n");
    printf("1. 结构体成员按其类型的大小对齐\n");
    printf("2. 结构体整体大小是最大成员大小的倍数\n");
    printf("3. 不同的成员顺序会导致不同的填充字节\n");
    printf("4. 合理安排成员顺序可以节省内存空间\n");

    return 0;
}

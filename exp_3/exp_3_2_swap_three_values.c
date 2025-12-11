#include <stdio.h>

int main() {
    int i, j, k, temp;
    int *p1, *p2, *p3;

    printf("请输入三个整数 i, j, k: ");
    scanf("%d %d %d", &i, &j, &k);

    // 设置指针指向变量
    p1 = &i;
    p2 = &j;
    p3 = &k;

    printf("交换前: i=%d, j=%d, k=%d\n", *p1, *p2, *p3);

    // 通过指针进行交换：i的值赋给j，j的值赋给k，k的值赋给i
    temp = *p3;    // 保存k的值
    *p3 = *p2;     // j的值赋给k
    *p2 = *p1;     // i的值赋给j
    *p1 = temp;    // k的值赋给i

    printf("交换后: i=%d, j=%d, k=%d\n", *p1, *p2, *p3);

    return 0;
}

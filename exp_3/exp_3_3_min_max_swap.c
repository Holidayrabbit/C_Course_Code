#include <stdio.h>

int main() {
    int arr[10];
    int *p, *pMin, *pMax;
    int i, temp;

    printf("请输入10个整数: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // 初始化指针
    pMin = pMax = arr;

    // 查找最小值和最大值的指针
    for (p = arr + 1; p < arr + 10; p++) {
        if (*p < *pMin) {
            pMin = p;
        }
        if (*p > *pMax) {
            pMax = p;
        }
    }

    // 最小的数与第一个数对换
    temp = *pMin;
    *pMin = arr[0];
    arr[0] = temp;

    // 如果最大值原本在第一个位置，现在它已经被移到了pMin的位置
    if (pMax == arr) {
        pMax = pMin;
    }

    // 最大的数与最后一个数对换
    temp = *pMax;
    *pMax = arr[9];
    arr[9] = temp;

    printf("交换后的数组: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

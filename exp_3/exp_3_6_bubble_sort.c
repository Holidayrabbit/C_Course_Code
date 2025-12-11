#include <stdio.h>

// 冒泡排序函数，使用指针实现
void bubbleSort(int *arr, int n) {
    int i, j, temp;
    int *p1, *p2;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            p1 = arr + j;       // 指向当前元素
            p2 = arr + j + 1;   // 指向下一个元素

            // 如果前一个数大于后一个数，则交换
            if (*p1 > *p2) {
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }
}

int main() {
    int arr[10];
    int i;

    printf("请输入10个数字: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("排序前: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 调用冒泡排序函数
    bubbleSort(arr, 10);

    printf("排序后: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>

int main() {
    int arr[10];
    int max, max_index;

    printf("请输入10个整数：\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    max_index = 0;

    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }

    printf("最大值为：%d\n", max);
    printf("最大值的下标为：%d\n", max_index);

    return 0;
}

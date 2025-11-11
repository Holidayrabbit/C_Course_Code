#include <stdio.h>

int main() {
    int nums[4];
    int i, j, temp;

    printf("请输入4个整数: ");
    for (i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
    }

    // 冒泡排序
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                // 交换
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    printf("从小到大排序后: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
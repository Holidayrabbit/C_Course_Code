#include <stdio.h>

int main() {
    int arr[100] = {2, 6, 3, 7, 9};
    int n = 5;
    int target, found = 0, index;

    printf("当前数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("请输入要删除的数：");
    scanf("%d", &target);

    // 查找要删除的元素
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) {
        // 删除元素：将后面的元素前移
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("删除后的数组：");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("数组中没有找到该元素\n");
    }

    return 0;
}

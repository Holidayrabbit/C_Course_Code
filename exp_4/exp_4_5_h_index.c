/*
 * 实验4-5: 计算H指数（选做题）
 * 功能: 给定一位研究者的论文被引用次数的数组，计算H指数
 * H指数定义: 一位科学家有指数h是指他（她）的N篇论文中至多有h篇论文，
 *            分别被引用了至少h次，其余的N-h篇论文每篇被引用次数小于h次
 * 例如: citations=[3, 0, 6, 1, 5]，H指数为3
 */

#include <stdio.h>

// 冒泡排序（降序）
void bubble_sort_desc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 计算H指数
int h_index(int citations[], int n) {
    // 先将数组降序排序
    bubble_sort_desc(citations, n);

    int h = 0;
    // 遍历排序后的数组
    for (int i = 0; i < n; i++) {
        // 如果当前论文的引用次数 >= (i+1)，说明至少有(i+1)篇论文被引用了至少(i+1)次
        if (citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break;
        }
    }

    return h;
}

int main() {
    int n;
    int citations[100];

    printf("请输入论文数量: ");
    scanf("%d", &n);

    printf("请输入每篇论文的引用次数:\n");
    for (int i = 0; i < n; i++) {
        printf("第%d篇论文的引用次数: ", i + 1);
        scanf("%d", &citations[i]);
    }

    int result = h_index(citations, n);

    printf("\nH指数为: %d\n", result);

    // 输出排序后的引用次数（用于验证）
    printf("引用次数（降序）: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", citations[i]);
    }
    printf("\n");

    return 0;
}

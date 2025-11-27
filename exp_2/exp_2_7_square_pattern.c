#include <stdio.h>

int min(int a, int b, int c, int d) {
    int temp = a < b ? a : b;
    temp = temp < c ? temp : c;
    temp = temp < d ? temp : d;
    return temp;
}

int main() {
    int n;

    printf("请输入层数：");
    scanf("%d", &n);

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // 计算当前位置到四条边的最小距离
            int dist_top = i;
            int dist_bottom = size - 1 - i;
            int dist_left = j;
            int dist_right = size - 1 - j;

            // 当前位置的值 = n - 最小距离
            int value = n - min(dist_top, dist_bottom, dist_left, dist_right);

            printf("%d ", value);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    int matrix[3][3];
    float avg;

    printf("请输入一个3x3的整数矩阵：\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n各行的平均值：\n");
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
        avg = sum / 3.0;
        printf("第%d行的平均值：%.2f\n", i + 1, avg);
    }

    return 0;
}

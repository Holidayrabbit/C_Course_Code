#include <stdio.h>
#include <math.h>

int main() {
    int count = 0;

    printf("1-1000之间的完全平方数:\n");

    for (int i = 1; i * i <= 1000; i++) {
        printf("%4d ", i * i);
        count++;

        // 每行输出8个数
        if (count % 8 == 0) {
            printf("\n");
        }
    }

    if (count % 8 != 0) {
        printf("\n");
    }

    printf("\n共有%d个完全平方数\n", count);

    return 0;
}
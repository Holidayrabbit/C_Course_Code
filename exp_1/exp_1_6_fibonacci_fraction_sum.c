#include <stdio.h>

int main() {
    // 斐波那契数列的前n项
    int fib[17]; // 需要17个数，从0开始计数
    fib[0] = 1; // F(0) = 1
    fib[1] = 1; // F(1) = 1

    for (int i = 2; i <= 16; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("分数序列的前15项:\n");
    double sum = 0.0;

    for (int i = 1; i <= 15; i++) {
        double fraction = (double)fib[i+1] / fib[i];
        sum += fraction;
        printf("第%d项: %d/%d = %.6f\n", i, fib[i+1], fib[i], fraction);
    }

    printf("\n前15项之和为: %.6f\n", sum);

    return 0;
}
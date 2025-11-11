#include <stdio.h>

int main() {
    int sum = 0;

    printf("100之内的奇数有: ");
    for (int i = 1; i < 100; i += 2) {
        sum += i;
        printf("%d ", i);
    }

    printf("\n100之内奇数之和为: %d\n", sum);

    return 0;
}
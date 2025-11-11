#include <stdio.h>

int main() {
    double x, y;

    printf("请输入x的值: ");
    scanf("%lf", &x);

    if (x < 1) {
        y = x;
    } else if (x >= 1 && x < 10) {
        y = x + 5;
    } else { // x >= 10
        y = x - 5;
    }

    printf("当x = %.2f时, y = %.2f\n", x, y);

    return 0;
}
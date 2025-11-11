#include <stdio.h>
#include <math.h>

int main() {
    double side;

    printf("请输入等边三角形的边长: ");
    scanf("%lf", &side);

    // 等边三角形面积公式: (sqrt(3)/4) * a^2
    double area = (sqrt(3) / 4) * side * side;

    printf("等边三角形的面积为: %.2f\n", area);

    return 0;
}
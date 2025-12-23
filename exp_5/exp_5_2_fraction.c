/*
 * 实验5-2: 分数的加法和乘法
 * 定义分数结构体,实现分数的加法和乘法
 */

#include <stdio.h>

// 定义分数结构体
typedef struct {
    int numerator;    // 分子
    int denominator;  // 分母
} Fraction;

// 求最大公约数(用于化简分数)
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 化简分数
Fraction simplify(Fraction f) {
    if (f.denominator == 0) {
        printf("错误: 分母不能为0\n");
        f.numerator = 0;
        f.denominator = 1;
        return f;
    }

    int g = gcd(f.numerator, f.denominator);
    f.numerator /= g;
    f.denominator /= g;

    // 保证分母为正
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }

    return f;
}

// 分数加法: a/b + c/d = (a*d + b*c) / (b*d)
Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return simplify(result);
}

// 分数乘法: a/b * c/d = (a*c) / (b*d)
Fraction mul(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return simplify(result);
}

// 打印分数
void print_fraction(Fraction f) {
    if (f.denominator == 1) {
        printf("%d", f.numerator);
    } else if (f.numerator == 0) {
        printf("0");
    } else {
        printf("%d/%d", f.numerator, f.denominator);
    }
}

int main() {
    Fraction f1, f2, result;

    printf("分数计算程序\n");
    printf("================================\n\n");

    // 输入第一个分数
    printf("请输入第一个分数的分子和分母(用空格分隔): ");
    scanf("%d %d", &f1.numerator, &f1.denominator);

    // 输入第二个分数
    printf("请输入第二个分数的分子和分母(用空格分隔): ");
    scanf("%d %d", &f2.numerator, &f2.denominator);

    printf("\n");

    // 显示输入的分数
    printf("第一个分数: ");
    print_fraction(f1);
    printf("\n");

    printf("第二个分数: ");
    print_fraction(f2);
    printf("\n\n");

    // 计算加法
    result = add(f1, f2);
    printf("加法结果: ");
    print_fraction(f1);
    printf(" + ");
    print_fraction(f2);
    printf(" = ");
    print_fraction(result);
    printf("\n");

    // 计算乘法
    result = mul(f1, f2);
    printf("乘法结果: ");
    print_fraction(f1);
    printf(" * ");
    print_fraction(f2);
    printf(" = ");
    print_fraction(result);
    printf("\n");

    // 示例计算
    printf("\n示例计算:\n");
    Fraction ex1 = {2, 3};  // 2/3
    Fraction ex2 = {5, 6};  // 5/6

    printf("  2/3 + 5/6 = ");
    print_fraction(add(ex1, ex2));
    printf("\n");

    printf("  2/3 * 5/6 = ");
    print_fraction(mul(ex1, ex2));
    printf("\n");

    return 0;
}

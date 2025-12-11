#include <stdio.h>

int main() {
    char a = 'A';
    int x = 125;
    float p = 10.25;

    printf("变量 a 的值: %c, 地址: %p\n", a, (void*)&a);
    printf("变量 x 的值: %d, 地址: %p\n", x, (void*)&x);
    printf("变量 p 的值: %.2f, 地址: %p\n", p, (void*)&p);

    return 0;
}

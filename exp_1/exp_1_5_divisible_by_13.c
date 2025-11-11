#include <stdio.h>

int main() {
    printf("100之内能被13整除的数有: ");

    for (int i = 1; i < 100; i++) {
        if (i % 13 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
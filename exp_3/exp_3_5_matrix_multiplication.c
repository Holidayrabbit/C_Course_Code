#include <stdio.h>

#define N 3

// 矩阵乘法函数
void matrixMultiply(int (*a)[N], int (*b)[N], int (*result)[N]) {
    int i, j, k;
    int *pa, *pb, *presult;

    // 初始化结果矩阵为0
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            *(*(result + i) + j) = 0;
        }
    }

    // 矩阵相乘
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                *(*(result + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
            }
        }
    }
}

// 打印矩阵函数
void printMatrix(int (*matrix)[N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int A[N][N];
    int B[N][N];
    int i, j;

    printf("请输入3*3矩阵A的元素:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n矩阵A:\n");
    printMatrix(A);

    // 计算B = A * A
    matrixMultiply(A, A, B);

    printf("\n矩阵B = A * A:\n");
    printMatrix(B);

    return 0;
}


/*
`int (*a)[N]` 的含义

这是 C 语言的优先级问题：

* `*a` 表示 a 是一个指针
* `(*a)[N]` 表示 *a 是一个长度为 N 的数组
* `int (*a)[N]` 表示该数组的元素类型是 int

所以：

```
a 是一个指向「含 N 个 int 的数组」的指针
```

也就是指向一行的指针。

对于 N=3，就是：

```
a 的类型是：int (*)[3]
```

符合二维数组的真实结构。

---

为什么二维数组必须写成这种形式？

因为 C 编译器需要知道“每一行的长度”，否则无法做正确寻址：

```
*(a + i)  ← 跳 i 行时，编译器必须知道每行占多少字节
```

如果写成 `int **a`：

* 编译器不知道一行有几个元素
* 没法计算下一行的位置
* 因此不能正确访问二维数组

**`int (*a)[N]` 是二维数组退化后的正确类型，因为二维数组是“数组的数组”，而不是指针的指针。**


*/
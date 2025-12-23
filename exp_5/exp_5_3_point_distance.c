/*
 * 实验5-3: 坐标点距离计算
 * 计算两点之间的直线距离和曼哈顿距离
 */

#include <stdio.h>
#include <math.h>

// 定义坐标点结构体
typedef struct {
    int x;
    int y;
} Point;

// 计算两点之间的欧几里得距离(直线距离)
// 公式: sqrt((x2-x1)^2 + (y2-y1)^2)
float distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// 计算两点之间的曼哈顿距离
// 公式: |x2-x1| + |y2-y1|
float manhattan_distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    if (dx < 0) dx = -dx;  // 取绝对值
    if (dy < 0) dy = -dy;  // 取绝对值
    return dx + dy;
}

// 打印点的坐标
void print_point(Point p) {
    printf("(%d, %d)", p.x, p.y);
}

int main() {
    Point p1, p2;

    printf("坐标点距离计算程序\n");
    printf("================================\n\n");

    // 输入第一个点
    printf("请输入第一个点的坐标 (x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    // 输入第二个点
    printf("请输入第二个点的坐标 (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    printf("\n");

    // 显示输入的点
    printf("点1: ");
    print_point(p1);
    printf("\n");

    printf("点2: ");
    print_point(p2);
    printf("\n\n");

    // 计算并显示距离
    float euclidean_dist = distance(p1, p2);
    float manhattan_dist = manhattan_distance(p1, p2);

    printf("欧几里得距离(直线距离): %.2f\n", euclidean_dist);
    printf("曼哈顿距离: %.2f\n\n", manhattan_dist);

    // 示例计算
    printf("示例计算:\n");
    printf("--------------------------------\n");
    Point ex1 = {0, 0};
    Point ex2 = {3, 4};

    printf("点 (0,0) 到 (3,4):\n");
    printf("  欧几里得距离: %.2f\n", distance(ex1, ex2));
    printf("  曼哈顿距离: %.2f\n\n", manhattan_distance(ex1, ex2));

    Point ex3 = {1, 2};
    Point ex4 = {4, 6};

    printf("点 (1,2) 到 (4,6):\n");
    printf("  欧几里得距离: %.2f\n", distance(ex3, ex4));
    printf("  曼哈顿距离: %.2f\n", manhattan_distance(ex3, ex4));

    return 0;
}

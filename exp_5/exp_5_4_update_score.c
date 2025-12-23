/*
 * 实验5-4: 学生信息更新
 * 更新指定学号学生的分数信息
 */

#include <stdio.h>
#include <string.h>

#define STUDENT_COUNT 6

// 定义学生结构体
typedef struct {
    int id;            // 学号(个位数)
    char name[50];     // 姓名
    int score;         // 分数
} Student;

// 更新学生分数
// 返回值: 1表示更新成功, -1表示查找失败
int update_score(Student *p, int id, int score) {
    for (int i = 0; i < STUDENT_COUNT; i++) {
        if (p[i].id == id) {
            p[i].score = score;
            return 1;  // 更新成功
        }
    }
    return -1;  // 查找失败
}

// 打印所有学生信息
void print_students(Student students[], int count) {
    printf("\n学号\t姓名\t\t分数\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%d\n", students[i].id, students[i].name, students[i].score);
    }
    printf("\n");
}

int main() {
    // 初始化6个学生的信息
    Student students[STUDENT_COUNT] = {
        {1, "Alice", 85},
        {2, "Bob", 90},
        {3, "Charlie", 78},
        {4, "David", 92},
        {5, "Emma", 88},
        {6, "Frank", 76}
    };

    printf("学生成绩管理系统\n");
    printf("================================\n");

    // 显示初始学生信息
    printf("\n初始学生信息:");
    print_students(students, STUDENT_COUNT);

    // 输入要更新的学号和分数
    int id, new_score;
    printf("请输入要更新成绩的学号(1-6): ");
    scanf("%d", &id);

    printf("请输入新的分数: ");
    scanf("%d", &new_score);

    // 调用更新函数
    int result = update_score(students, id, new_score);

    if (result == 1) {
        printf("\n更新成功!\n");
        printf("学号 %d 的分数已更新为 %d\n", id, new_score);
    } else {
        printf("\n更新失败!\n");
        printf("未找到学号为 %d 的学生\n", id);
    }

    // 显示更新后的学生信息
    printf("\n更新后的学生信息:");
    print_students(students, STUDENT_COUNT);

    // 测试查找失败的情况
    printf("测试: 尝试更新不存在的学号(如9)\n");
    result = update_score(students, 9, 100);
    if (result == -1) {
        printf("返回值: -1 (查找失败,如预期)\n");
    }

    return 0;
}

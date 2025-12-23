/*
 * 实验5-5: 学生信息排序
 * 按照学号对学生进行排序
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

// 按学号排序(冒泡排序)
void sort_by_student_id(Student s[6]) {
    for (int i = 0; i < STUDENT_COUNT - 1; i++) {
        for (int j = 0; j < STUDENT_COUNT - 1 - i; j++) {
            if (s[j].id > s[j + 1].id) {
                // 交换两个学生
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
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
    // 初始化6个学生的信息(学号未排序)
    Student students[STUDENT_COUNT] = {
        {5, "Emma", 88},
        {2, "Bob", 90},
        {6, "Frank", 76},
        {1, "Alice", 85},
        {4, "David", 92},
        {3, "Charlie", 78}
    };

    printf("学生信息排序程序\n");
    printf("================================\n");

    // 显示排序前的学生信息
    printf("\n排序前的学生信息:");
    print_students(students, STUDENT_COUNT);

    // 按学号排序
    printf("正在按学号排序...\n");
    sort_by_student_id(students);

    // 显示排序后的学生信息
    printf("\n排序后的学生信息:");
    print_students(students, STUDENT_COUNT);

    printf("排序完成! 学生已按学号从小到大排列。\n");

    return 0;
}

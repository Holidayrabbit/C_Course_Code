/*
 * 实验5-6: 嵌套结构体
 * 学生信息包含笔记本电脑信息(对象里面包含另一个对象)
 */

#include <stdio.h>
#include <string.h>

// 定义笔记本电脑结构体
typedef struct {
    char model[50];   // 型号
    char color[30];   // 颜色
    float price;      // 价格
} Laptop;

// 定义学生结构体(包含Laptop对象)
typedef struct {
    int id;           // 学号
    char name[50];    // 姓名
    Laptop laptop;    // 笔记本电脑(嵌套结构体)
} Student;

// 输入学生信息
void input_student(Student *s) {
    printf("请输入学号: ");
    scanf("%d", &s->id);
    getchar();  // 清除输入缓冲区的换行符

    printf("请输入姓名: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;  // 去掉换行符

    printf("请输入笔记本型号: ");
    fgets(s->laptop.model, sizeof(s->laptop.model), stdin);
    s->laptop.model[strcspn(s->laptop.model, "\n")] = 0;

    printf("请输入笔记本颜色: ");
    fgets(s->laptop.color, sizeof(s->laptop.color), stdin);
    s->laptop.color[strcspn(s->laptop.color, "\n")] = 0;

    printf("请输入笔记本价格: ");
    scanf("%f", &s->laptop.price);
    getchar();  // 清除输入缓冲区的换行符
}

// 打印学生信息
void print_student(Student s) {
    printf("\n学号: %d\n", s.id);
    printf("姓名: %s\n", s.name);
    printf("笔记本信息:\n");
    printf("  型号: %s\n", s.laptop.model);
    printf("  颜色: %s\n", s.laptop.color);
    printf("  价格: %.2f 元\n", s.laptop.price);
}

// 打印所有学生信息
void print_all_students(Student students[], int count) {
    printf("\n================================\n");
    printf("所有学生信息汇总\n");
    printf("================================\n");
    for (int i = 0; i < count; i++) {
        printf("\n[学生 %d]", i + 1);
        print_student(students[i]);
        printf("--------------------------------");
    }
    printf("\n");
}

int main() {
    Student students[3];

    printf("学生和笔记本信息录入系统\n");
    printf("================================\n");
    printf("请输入3个学生的信息\n\n");

    // 输入3个学生的信息
    for (int i = 0; i < 3; i++) {
        printf(">>> 输入第 %d 个学生的信息 <<<\n", i + 1);
        printf("--------------------------------\n");
        input_student(&students[i]);
        printf("\n");
    }

    // 显示所有学生信息
    print_all_students(students, 3);

    // 统计信息
    printf("\n统计信息:\n");
    printf("--------------------------------\n");
    float total_price = 0;
    float max_price = students[0].laptop.price;
    float min_price = students[0].laptop.price;
    int max_idx = 0, min_idx = 0;

    for (int i = 0; i < 3; i++) {
        total_price += students[i].laptop.price;
        if (students[i].laptop.price > max_price) {
            max_price = students[i].laptop.price;
            max_idx = i;
        }
        if (students[i].laptop.price < min_price) {
            min_price = students[i].laptop.price;
            min_idx = i;
        }
    }

    printf("笔记本平均价格: %.2f 元\n", total_price / 3);
    printf("最贵的笔记本: %s 的 %s (%.2f 元)\n",
           students[max_idx].name, students[max_idx].laptop.model, max_price);
    printf("最便宜的笔记本: %s 的 %s (%.2f 元)\n",
           students[min_idx].name, students[min_idx].laptop.model, min_price);

    return 0;
}

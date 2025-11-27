#include <stdio.h>

int main() {
    int votes[5] = {0};  // 5名候选人的得票数，初始化为0
    int vote;

    printf("协会换届选举投票系统\n");
    printf("候选人代号：1, 2, 3, 4, 5\n");
    printf("请输入每张选票上的候选人代号（输入-1结束）：\n");

    while (1) {
        scanf("%d", &vote);

        if (vote == -1) {
            break;
        }

        if (vote >= 1 && vote <= 5) {
            votes[vote - 1]++;
        } else {
            printf("无效的候选人代号，请输入1-5之间的数字\n");
        }
    }

    printf("\n投票统计结果：\n");
    for (int i = 0; i < 5; i++) {
        printf("候选人%d：%d票\n", i + 1, votes[i]);
    }

    return 0;
}

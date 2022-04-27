#include <stdio.h>
#include <string.h>

int countHistory = 0;
char history[100][12];

// 檢查是否已在歷史中
bool checkHis(char *input) {
    for (int i = 0; i < countHistory; i++) {
        if (!(strncmp(history[i], input, 12)))
            return 1;
    }
    return 0;
}

// 評斷是否有目標字且之前未曾出現 回傳是否有誤
bool judge(int *countError, char *input, char *target) {
    bool chechHistory = checkHis(input);
    if (chechHistory != 1) {
        for (int i = 0; i <= 9; i += 3) {
            if (!(strncmp(target, &input[i], 3))) {
                strncpy(history[countHistory++], input, 12);
                return 0;
            }
        }
        *countError = *countError + 1;
        return 1;
    }
    printf("Input proverb already in the history!\n");
    *countError = *countError + 1;
    return 1;
}

// 計算中文字串長度
int Len(char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    bool game[4] = {0};
    int countError[4] = {0}, countGame = 4;
    int inputLen = 12, targetLen = 3;
    char input[100] = {0}, target[100] = {0};

    // 輸入目標字
    printf("Input the target word:");
    do {
        if (targetLen != 3) {
            printf("Target length error, Input it again!\n");
        }
        scanf("%s", target);
    } while ((targetLen = strlen(target)) != 3);
//    Len(target))
    printf("your target word is %s\n", target);

    //輪流輸入
    while (countGame != 1) {
        for (int i = 0; i < 4; i++) {
            if (game[i] == 1)
                continue;
            else {
                do {
                    if (inputLen != 12) {
                        printf("String length error, Input it again!\n");
                    }
                    printf("Player%d:", i);
                    scanf("%s", input);
                } while ((inputLen = Len(input)) != 12);

                if (judge(&countError[i], input, target)) {
                    printf("Player%d wrong answer! remain %d chance\n", i, 2 - countError[i]);
                } else {
                    printf("Player%d correct answer.\n", i);
                }
            }
            if (countError[i] == 2) {
                game[i] = 1;
                countGame--;
                printf("Player%d Lose!\n", i);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (game[i] == 0)
            printf("Winner is Player%d", i);
    }
}
/*
 江你哇啦
 你江哇勒
 哇你江勒
 哇你勒江
 哇你媽的
*/
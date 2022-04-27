#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], int *MaxComNum, int *MaxProgNum, int *MaxComScore, int *MaxProgScore) {
    *MaxProgScore = program[0];
    *MaxComScore = computer[0];
    for (int i = 1; i < 99; i++) {
        if (computer[i] > *MaxComScore) {
            *MaxComScore = computer[i];
        }
        if (program[i] > *MaxProgScore) {
            *MaxProgScore = program[i];
        }

    }
    for (int i = 0; i < 100; i++) {
        if (computer[i] == *MaxComScore) {
            MaxComIndex[i] = 1;
        }
        if (program[i] == *MaxProgScore) {
            MaxProgIndex[i] = 1;
        }
    }
}

void getAverage(int computer[], int program[], float average[], int count[]) {
    for (int i = 0; i < 100; i++) {
        average[i] = (computer[i] + (float) program[i]) / 2;
        if (average[i] < 60) {
            printf("Index: %3d | average %.2f\n", i, average[i]);
        }
        if (average[i] < 10)
            count[0]++;
        if (average[i] >= 10 && average[i] < 20)
            count[1]++;
        if (average[i] >= 20 && average[i] < 30)
            count[2]++;
        if (average[i] >= 30 && average[i] < 40)
            count[3]++;
        if (average[i] >= 40 && average[i] < 50)
            count[4]++;
        if (average[i] >= 50 && average[i] < 60)
            count[5]++;
        if (average[i] >= 60 && average[i] < 70)
            count[6]++;
        if (average[i] >= 70 && average[i] < 80)
            count[7]++;
        if (average[i] >= 80 && average[i] < 90)
            count[8]++;
        if (average[i] >= 90 && average[i] < 100)
            count[9]++;
        if (average[i] == 100)
            count[10]++;
    }
}

void getHistogram(int count[], float average[], int computer[], int program[]) {
    if (count[0] == 0 && count[1] == 0 && count[2] == 0 && count[4] == 0) {
        for (int i = 0; i < 100; i++) {
            average[i] = (computer[i] + (float) program[i]) / 2;
            if (average[i] < 10)
                count[0]++;
            if (average[i] >= 10 && average[i] < 20)
                count[1]++;
            if (average[i] >= 20 && average[i] < 30)
                count[2]++;
            if (average[i] >= 30 && average[i] < 40)
                count[3]++;
            if (average[i] >= 40 && average[i] < 50)
                count[4]++;
            if (average[i] >= 50 && average[i] < 60)
                count[5]++;
            if (average[i] >= 60 && average[i] < 70)
                count[6]++;
            if (average[i] >= 70 && average[i] < 80)
                count[7]++;
            if (average[i] >= 80 && average[i] < 90)
                count[8]++;
            if (average[i] >= 90 && average[i] < 100)
                count[9]++;
            if (average[i] == 100)
                count[10]++;
        }
    }
    printf("00~09: "); // 加空白出事
    for (int i = 0; i < count[0]; i++) {
        printf("*");
    }
    printf("\n10~19: ");
    for (int i = 0; i < count[1]; i++) {
        printf("*");
    }
    printf("\n20~29: ");
    for (int i = 0; i < count[2]; i++) {
        printf("*");
    }
    printf("\n30~39: ");
    for (int i = 0; i < count[3]; i++) {
        printf("*");
    }
    printf("\n40~49: ");
    for (int i = 0; i < count[4]; i++) {
        printf("*");
    }
    printf("\n50~59: ");
    for (int i = 0; i < count[5]; i++) {
        printf("*");
    }
    printf("\n60~69: ");
    for (int i = 0; i < count[6]; i++) {
        printf("*");
    }
    printf("\n70~79: ");
    for (int i = 0; i < count[7]; i++) {
        printf("*");
    }
    printf("\n80~89: ");
    for (int i = 0; i < count[8]; i++) {
        printf("*");
    }
    printf("\n90~99: ");
    for (int i = 0; i < count[9]; i++) {
        printf("*");
    }
    printf("\n100: ");
    for (int i = 0; i < count[10]; i++) {
        printf("*");
    }
    printf("\n");
}


int main() {
    srand(time(NULL));
    int computer[100], program[100], MaxComIndex[100] = {0}, MaxProgIndex[100] = {0}, count[11] = {0}, *MaxComScore = new int, *MaxProgScore = new int, *MaxComNum = new int, *MaxProgNum = new int;
    int func = 1;
    float average[100];
    for (int i = 0; i < 100; i++) {
        computer[i] = rand() % 100 + 1;
        program[i] = rand() % 100 + 1;
    }
    while (func != 5) {
        do {
            if (func != 1 && func != 2 && func != 3 && func != 4 && func != 5) {
                printf("------------------------------------\nInput error Error,Please cjoose again!\n");
            }
            printf("-----------------------------------------------\nChoose which function you want to do:\n(1)List all Score of student\n(2)Get Max Score student\n(3)get average lower than 60\n(4)get the Histogram\n(5)exit : ");
            scanf("%d", &func);

        } while (func != 1 && func != 2 && func != 3 && func != 4 && func != 5);
        switch (func) {
            case 1:
                for (int i = 0; i < 100; i++) {
                    printf("%d | computer: %3d program: %3d\n", i + 11000001,
                           computer[i], program[i]);
                }
                break;
            case 2:
                MaxScore(computer, program, MaxComIndex, MaxProgIndex, MaxComNum, MaxProgNum, MaxComScore, MaxProgScore);
                printf("computer: ");
                for (int i = 0; i < 100; i++) {
                    if (MaxComIndex[i] == 1)
                        printf("Index: %3d | Score: %3d | ", i + 11000001, computer[i]);
                }
                printf("\nprogram: ");
                for (int i = 0; i < 100; i++) {
                    if (MaxProgIndex[i] == 1)
                        printf("Index: %3d | Score: %3d | ", i + 11000001, program[i]);
                }
                printf("\n");
                break;
            case 3:
                for (int i = 0; i < 11; i++) {
                    count[i] = 0;
                }
                getAverage(computer, program, average, count);
                break;
            case 4:
                getHistogram(count, average, computer, program);
                break;
        }
    }
}
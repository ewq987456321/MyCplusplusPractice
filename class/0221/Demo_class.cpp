#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], int *MaxComNum, int *MaxProgNum, int *MaxComScore, int *MaxProgScore) {
    for (int i = 0; i < 100; i++) {
        if (computer[i] > *MaxComScore) {
            *MaxComScore = computer[i];
        }
        if (program[i] > *MaxProgScore) {
            *MaxProgScore = program[i];
        }
    }
    for (int i = 0; i < 100; i++) {
        if (program[i] == *MaxProgScore) {
            MaxProgIndex[i] = 1;
        }
        if (computer[i] == *MaxComScore) {
            MaxComIndex[i] = 1;
        }
    }
}

void getAverage(int computer[], int program[], int count[], float average[]) {
    for (int i = 0; i < 100; i++) {
        average[i] = (computer[i] + (float) program[i]) / 2;
        if (average[i] < 60) {
            printf("Index: %d Score: %.2f\n", i + 11000001, average[i]);
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

void getHistogram(int computer[], int program[], int count[], float average[]) {
    if (count[2] == 0 && count[4] == 0 && count[5] == 0) {
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
    printf("0~9: ");
    for (int i = 0; i < count[0]; i++) {
        printf("*");
    }
    printf("\n10~29: ");

    for (int i = 0; i < count[1]; i++) {
        printf("*");
    }
    printf("\n20~29: ");

    for (int i = 0; i < count[2]; i++) {
        printf("*");
    }
    printf("\n30~29: ");

    for (int i = 0; i < count[3]; i++) {
        printf("*");
    }
    printf("\n40~29: ");

    for (int i = 0; i < count[4]; i++) {
        printf("*");
    }
    printf("\n50~29: ");

    for (int i = 0; i < count[5]; i++) {
        printf("*");
    }
    printf("\n60~29: ");

    for (int i = 0; i < count[6]; i++) {
        printf("*");
    }
    printf("\n70~29: ");

    for (int i = 0; i < count[7]; i++) {
        printf("*");
    }
    printf("\n80~29: ");

    for (int i = 0; i < count[8]; i++) {
        printf("*");
    }
    printf("\n90~29: ");

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
                printf("Input error!\nPlease choose again\n");
            }
            printf("choose which function you want to do \n(1)list all Score\n(2)get Max Score students\n(3)get average students\n(4) get Histogram\n(5)exit : ");
            scanf("%d", &func);
        } while (func != 1 && func != 2 && func != 3 && func != 4 && func != 5);
        switch (func) {
            case 1:
                for (int i = 0; i < 100; i++) {
                    printf("Index: %d  computer Score: %3d | program Score: %3d\n", i + 11000001, computer[i], program[i]);
                }
                break;
            case 2:
                MaxScore(computer, program, MaxComIndex, MaxProgIndex, MaxComNum, MaxProgNum, MaxComScore, MaxProgScore);
                printf("Program:\n");
                for (int i = 0; i < 100; i++) {
                    if (MaxProgIndex[i] == 1) {
                        printf(" Index: %d | Score: %3d", i + 11000001, program[i]);
                    }
                }
                printf("\ncomputer\n");
                for (int i = 0; i < 100; i++) {
                    if (MaxComIndex[i] == 1) {
                        printf(" Index: %d | Score: %3d", i + 11000001, computer[i]);
                    }
                }
                printf("\n");
                break;
            case 3:
                getAverage(computer, program, count, average);
                break;
            case 4:
                getHistogram(computer, program, count, average);
                break;;
        }
    }
}
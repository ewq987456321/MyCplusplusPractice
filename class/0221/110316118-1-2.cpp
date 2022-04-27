#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], int *MaxComNum, int *MaxProgNum, int *MaxComScore, int *MaxProgScore) {
    *MaxComScore = computer[0];
    *MaxProgScore = program[0];
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
            *MaxComNum = *MaxComNum + 1;
            MaxComIndex[i] = 1;
        }
        if (program[i] == *MaxProgScore) {
            *MaxProgNum = *MaxProgNum + 1;
            MaxProgIndex[i] = 1;
        }
    }
}

void getAverage(int computer[], int program[], float average[], int *count1, int *count2, int *count3, int *count4, int *count5, int *count6, int *count7, int *count8, int *count9, int *count10,
                int *count11) {
    for (int i = 0; i < 100; i++) {
        average[i] = ((float) computer[i] + (float) program[i]) / 2;
        if (average[i] < 60) {
            printf("Index:%d Score:%.2f\n", i, average[i]);
        }
        if (average[i] < 10) {
            *count1 = *count1 + 1;
        } else if (average[i] >= 10 && average[i] < 20) {
            *count2 = *count2 + 1;
        } else if (average[i] >= 20 && average[i] < 30) {
            *count3 = *count3 + 1;
        } else if (average[i] >= 30 && average[i] < 40) {
            *count4 = *count4 + 1;
        } else if (average[i] >= 40 && average[i] < 50) {
            *count5 = *count5 + 1;
        } else if (average[i] >= 50 && average[i] < 60) {
            *count6 = *count6 + 1;
        } else if (average[i] >= 60 && average[i] < 70) {
            *count7 = *count7 + 1;
        } else if (average[i] >= 70 && average[i] < 80) {
            *count8 = *count8 + 1;
        } else if (average[i] >= 80 && average[i] < 90) {
            *count9 = *count9 + 1;
        } else if (average[i] >= 90 && average[i] < 100) {
            *count10 = *count10 + 1;
        } else if (average[i] == 100) {
            *count11 = *count11 + 1;
        }
    }
}

void histogram(int *count1, int *count2, int *count3, int *count4, int *count5, int *count6, int *count7, int *count8, int *count9, int *count10, int *count11) {
    printf("0~9: ");
    for (int i = 0; i < *count1; i++) {
        printf("*");
    }
    printf("\n10~19:");
    for (int i = 0; i < *count2; i++) {
        printf("*");
    }
    printf("\n20~29:");
    for (int i = 0; i < *count3; i++) {
        printf("*");
    }
    printf("\n30~39:");
    for (int i = 0; i < *count4; i++) {
        printf("*");
    }
    printf("\n40~49:");
    for (int i = 0; i < *count5; i++) {
        printf("*");
    }
    printf("\n50~59:");
    for (int i = 0; i < *count6; i++) {
        printf("*");
    }
    printf("\n60~69:");
    for (int i = 0; i < *count7; i++) {
        printf("*");
    }
    printf("\n70~79:");
    for (int i = 0; i < *count8; i++) {
        printf("*");
    }
    printf("\n80~89:");
    for (int i = 0; i < *count9; i++) {
        printf("*");
    }
    printf("\n90~99:");
    for (int i = 0; i < *count10; i++) {
        printf("*");
    }
    printf("\n100:");
    for (int i = 0; i < *count11; i++) {
        printf("*");
    }
}


int main() {
    srand(time(NULL));
    int computer[100], program[100], MaxComIndex[100] = {0}, MaxProgIndex[100] = {0}, *MaxComNum = new int, *MaxProgNum = new int, *MaxComScore = new int, *MaxProgScore = new int;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0, count10 = 0, count11 = 0;
    int func = 1;
    float average[100];
    *MaxComNum = 0;
    *MaxProgNum = 0;
    *MaxComScore =0;
    *MaxProgScore = 0;
    while(func!=5) {
        do {
            if (func != 1 && func != 2 && func != 3 && func != 4) {
                printf("input error! Please input it again.\n");
            }
            printf("Please cchoose a function: list all score(1),get max student(2),get average(3),get the histogram(4),exit(5): ");
            scanf("%d", &func);
        } while (func != 1 && func != 2 && func != 3 && func != 4 && func != 5);
        switch (func) {
            case 1:
                for (int i = 0; i < 100; i++) {
                    computer[i] = rand() % 100 + 1;
                    program[i] = rand() % 100 + 1;
                    printf("%d|%3d %3d\n", i + 11000000, computer[i], program[i]);
                }
                break;
            case 2:
                MaxScore(computer, program, MaxComIndex, MaxProgIndex, MaxComNum, MaxProgNum, MaxComScore, MaxProgScore);
                printf("computer biggest student: ");
                for (int i = 0; i < 100; i++) {
                    if (MaxComIndex[i] == 1) {
                        printf("%d %2d | ", i + 11000000, computer[i]);
                    }
                }
                printf("\nprogram biggest student: ");
                for (int i = 0; i < 100; i++) {
                    if (MaxProgIndex[i] == 1) {
                        printf("%d %2d | ", i + 11000000, program[i]);
                    }
                }
                printf("\n");
                break;
            case 3:
                getAverage(computer, program, average, &count1, &count2, &count3, &count4, &count5, &count6, &count7, &count8, &count9, &count10, &count11);
                break;
            case 4:
                histogram(&count1, &count2, &count3, &count4, &count5, &count6, &count7, &count8, &count9, &count10, &count11);
                break;
        }
    }
    return 0;
}
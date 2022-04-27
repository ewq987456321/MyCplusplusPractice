#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void insert(FILE *pFile) {
    char str[1000] = {0};
    printf("請輸入欲新增格言");
    scanf("%s", str);
    fprintf(pFile, "\n%s", str);
    fclose(pFile);
}

void print_all(FILE *pFile) {
    char str[1000];
    int check_en = 0;
    fscanf(pFile, "%s", str);
    while (!(feof(pFile))) {
        if (isalpha(str[0])) {
            if (check_en == 0)
                printf("\n");
            check_en = 1;
            printf("%s ", str);
        } else
            printf("\n%s", str);
        fscanf(pFile, "%s", str);
    }
    if (isalpha(str[0])) {
        check_en = 1;
        printf("%s ", str);
    } else
        printf("\n%s", str);
    fscanf(pFile, "%s", str);
    fclose(pFile);
}

int count_data(FILE *pFile) {
    int count = 0, chech_en = 0;
    char str[1000];
    while (!(feof(pFile))) {
        fscanf(pFile, "%s", str);
//        count++;
        if (isalpha(str[0])) {
            if (chech_en == 1) {
                continue;
            } else {
                chech_en = 1;
                count++;
            }
        }
        else{
            count++;
        }
    }
    fclose(pFile);
    return count;
}

void rand_aphorism(FILE *pFile, int i) {
    rewind(pFile);
    char str1[1000];
    for (int j = 0; j < i; j++) {
        fscanf(pFile, "%s", str1);
    }
    char str2[1000];
    fscanf(pFile, "%s", str2);
    while (isalpha(str2[0])) {
        strcat(str1, " ");
        strcat(str1, str2);
        fscanf(pFile, "%s", str2);
    }
    printf("%s\n", str1);
    fclose(pFile);
}

int main() {
    int func = 1, count = 0, i = 0;
    FILE *fptr;

    do {
        printf("請輸入欲選功能 1)隨機顯示格言 2)顯次所有格言 3)新增格言 -1)結束：");
        scanf("%d", &func);
        switch (func) {
            case 1:
                srand(time(NULL));
                fptr = fopen("aphorism.txt", "r");
                count = count_data(fptr);
                fptr = fopen("aphorism.txt", "r");
                i = rand() % count + 1;
                rand_aphorism(fptr, i);
                break;
            case 2:
                fptr = fopen("aphorism.txt", "r");
                print_all(fptr);
                break;
            case 3:
                fptr = fopen("aphorism.txt", "a");
                insert(fptr);
                break;
            case -1:
                break;
            default:
                printf("輸入錯誤請重新輸入\n");
                break;

        }
    } while (func != -1);
    return 0;
}
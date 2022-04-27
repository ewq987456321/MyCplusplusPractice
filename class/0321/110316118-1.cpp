#include <stdio.h>
#include <string.h>
#include <ctype.h>

int FindIndex(int index[], int *IndexCount, char *str, char *target) {
    char *temp;
    scanf(" %[^\n]", target);
    temp = strstr(str, target);
    while (temp != NULL) {
        index[*IndexCount] = temp - str;
        *IndexCount = *IndexCount + 1;
        temp = strstr((temp + 1), target);
    }
    if (*IndexCount != 0) {
        printf("有找到自串 “%s”,index 是", target);
        for (int i = 0; i < *IndexCount; i++) {
            printf("%d ", index[i]);
        }
        printf("\n");
        return 1;
    } else {
        printf("未找到目標字串\n");
        return 0;
    }
}

void change(int index[], int *IndexCount, char *str, char *target) {
    int find_status;
    find_status = FindIndex(index, IndexCount, str, target);
    if (find_status) {
        char chWord[50];
        printf("請輸入要替換的字串：");
        scanf(" %[^\n]", chWord);
        for (int i = 0; i < *IndexCount; i++) {
            printf("找到字串“%s”,index是%d,是否要取代(y/n)", target, index[i]);
            char tochange;
            scanf(" %c", &tochange);
            if (tochange == 'y') {
                char hold[500];
                strcpy(hold, (str + index[i] + strlen(target)));
                for (int j = 0; chWord[j] != '\0'; j++) {
                    (str + index[i])[j] = chWord[j];
                }
                // printf("%s", str);
                int minus = strlen(chWord) - strlen(target);
                strcpy((str + index[i] + strlen(chWord)), hold);
                printf("替換後的字串%s\n", str);
                for (int j = i + 1; j < *IndexCount; j++) {
                    index[j] += minus;
                }
            } else
                printf("替換後字串：%s\n", str);
        }
    }
}

void strcut(char temp[1000]) {
    int allDigit[50], allUpper[50];
    int DigitLen = 0, UpperLen = 0, strLen = 0;
    char *str[50];
    char *address = strtok(temp, " (),!+=.");
    while (address != NULL) {
        int countDigit = 0, countUpper = 0;
        str[strLen] = address;
        for (int j = 0; str[strLen][j] != '\0'; j++) {
            if (isdigit(str[strLen][j]))
                countDigit++;
            if (isupper(str[strLen][j]))
                countUpper++;
        }
        if (countUpper == strlen(str[strLen]))
            allUpper[UpperLen++] = strLen;
        if (countDigit == strlen(str[strLen]))
            allDigit[DigitLen++] = strLen;
        strLen++;
        address = strtok(NULL, " (),!-+=.");
    }
    for (int i = 0; i < strLen; i++) {
        printf("%s\n", str[i]);
    }
    printf("全部數字：");
    for (int i = 0; i < DigitLen; i++) {
        printf("%s ", str[allDigit[i]]);
    }
    printf("\n全部大寫：");
    for (int i = 0; i < UpperLen; i++) {
        printf("%s ", str[allUpper[i]]);
    }
    printf("\n");
}

int main() {
    int func = 1;
    int find_index[50] = {0}, IndexCount = 0;
    char str[1000];
    char target[100];
    printf("糗輸入字串");
    scanf("%[^\n]", str);
    do {
        for (int i = 0; i < 50; i++) {
            find_index[i] = 0;
        }
        IndexCount = 0;
        printf("請選擇功能 (1 尋找子自串 (2 替代字串 (3 切割字串(-1 結束");
        scanf("%d", &func);
        switch (func) {
            case 1:
                printf("輸入你要搜尋的字串：");
                FindIndex(find_index, &IndexCount, str, target);
                break;
            case 2:
                printf("替換前字串：%s", str);
                printf("請輸入被替換字串；");
                change(find_index, &IndexCount, str, target);
                break;
            case 3:
                char temp[1000];
                strcpy(temp, str);
                strcut(temp);
                break;
            case -1:
                break;
            default:
                printf("輸入錯誤 , 請重新輸入！\n");
                break;
        }
    } while (func != -1);
    return 0;
}
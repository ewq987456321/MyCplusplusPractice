#include <stdio.h>
#include <string.h>
#include <ctype.h>

int FindIndex(int find_index[50], int *IndexCount, char str[1000], char target[100]) {
//    scanf(" %[^\n]", target);
    fgets(target,100,stdin);
    fgets(target,1000,stdin);
    target[strlen(target)-1] = '\0';
    char *temp = strstr(str, target);
    while (temp != NULL) {
        find_index[*IndexCount] = temp - str;
        *IndexCount = *IndexCount + 1;
        temp = strstr(temp + strlen(target), target);
    }
    if (*IndexCount) {
        printf("有找到字串“%s”,index是：,", target);
        for (int i = 0; i < *IndexCount; i++) {
            printf("%d ", find_index[i]);
        }
        printf("\n");
        return 1;
    } else {
        printf("未搜尋到目標字串\n");
        return 0;
    }
}

void change(int find_index[50], int *IndexCount, char str[1000], char target[100]) {
    int tochange = FindIndex(find_index, IndexCount, str, target);
    char toWord[100];
    char change;
    printf("輸入要替換的字串：");
    scanf(" %[^\n]", toWord);
    if (tochange) {
        for (int i = 0; i < *IndexCount; i++) {
            printf("找到字串“%s”, index是%d 是否取代(y/n):", target, find_index[i]);
            scanf(" %c", &change);
            if (change == 'y') {
                char hold[1000];
                strcpy(hold, (str + find_index[i] + strlen(target)));
                strncpy((str + find_index[i]), toWord, strlen(toWord));
                strcpy((str + find_index[i] + strlen(toWord)), hold);
                printf("替換後的字串：%s\n", str);
                for (int j = 0; j < *IndexCount; j++) {
                    find_index[j] += (strlen(toWord) - strlen(target));
                }
            } else {
                printf("替換後的字串：%s\n", str);
            }
        }
    }
}

void strcut(char temp[1000]) {
    int allDigit[50], allUpper[50];
    int DigitLen = 0, UpperLen = 0, strLen = 0;
    char *str[50];
    char *address = strtok(temp, " (),!+=.");
    while(address != NULL){
        int countDigit =0,countUpper =0;
        str[strLen] = address;
        for(int j=0;str[strLen][j] != '\0';j++){
            if(isdigit(str[strLen][j]))
                countDigit++;
            if(isupper(str[strLen][j]))
                countUpper++;
        }
        if(countDigit == strlen(str[strLen]))
            allDigit[DigitLen++] = strLen;
        if(countUpper == strlen(str[strLen]))
            allUpper[UpperLen++] = strLen;
        strLen += 1;
        address = strtok(NULL," (),!+=.");
    }
    for(int i =0;i<strLen;i++){
        printf("%s\n",str[i]);
    }
    printf("全部數字：");
    for(int i =0;i<DigitLen;i++){
        printf("%s ",str[allDigit[i]]);
    }
    printf("\n全部大寫：");
    for(int i =0;i<UpperLen;i++){
        printf("%s ",str[allUpper[i]]);
    }
}

int main() {
    int func = 1;
    int find_index[50] = {0}, IndexCount = 0;
    char target[100], str[1000];

    printf("Please input a string:");
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
                printf("請輸入被替換字串:\n");
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
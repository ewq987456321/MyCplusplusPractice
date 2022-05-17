#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LK {
    int num = 0;
    LK *nextPtr = NULL;
};

LK *addData(LK *head)
{
    LK *current = head;
    LK *add = (LK *)malloc(sizeof(LK));
    printf("請輸入要新增的整數: ");
    scanf("%d", &add->num);
    if (current == NULL) {
        current = add;
    }
    else {
        LK *temp = current;
        current = add;
        current->nextPtr = temp;
    }
    return current;
}

LK *delData(LK *head)
{
    LK *current = head;
    if (current == NULL) {
        printf("尚未新增任何資料!\n");
    }
    else {
        LK *temp = current->nextPtr;
        free(current);
        current = temp;
    }
    return current;
}

void printData(LK *head)
{
    LK *current = head;
    if (current != NULL) {
        while (current != NULL) {
            printf("%d ", current->num);
            current = current->nextPtr;
        }
    }
    else
        printf("尚未新增任何資料!\n");
    printf("\n");
}

void freeData(LK *head)
{
    LK *current = head;
    while (current->nextPtr != NULL) {
        LK *temp = current->nextPtr;
        free(current);
        current = temp;
    }
}

int main()
{
    LK *head = NULL;
    int func = 1;
    do {
        printf("請選擇 1)新增 2)刪除 3)印出 -1)結束: ");
        scanf("%d", &func);
        switch (func) {
        case 1:
            head = addData(head);
            break;
        case 2:
            head = delData(head);
            break;
        case 3:
            printData(head);
            break;
        case -1:
            freeData(head);
            break;
        default:
            printf("輸入錯誤請再輸一次!\n");
            break;
        }
    } while (func != -1);
    return 0;
}

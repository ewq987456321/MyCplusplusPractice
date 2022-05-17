#include <cstdlib>
#include <ctime>
#include <malloc/_malloc.h>
#include <stdio.h>
struct LK {
    int num = 0;
    LK *nextPtr = NULL;
};

int chooseInterval(LK **array, int num)
{
    int index;
    if (num < 10) {
        index = 0;
    }
    else if (num >= 10 && num < 20) {
        index = 1;
    }
    else if (num >= 20 && num < 30) {
        index = 2;
    }
    else if (num >= 30 && num < 40) {
        index = 3;
    }
    else if (num >= 40 && num < 50) {
        index = 4;
    }
    else if (num >= 50 && num < 60) {
        index = 5;
    }
    else if (num >= 60 && num < 70) {
        index = 6;
    }
    else if (num >= 70 && num < 80) {
        index = 7;
    }
    else if (num >= 80 && num < 90) {
        index = 8;
    }
    else if (num >= 90 && num < 100) {
        index = 9;
    }
    return index;
}
LK *addData(LK *current, int num)
{
    LK *add = (LK *)malloc(sizeof(LK));
    add->num = num;
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
void printData(LK **array)
{
    for (int i = 0; i < 10; i++) {
        LK *current = array[i];
        if (current != NULL) {
            while (current != NULL) {
                printf("%d ", current->num);
                current = current->nextPtr;
            }
            printf("\n");
        }
    }
}
void freeLK(LK **array)
{
    for (int i = 0; i < 10; i++) {
        LK *current = array[i];
        if (current != NULL) {
            free(current);
        }
    }
}
void searchData(LK **array)
{
    int num = 0;
    int searched = 0;
    do {
        if (num > 99 || num < 0) printf("輸入錯誤請重新輸入\n");
        printf("請輸入要搜尋的整數: ");
        scanf("%d", &num);
    } while (num > 99 || num < 0);
    int index = chooseInterval(array, num);
    LK *current = array[index];
    while (current != NULL) {
        if (current->num == num) {
            searched = 1;
            break;
        }
        current = current->nextPtr;
    }
    if (searched == 0) printf("未找到\n");
    if (searched == 1) printf("有找到%d\n", current->num);
}
int main()
{
    srand(time(NULL));
    int func = 1;
    int num = 0, index = 0;
    LK *array[10] = {0};
    // LK *current = NULL;
    for (int i = 0; i < 20; i++) {
        num = rand() % 100;
        index = chooseInterval(array, num);
        array[index] = addData(array[index], num);
    }
    printData(array);

    do {
        printf("請選擇1) 搜尋 2)新增 3)列印 -1)結束: ");
        scanf("%d", &func);
        switch (func) {
        case 1:
            searchData(array);
            break;
        case 2:
            do {
                if (num < 0 || num > 99) printf("輸入錯誤請再輸一次!\n");
                printf("請輸入要新增的整數: ");
                scanf("%d", &num);
            } while (num < 0 || num > 99);
            index = chooseInterval(array, num);
            array[index] = addData(array[index], num);
            break;
        case 3:
            printData(array);
            break;
        case -1:
            freeLK(array);
            break;
        default:
            printf("輸入錯誤請再輸一次!\n");
        }
    } while (func != -1);
}

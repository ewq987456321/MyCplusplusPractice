#include <cstdlib>
#include <ctime>
#include <stdio.h>
struct LK {
    int num = 0;
    LK *nextPtr = NULL;
};

int chooseInterval(LK **array, int num) {
    int index;
    if (num < 10) {
        index = 0;
    } else if (num >= 10 && num < 20) {
        index = 1;
    } else if (num >= 20 && num < 30) {
        index = 2;
    } else if (num >= 30 && num < 40) {
        index = 3;
    } else if (num >= 40 && num < 50) {
        index = 4;
    } else if (num >= 50 && num < 60) {
        index = 5;
    } else if (num >= 60 && num < 70) {
        index = 6;
    } else if (num >= 70 && num < 80) {
        index = 7;
    } else if (num >= 80 && num < 90) {
        index = 8;
    } else if (num >= 90 && num < 100) {
        index = 9;
    }
    return index;
}

LK *addData(LK *current, int num) {
    LK *start = current;
    LK *add = (LK *)malloc(sizeof(LK));
    LK *prev = NULL;
    add->num = num;
    if (current == NULL) {
        start = add;
    } else {
        while (current != NULL && current->num < num) {
            prev = current;
            current = current->nextPtr;
        }
        if (prev != NULL) {
            prev->nextPtr = add;
            add->nextPtr = current;
        } else {
            LK *temp = start;
            start = add;
            start->nextPtr = temp;
        }
    }

    /*
    else {
        LK *temp = current;
        current = add;
        current->nextPtr = temp;
    }
    */

    return start;
}
void printData(LK **array) {
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
void freeLK(LK **array) {
    for (int i = 0; i < 10; i++) {
        LK *current = array[i];
        if (current != NULL) {
            free(current);
        }
    }
}
void searchData(LK **array) {
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

LK *delData(LK *current, int num) {
    LK *search = current;
    LK *prev = NULL;
    if (current != NULL) {
        int searched = 0;
        while (search != NULL) {
            if (search->num == num) {
                searched = 1;
                break;
            }
            prev = search;
            search = search->nextPtr;
        }
        if (searched) {
            if (search == current) {
                current = current->nextPtr;
                free(search);
            } else {
                prev->nextPtr = search->nextPtr;
                free(search);
            }
        } else {
            printf("無輸入的目標!\n");
        }
    } else {
        printf("該列無任何資料\n");
    }
    return current;
}
int main() {
    srand(time(NULL));
    int func = 1, inArray = 0;
    int num = 0, index = 0;
    LK *array[10] = {0}, *temp;
    // LK *current = NULL;
    for (int i = 0; i < 20; i++) {
        do {
            inArray = 0;
            num = rand() % 100;
            index = chooseInterval(array, num);
            temp = array[index];
            while (temp != NULL) {
                if (temp->num == num) {
                    inArray = 1;
                    break;
                }
                temp = temp->nextPtr;
            }
        } while (inArray);
        array[index] = addData(array[index], num);
    }
    printData(array);
    do {
        printf("請選擇1) 搜尋 2)新增 3)列印 4)刪除 -1)結束: ");
        scanf("%d", &func);
        switch (func) {
        case 1:
            searchData(array);
            break;
        case 2:
            do {
                if (inArray) printf("輸入重複!\n");
                inArray = 0;
                do {
                    if (num < 0 || num > 99) printf("輸入錯誤請再輸一次!\n");
                    printf("請輸入要新增的整數: ");
                    scanf("%d", &num);
                } while (num < 0 || num > 99);
                index = chooseInterval(array, num);
                temp = array[index];
                while (temp != NULL) {
                    if (temp->num == num) {
                        inArray = 1;
                        break;
                    }
                    temp = temp->nextPtr;
                }
            } while (inArray);
            array[index] = addData(array[index], num);
            break;
        case 3:
            printData(array);
            break;
        case 4:
            do {
                if (num < 0 || num > 99) printf("輸入錯誤請再輸一次!\n");
                printf("請輸入要新增的整數: ");
                scanf("%d", &num);
            } while (num < 0 || num > 99);
            index = chooseInterval(array, num);
            array[index] = delData(array[index], num);
            break;
        case -1:
            freeLK(array);
            break;
        default:
            printf("輸入錯誤請再輸一次!\n");
        }
    } while (func != -1);
}

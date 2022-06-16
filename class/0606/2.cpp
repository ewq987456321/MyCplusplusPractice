#include <cstdio>
#include <cstdlib>

#include "2header.h"

int main() {
    int func;
    Queue *head = NULL;
    do {
        printf("請選擇 1)新增訂單 2)刪除訂單 3)列印訂單 -1)結束: ");
        scanf("%d", &func);
        switch (func) {
        case 1:
            add(&head);
            break;
        case 2:
            del(&head);
            break;
        case 3:
            print(head);
            break;
        case -1:
            freed(head);
            break;
        }
    } while (func != -1);
}


#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Queue {
    char ID[50] = "";
    int count = 0;
    char name[50] = "";
    Queue *next = NULL;
};

void add(Queue **head);
void del(Queue **head);
void freed(Queue *head);
void print(Queue *head);

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

void add(Queue **head) {
    Queue *current = *head, *prev = NULL;
    Queue *check = *head;
    Queue *add = (Queue *)malloc(sizeof(Queue));
    bool fined = false;
    while (current != NULL) {
        prev = current;
        current = current->next;
    }
    do {
        if (fined) printf("編號重複\n");
        fined = false;
        check = *head;
        printf("請輸入訂單編號: ");
        scanf(" %s", add->ID);
        while (check != NULL) {
            if (strcmp(check->ID, add->ID) == 0) {
                fined = true;
                break;
            }
            check = check->next;
        }
    } while (fined);
    printf("請輸入名稱: ");
    scanf(" %s", add->name);
    do {
        printf("請輸入數量: ");
        scanf(" %d", &add->count);
    } while (add->count <= 0);
    if (*head != NULL) {
        printf("123\n");
        add->next = NULL;
        prev->next = add;
    } else
        *head = add;
}

void del(Queue **head) {
    Queue *current = *head;
    if (current != NULL) {
        printf("訂單編號: %s\n", current->ID);
        printf("飲品名稱: %s\n", current->name);
        printf("數量: %d\n", current->count);
        *head = current->next;
        free(current);
    } else
        printf("無訂單\n");
}

void freed(Queue *head) {
    Queue *current = head;
    while (current != NULL) {
        Queue *temp = current;
        current = current->next;
        free(temp);
    }
}

void print(Queue *head) {
    Queue *current = head;
    while (current != NULL) {
        printf("訂單編號: %s\n", current->ID);
        printf("飲品名稱: %s\n", current->name);
        printf("數量: %d\n", current->count);
        printf("---------------------------\n");
        current = current->next;
    }
}

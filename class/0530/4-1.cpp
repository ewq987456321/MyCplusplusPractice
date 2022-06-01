#include <cstdio>
#include <cstdlib>
#include <iostream>

struct LL {
    int num = 0;
    LL *next = NULL;
};

void add(LL **head, int num) {
    LL *current = *head, *prev = NULL;
    LL *add = (LL *)malloc(sizeof(LL));
    add->num = num;
    while (current != NULL && current->num < num) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        add->next = current;
        *head = add;
    } else {
        prev->next = add;
        add->next = current;
    }
}
int main() {
    LL *head = NULL, *current;
    int temp;
    while (std::cin >> temp) {
        add(&head, temp);
    }
    current = head;
    while (current != NULL) {
        LL *del = current;
        printf("%d\n", current->num);
        current = current->next;
        free(del);
    }
    char nu = '\0';
    printf("%c", nu);
}

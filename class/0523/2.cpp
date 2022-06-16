#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <stdio.h>

struct word {
    char words[20] = "";
    int count = 0;
    word *nextPtr = NULL;
};

int main() {
    word *head = NULL, *current = head;
    char target[1000] = "";
    bool fined = false;
    printf("請輸入: ");
    scanf("%[^\n]", target);
    for (int i = 0; i < strlen(target); i++) {
        target[i] = tolower(target[i]);
    }
    char *temp = strtok(target, "\t \n");
    while (temp != NULL) {
        word *add = (word *)malloc(sizeof(word));
        fined = false;
        current = head;
        if (ispunct(*temp) != 0) temp += 1;
        if (ispunct(temp[strlen(temp) - 1]) != 0) temp[strlen(temp) - 1] = '\0';
        if (head != NULL) {
            while (current != NULL) {
                if (strcmp(current->words, temp) == 0) {
                    current->count += 1;
                    fined = true;
                    free(add);
                    break;
                }
                current = current->nextPtr;
            }
            if (!(fined)) {
                word *prev = NULL;
                current = head;
                strcpy(add->words, temp);
                add->count += 1;
                while (current != NULL && strcmp(current->words, add->words) < 0) {
                    prev = current;
                    current = current->nextPtr;
                }
                if (prev != NULL) {
                    prev->nextPtr = add;
                    add->nextPtr = current;
                } else {
                    add->nextPtr = current;
                    head = add;
                }
            }
        } else {
            strcpy(add->words, temp);
            add->count += 1;
            head = add;
        }
        temp = strtok(NULL, "\t \n");
    }
    current = head;
    while (current != NULL) {
        printf("%s %d\n", current->words, current->count);
        current = current->nextPtr;
    }
    current = head;
    while (current != NULL) {
        word *temp = current;
        current = current->nextPtr;
        free(temp);
    }
}

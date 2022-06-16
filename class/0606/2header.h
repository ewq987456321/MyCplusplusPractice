#ifndef HEADER_H
#define HEADER_H
#include <cstdlib>

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

#endif //

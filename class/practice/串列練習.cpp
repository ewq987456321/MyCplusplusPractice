// Created on iPad Jing.

#include <stdio.h>

struct old{
    int age;
    old *next = NULL;
};

void printAll(old *head,old *current){
    int counter = 0;
    current = head;
    printf("now print all age in the record\n");
    do{
        printf("%d: %d\n",counter,current->age);
        current = current->next;
        counter++;
    }
    while(current != NULL);
}

int main() {
    // init linked list.
    old *head = new old; // create first data.
    old *current = head; // record currnt data address.
    head->age = 12;
    head->next = NULL; // init address of next of first data.

    // record all data into linked list.
    for(int i=0;i<5;i++){
        current->next = new old; // let the next address of first data equal "new struct".
        current = current->next; // let current equal the next data.
        int age;
        printf("Please input a number: ");
        scanf(" %d",&age);
        current->age = age;
        current->next = NULL;
    }
    printAll(head,current);
    

    // change specific data.
    printf("please input which record you want to change.");
    int whichNum;
    scanf(" %d",&whichNum);
    current = head;
    for(int i=0;i<whichNum;i++){
        current = current->next;
    }
    printf("Please input the age: ");
    int age;
    scanf(" %d",&age);
    current->age = age;
    printAll(head,current);

    // delete specific record.
    printf("please input which record you want to delete: ");
    scanf(" %d",&whichNum);
    current = head;
    for(int i=0;i<whichNum-1;i++){
        current = current->next;
    }
    old *temp = current->next;
    current->next = temp->next;
    delete temp;
    printAll(head,current);
    return 0;
}
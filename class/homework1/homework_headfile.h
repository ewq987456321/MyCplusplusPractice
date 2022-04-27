//
// Created by Jing on 2022/4/8.
//

#ifndef HOMEWORK1_HOMEWORK_HEADFILE_H
#define HOMEWORK1_HOMEWORK_HEADFILE_H

#include "stdio.h"

int checkID(char *char_num);

int checkDAY(char *char_day);

FILE *open_file(char *filename, char *mode);

void insert_vaccine(FILE *fptr);

void insert_quarantineResult(FILE *fptr, char *ID);

void print_info(FILE *fptr);

void insert_positive(char *id, char date[50], char type[50], char place[50], char result[50]);

int print_positive_person_info(FILE *pFile);

int delete_positive(FILE *fptr, char code[20]);



#endif //HOMEWORK1_HOMEWORK_HEADFILE_H

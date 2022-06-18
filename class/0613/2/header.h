#ifndef HEADER_H
#define HEADER_H
#include <map>
#include <string>
using namespace std;

struct View_spot {
    string name = "";
    int township = -1;
    int type = -1;
    float longitude = 0;
    float latitude = 0;
};

int add(View_spot arr[], int length);
int del(View_spot arr[], int length);
void print(View_spot arr[], int length);
void print_township(View_spot arr[], int length);
void print_type(View_spot arr[], int length);
void sort_long(View_spot arr[], int length);
void sort_la(View_spot arr[], int length);
int find(View_spot arr[], string name, int length);

#endif

#include <stdio.h>

int main() {
    char *arr[8] = {"Pointer variables", "Array of pointers", "& is address operator", "Contain address of variable", "NULL points to nothing", "* indicates variable is a pointer",
                    "dereferencing operator", "Selection sort using pass-by-reference"};
    for (int i = 0; i < 8 - 1; i++) {
        int small = i;
        for (int j = i; j < 8; j++) {
            if (arr[j][0] < arr[small][0]) {
                small = j;
            }
        }
        char *temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
    int j=0;
    for(int i =0;i<8;i++){
        j=0;
        while(arr[i][j]!='\0'){
            printf("%c",arr[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}

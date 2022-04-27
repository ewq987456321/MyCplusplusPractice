#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int minus[],int index[], int smallIndex, int target) {
    int temp = index[smallIndex];
    index[smallIndex] = index[target];
    index[target] = temp;
    temp = minus[smallIndex];
    minus[smallIndex] = minus[target];
    minus[target] = temp;
}


int main() {
    srand(time(NULL));
    int answer = rand() % 10001;
    printf("answer:%d\n", answer);
    int guess[5]={0};
    int minus[5] = {0};
    int index[5];
    for (int i = 0; i < 5; i++) {
        index[i] = i;
        do{
            if(guess[i]<0 || guess[i]>10000){
                printf("input error\n");
            }
            scanf("%d", &guess[i]);
            minus[i] = abs(guess[i] - answer);
        }
        while(guess[i]<0||guess[i]>10000);

        printf("元：%d\n", minus[i]);
    }
    for (int i = 0; i < 5 - 1; i++) {
        int small = i;
        for (int j = i; j < 5; j++) {
            if (minus[j] < minus[small]) {
                small = j;
            }
        }
        swap(minus,index, i, small);
    }
    for (int i = 0; i <5; i++) {
        printf("排%d\n", minus[i]);
    }
    printf("差：%d玩：%d", minus[0], index[0]);
    return 0;
}

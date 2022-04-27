#include <stdio.h>
#include <string.h>


int main() {
    int num;
    int str[9];
    int str1;
    int sum[9] = {0};
    scanf("%d",&num);
    for (int i = 0; i < num ;i++) {
        scanf("%d", &str[i]);
        int str1= str[i];
        for (int j = 0; str1!= 0; j++) {
            sum[i] += str1%10;
            str1 /= 10;
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1; j++) {
            if (sum[j] > sum[j + 1]) {
                int temp = sum[j + 1];
                sum[j + 1] = sum[j];
                sum[j] = temp;
                temp = str[j+1];
                str[j+1] = str[j];
                str[j] = temp;


            }
            if (sum[j] == sum[j + 1]) {
                if (str[j] > str[j+1]) {
                    int temp = sum[j + 1];
                    sum[j + 1] = sum[j];
                    sum[j] = temp;
                    temp = str[j+1];
                    str[j+1] = str[j];
                    str[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < num; i++) {
        if (i != num - 1)
            printf("%d ", str[i]);
        else
            printf("%d", str[i]);
    }
    printf("\n");
}
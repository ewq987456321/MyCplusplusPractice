#include <stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    int count =0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if(count == 0){
        printf("YES\n");
    }
    else
        printf("NO\n");
}
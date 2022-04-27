#include <stdio.h>

int main() {
    int k = 0, count = 0;
    int a[30] = {0}, b[30] = {0};
    scanf("%d", &k);
    while (k != 0) {
        a[count++] = (k % 10);
        k /= 10;
    }
    for(int i =count,j=0;i>=0;i--,j++){
        b[j] = a[i];
    }
    for (int i = 0; i < count; i++) {
        if (!(a[i] == b[i+1])) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

}
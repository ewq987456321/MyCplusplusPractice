#include <stdio.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);
    for (int k = 0; k < num; k++) {
        int error = 0;
        char str[110] = {0}, str2[110] = {0};
        int count[26] = {0};
        scanf("%s", str);
        scanf("%s", str2);
        if (strlen(str) != strlen(str2)) {
            printf("0");
        } else {
            for (int i = 0; i < strlen(str); i++) {
                count[str[i] - 'a']++;
                count[str2[i] - 'a']--;
            }
            for (int i = 0; i < 26; i++) {
                if (count[i]!=0) {
                    printf("0");
                    error = 1;
                    break;
                }
            }
            if (!error)
                printf("1");
        }
        printf("\n");
    }
    return 0;
}


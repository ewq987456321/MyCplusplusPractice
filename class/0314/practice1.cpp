#include <stdio.h>
#include <ctype.h>

int strcheck(char *str, int *strcounter) {
    for (*strcounter = 0; str[*strcounter] != '\n'; *strcounter = *strcounter + 1) {
        if (isspace(str[*strcounter])) {
            return 2;
        }
        if (*strcounter+1 > 30) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int errorCode = 0, *strcounter = new int;
    char str[50] = {0}, strEncryption[50] = {0};
    do {
        if (errorCode) {
            switch (errorCode) {
                case 1:
                    printf("Length error!\n");
                    break;
                case 2:
                    printf("Space is not arrow!\n");
            }
        }
        fgets(str, 50, stdin);
    } while ((errorCode = strcheck(str, strcounter)));
    for (int i = 0, j = 0; i < *strcounter; i++, j++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] + 5 > 'z') {
                strEncryption[j] = str[i] + 5 - 26;
            } else {
                strEncryption[j] = str[i] + 5;
            }
            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] + 5 > 'Z') {
                strEncryption[j] = str[i] + 5 - 26;
            } else {
                strEncryption[j] = str[i] + 5;
            }
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            strEncryption[j] = str[i] - 15;
            continue;
        }
        if (ispunct(str[i])) {
            strEncryption[j] = '/';
            strEncryption[j + 1] = str[i];
            j += 1;
            continue;
        }
    }
    printf("%s", strEncryption);
    return 0;
}
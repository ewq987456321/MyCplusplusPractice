#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    int i = 0, j = 1, key = 1;
    char str[1000], *wptr[100], *tmp;

    gets(str);
    while (!feof(stdin)) {
        for (int i = 0; i < strlen(str); i++) {
            str[i] = tolower(str[i]);
        }

        if ((wptr[0] = (strtok(str, " "))) != NULL) {
            while (wptr[0][i] != '\0') {
                i++;
            }
            wptr[0][i] = '\0';
        }
        while ((wptr[j] = (strtok(NULL, " "))) != NULL) {
            for (int k = 0; k < j; k++) {
                if (strcmp(wptr[k], wptr[j]) == 0) {
                    key = 0;
                }
            }
            if (key == 1) {
                i = 0;
                while (wptr[j][i] != '\0') {
                    i++;
                }
                wptr[j][i] = '\0';
                j++;
            }
            key = 1;
        }
        for (int i = 0; i < j; i++) {
            printf("%s", wptr[i]);
            if (i == j - 1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
        gets(str);
    }

    return 0;
}

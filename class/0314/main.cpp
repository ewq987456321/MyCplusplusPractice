#include <stdio.h>
#include <ctype.h>

bool haveSpace(char *str, int *count) {
    *count = 0;
    bool ans = 0;
    for (int i = 0; str[i] != '\0'; i++, *count = *count + 1) {
        if (isspace(str[i]) && str[i] != '\n')
            ans = 1;
        if (str[i] == '\n')
            *count = *count - 1;
    }
    if (*count >= 30)
        ans = 1;
    return ans;
}

int main() {
    bool judge = 0;
    int count = 0;
    char str[100] = {0}, str2[100] = {0};
    do {
        if (judge) {
            printf("error PLEASE INPUT AGAIN\n");
        }
        fgets(str, 100, stdin);
    } while ((judge = haveSpace(str, &count)));
    for (int i = 0, j = 0; i < count; i++, j++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] + 5;
            if (str[i] > 'z') {
                str[i] = str[i] - 26;
            }
            str2[j] = toupper(str[i]);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 5;
            if (str[i] > 'Z') {
                str[i] = str[i] - 26;
            }
            str2[j] = tolower(str[i]);
        } else if (str[i] >= '0' && str[i] <= '9') {
            str2[j] = str[i] - 15;
        } else {
            str2[j] = '/';
            str2[j + 1] = str[i];
            j++;
        }
    }
    printf("%s", str2);
    return 0;
}

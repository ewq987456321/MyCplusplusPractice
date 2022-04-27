#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcheck(char *str){
    int len = strlen(str);
    if(len > 30)
        return 1;
    for(int i =0;str[i] != '\n';i++){
        if(isspace(str[i]))
            return 2;
    }
    return 0;
}

int main() {
    int errorCode = 0;
    char str[50] = {0}, str2[50] = {0};

    do {
        if (errorCode) {
            if (errorCode == 1) {
                printf("Length error!\n");
            }
            if (errorCode == 2) {
                printf("Space is not allow\n");
            }
        }
        fgets(str, 49, stdin);
    } while ((errorCode = strcheck(str)));

    for (int i = 0, j = 0; str[i] != '\n'; i++, j++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] + 5 > 'z') {
                str[i] = (str[i] +5 -26);
                str2[j] = toupper(str[i]);
            }
            else
                str2[j] = toupper(str[i] + 5);
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] + 5 > 'Z') {
                str2[j] = tolower(str[i] + 5 - 26);
            }
            else
                str2[j] = tolower(str[i] + 5);
        }
        if (str[i] >= '0' && str[i] <= '9') {
            str2[j] = str[i] - 15;
        }
        if (ispunct(str[i])) {
            str2[j] = '/';
            str2[j + 1] = str[i];
            j++;
        }
    }
    printf("%s",str2);
    return 0;
}
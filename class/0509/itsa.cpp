#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int ans = 0;
    char *temp;
    char target[130];
    char searchStr[514];
    // cin >> target;
    // cin >> searchStr;
    scanf("%s", target);
    scanf(" %s", searchStr);
    temp = strstr(searchStr, target);
    while (temp != NULL) {
        ans += 1;
        temp = strstr(temp + 1, target);
    }
    printf("%d\n", ans);
    for (int i = 0; i <)
        return 0;
}

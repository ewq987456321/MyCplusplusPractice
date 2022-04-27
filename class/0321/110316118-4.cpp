#include <stdio.h>
#include <string.h>
#include <iostream>

int main() {
    int num;
    scanf("%d", &num);
    for (int k = 0; k < num; k++) {
        int error = 0;
        char str[110] = {0}, str2[110] = {0};
        int count[26] = {0}, count2[26] = {0};
        std::cin >> str >> str2;
        if (strlen(str) != strlen(str2)) {
            std::cout << 0;
        } else {
            for (int i = 0; i < strlen(str); i++) {
                count[str[i] - 'a']++;
                count[str2[i] - 'a']--;
            }
            for (int i = 0; i < 26; i++) {
                if (count[i] != 0) {
                    std::cout << 0;
                    error = 1;
                    break;
                }
            }
            if (!error)
                std::cout << 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
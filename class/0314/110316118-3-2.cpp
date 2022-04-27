#include <stdio.h>
#include <string.h>

int main() {
    char str2[8][22], str[] = "錦瑟無端五十弦一弦一柱思華年莊生曉夢迷蝴蝶望帝春心托杜鵑滄海月明珠有淚藍田日暖玉生煙此情可待成追憶只是當時已惘然";
    for (int i = 0, j = 0; i < 8; i += 1, j += 21) {
        strncpy(str2[i], &str[j], 21);
        str2[i][21] = '\0';
        printf("%s\n", str2[i]);
    }

    return 0;
}

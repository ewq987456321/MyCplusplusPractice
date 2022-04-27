#include <stdio.h>

int main() {
    int game[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &game[i][j]);
        }
    }
    if (game[0][0] == game[1][0] &&game[1][0]== game[2][0]) {
        printf("True\n");
        return 0;
    } else if (game[0][1] == game[1][1] &&game[1][1]==game[2][1]) {
        printf("True\n");
        return 0;
    } else if (game[0][2] == game[1][2] && game[1][2]==game[2][2]) {
        printf("True\n");
        return 0;
    } else if (game[0][0] == game[0][1] && game[0][1]==game[0][2]) {
        printf("True\n");
        return 0;
    } else if (game[1][0] == game[1][1] && game[1][1]==game[1][2]) {
        printf("True\n");
        return 0;
    } else if (game[2][0] == game[2][1] && game[2][1]==game[2][2]) {
        printf("True\n");
        return 0;
    } else if (game[0][0] == game[1][1] && game[1][1]==game[2][2]) {
        printf("True\n");
        return 0;
    } else if (game[0][2] == game[1][1] && game[1][1]==game[2][0]) {
        printf("True\n");
        return 0;
    }
    else{
        printf("False\n");
    }
    return 0;
}
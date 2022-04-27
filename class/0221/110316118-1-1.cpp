#include <iostream>
#include <stdlib.h>
#include <time.h>

void transfer(int accountIN, int accountOUT, int money, int *account) {
    account[accountOUT - 1] -= money;
    account[accountIN - 1] += money;
}


int main() {
    srand(time(NULL));
    int account[3];
    int accountOUT=1, accountIN=2, money, func;
    for (int i = 0; i < 3; i++) {
        account[i] = rand() % 999900 + 100;
    }
    do {
        printf("choose a func list all money(1) or transfer money(2): ");
        scanf("%d", &func);
    } while (func != 1 && func != 2);
    if (func == 1) {
        for (int i = 0; i < 3; i++) {
            printf("account %d money: %d\n", i + 1, account[i]);
        }
    } else if (func == 2) {
        do {
            if (accountOUT == accountIN) {
                printf("accountOUT == accountIN, PLEASE INPUT IT AGAIN\n");
            }
            printf("input which account you want to transfer out: ");
            do {
                if(accountOUT != 1 && accountOUT != 2 && accountOUT != 3){
                    printf("input error.");
                }
                scanf("%d", &accountOUT);
            }
            while(accountOUT != 1 && accountOUT != 2 && accountOUT != 3);
            printf("account%d money: %d\n", accountOUT, account[accountOUT - 1]);
            printf("input which account you want to transfer in: ");
            do {
                if(accountIN != 1 && accountIN != 2 && accountIN != 3){
                    printf("input error");
                }
                scanf("%d", &accountIN);
            }
            while(accountIN != 1 && accountIN != 2 && accountIN != 3);
            printf("account%d money: %d\n", accountIN, account[accountIN - 1]);
        } while (accountOUT == accountIN);
        do {
            if (account[accountOUT - 1] < money) {
                printf("account[accountOUT] < money, PLEASE INPUT IT AGAIN\n");
            }
            if (money <= 0) {
                printf("money must > 0.");
            }
            printf("input how much money you want to transfer: ");
            scanf("%d", &money);
        } while (account[accountOUT - 1] < money || money <= 0);
        transfer(accountIN, accountOUT, money, account);
        printf("%d %d", account[accountOUT - 1], account[accountIN - 1]);
    }
    return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


struct bankAccount {
    long number;
    int remain_money;
    char name[100];
};

int main() {
    srand(time(NULL));
    struct bankAccount account[10];
    int func1, search, dos = 0;
    long num[10];
    for (int i = 0; i < 10; i++) {
        do {
            account[i].number = rand() % 1000000000 + 1;
            for (int j = 0; j < i - 1; j++) {
                if (num[j] != account[i].number) {
                    num[j] = account[i].number;
                } else {
                    account[i].number = rand() % 1000000000 + 1;
                    j = 0;
                }
            }

        } while (account[i].number > 100000000000LL || account[i].number < 100000000);
        account[i].name[0] = i + 96;
        account[i].remain_money = rand() % 100000;
    }
    for (int i = 0; i < 10; i++) {
        printf("account:%10li name:%c remain:%10d\n", account[i].number, account[i].name[0], account[i].remain_money);
    }
    do {
        printf("%s\n", "請輸入欲選功能(1)查詢餘額(2)存款(3)提款(4)轉帳(-1)結束:");
        scanf("%d", &func1);
        switch (func1) {
            case 1:
                search = 0;
                scanf("%d", &search);
                for (int i = 0; i < 10; i++) {
                    if (account[i].number == search) {
                        printf("帳號：%10li 餘俄:%d\n", account[i].number, account[i].remain_money);
                        break;
                    }
                    if (i + 1 == 10) {
                        printf("未找到帳號為%d俄帳戶", search);
                    }
                }

                break;
            case 2:
                search = 0;
                scanf("%d", &search);
                for (int i = 0; i < 10; i++) {
                    if (account[i].number == search) {
                        printf("帳號：%10li 餘俄:%d\n", account[i].number, account[i].remain_money);
                        int money = 1;
                        do {
                            printf("請輸入欲存款金額");
                            scanf("%d", &money);
                        } while (money < 0 || money == 0);
                        account[i].remain_money += money;
                        break;
                    }
                    if (i + 1 == 10) {
                        printf("未找到帳號為%d俄帳戶", search);
                    }
                }
                break;
            case 3:
                search = 0;
                scanf("%d", &search);
                for (int i = 0; i < 10; i++) {
                    if (account[i].number == search) {
                        printf("帳號：%10li 餘俄:%d\n", account[i].number, account[i].remain_money);
                        int money = 1;
                        do {
                            printf("請輸入欲題款金額");
                            scanf("%d", &money);
                        } while (money < 0 || money == 0 || money > account[i].remain_money);
                        account[i].remain_money -= money;
                        break;
                    }
                    if (i + 1 == 10) {
                        printf("未找到帳號為%d俄帳戶", search);
                    }
                }
                break;
            case 4:
                search = 0;
                scanf("%d", &search);

                for (int i = 0; i < 10; i++) {
                    int k;

                    if (account[i].number == search) {
                        printf("帳號：%10li 餘俄:%d\n", account[i].number, account[i].remain_money);
                        int search2;
                        scanf("%d", &search2);
                        if (search == search2) {
                            printf("輸入錯誤");
                            break;
                        }
                        for (k = 0; k < 10; k++) {
                            if (account[k].number == search2) {
                                printf("帳號：%10li 餘俄:%d\n", account[k].number, account[k].remain_money);
                                int money = 1;
                                do {
                                    printf("請輸入欲存款金額");
                                    scanf("%d", &money);
                                } while (money < 0 || money == 0 || money > account[i].remain_money);
                                account[i].remain_money -= money;
                                account[k].remain_money += money;
                                dos = 1;
                                break;
                            }
                        }
                        if (k == 10)
                            printf("未找到帳號為%d俄帳戶", search2);

                    }
                    if (dos == 0 && i == 9) {
                        printf("未找到帳號為%d俄帳戶", search);
                        break;
                    }
                }
                break;
            case -1:
                break;
            default:
                break;
        }
    } while (func1 != -1);
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
struct Account {
    char username[100] = {0};
    char password[11] = {0};
};

void searchAccount(Account account[], int count_num) {
    char target[100];
    int check = 0;
    printf("請輸入帳號: ");
    scanf("%s", target);
    for (int i = 0; i < count_num; i++) {
        if (strcmp(account[i].username, target) == 0) {
            printf("password : %s\n", account[i].password);
            check = 1;
        }
    }
    if (check == 0) {
        printf("帳號不存在\n");
    }
}

void changePassword(Account account[], int count_num) {
    char target[100];
    int check = 0;
    printf("請輸入帳號: ");
    scanf("%s", target);
    for (int i = 0; i < count_num; i++) {
        if (strcmp(account[i].username, target) == 0) {
            char password[50], temp[50];
            do {
                check = 0;
                do {
                    printf("請輸入密碼: ");
                    scanf("%s", password);
                } while (strlen(password) > 10);
                printf("請再輸入一次確認密碼: ");
                scanf("%s", temp);
                if (strcmp(temp, password) == 0)
                    check = 1;
            } while (check != 1);
            strcpy(account[i].password, temp);
            check = 1;
            break;
        }
    }
    if (check == 0)
        printf("帳號不存在\n");
    else
        printf("修改成功\n");
}

Account *addAccount(Account account[], int *count_num, int *count_space) {
    if (count_space == 0) {
        Account *temp = (Account *)malloc(sizeof(Account) * (*count_num + 5));
        for (int i = 0; i < *count_num; i++) {
            temp[i] = account[i];
        }
        free(account);
        account = temp;
    }
    char target[50];
    int check = 1;
    printf("請輸入帳號: ");
    scanf("%s", target);
    do {
        if (check == 0) {
            printf("帳號重複！\n");
            scanf("%s", target);
        }
        check = 1;
        for (int i = 0; i < *count_num; i++) {
            if (strcmp(account[i].username, target) == 0) {
                check = 0;
            }
        }
    } while (check != 1);
    *count_num = *count_num + 1;
    strcpy(account[*count_num - 1].username, target);
    for (int i = 0; i < 10; i++) {
        account[*count_num - 1].password[i] = rand() % 10 + '0';
    }
    for (int i = 0; i < *count_num; i++) {
        printf("%s %s\n", account[i].username, account[i].password);
    }
    *count_space += 4;
    return account;
}

Account *delAccount(Account account[], int *count_num, int *count_space) {
    char target[50];
    int check = 0;
    printf("請輸入帳號: ");
    scanf("%s", target);
    for (int i = 0; i < *count_num; i++) {
        if (strcmp(target, account[i].username) == 0) {
            check = i;
            break;
        }
    }
    if (check + 1) {
        for (int i = check; i < *count_num - 1; i++) {
            account[i] = account[i + 1];
        }
        *count_num -= 1;
        *count_space += 1;
    } else
        printf("帳號不存在\n");
    printf("%d %d", *count_space, *count_num);
    if (*count_space > 6) {
        Account *temp = (Account *)malloc(sizeof(Account) * (*count_num + *count_space - 5));
        for (int i = 0; i < *count_num; i++) {
            temp[i] = account[i];
        }
        free(account);
        account = temp;
        *count_space -= 5;
    }
    return account;
}

int main() {
    srand(time(NULL));
    int num;
    int count_num;
    do {
        printf("請輸入要多少帳號：");
        scanf("%d", &num);
    } while (num <= 0);
    count_num = num;
    int count_space = 0;
    Account *account = (Account *)malloc(sizeof(Account) * num);
    for (int i = 0; i < num; i++) {
        int check = 1;
        printf("請輸入帳號: ");
        scanf("%s", account[i].username);
        do {
            if (check == 0) {
                printf("請重新輸入！\n");
                scanf("%s", account[i].username);
            }
            check = 1;
            for (int j = 0; j < i; j++) {
                if (strcmp(account[i].username, account[j].username) == 0) {
                    check = 0;
                }
            }
        } while (check == 0);
        for (int k = 0; k < 10; k++) {
            account[i].password[k] = (rand() % 10 + '0');
        }
        account[i].password[10] = '\0';
    }
    for (int i = 0; i < num; i++) {
        printf("%s\n %s\n", account[i].username, account[i].password);
    }
    int func = 1;
    do {
        printf("請選擇 1) 搜尋帳號 2) 更改密碼 3) 新增帳號 4) 刪除帳號 -1) "
               "結束 : ");
        scanf("%d", &func);
        switch (func) {
        case 1:
            searchAccount(account, count_num);
            break;
        case 2:
            changePassword(account, count_num);
            break;
        case 3:
            account = addAccount(account, &count_num, &count_space);
            break;
        case 4:
            account = delAccount(account, &count_num, &count_space);
            break;
        case -1:
            free(account);
            break;
        default:
            printf("輸入錯誤請重新輸入\n");
            break;
        }
    } while (func != -1);
    // free(account);
}

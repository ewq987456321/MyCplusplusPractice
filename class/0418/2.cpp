#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
    int index;
    char ID[11];
    char name[10];
    char state;
};

int main() {
    int num, opt, key = 0, endnum = 0, tmp;
    FILE *fptr;
    data patient[100], blankdata = {0, "", "", ' '};
    char ID[11], name[10];

    /*開檔*/
    if ((fptr = fopen("掛號資料.dat", "ab+")) == NULL) {
        printf("File could not be opened.\n");
    }
    /*初始化*/
    for (int i = 0; i < 100; i++) {
        fwrite(&blankdata, sizeof(struct data), 1, fptr);
    }
    /*目前掛號*/
    printf("目前掛號: ");
    scanf("%d", &num);

    /*功能*/
    printf("1)檔案初始化 2)新增掛號 3)搜尋已掛號病患 4)已看診 5)取消掛號 6)印出所有掛號病患資料 7)印出尚未看診病患資料 -1)離開: ");
    scanf("%d", &opt);

    while (opt != -1) {
        switch (opt) {
            case 1:
                for (int i = 0; i < 100; i++) {
                    fwrite(&blankdata, sizeof(struct data), 1, fptr);
                }
                break;
            case 2:
                printf("輸入身分證號: ");
                scanf("%s", ID);
                /*將檔案中的資料讀入陣列*/
                rewind(fptr);
                for (int i = 0; i < 100; i++) {
                    fread(&patient[i], sizeof(struct data), 1, fptr);
                }
                /*搜尋是否有掛號*/
                key = 0;
                for (int i = 0; i < 100; i++) {
                    if (strcmp(patient[i].ID, ID) == 0) {
                        key = 1;// 有的話key = 1
                        printf("(已掛號)\n");
                        printf("%d %s %s %c\n", patient[i].index, patient[i].ID, patient[i].name, patient[i].state);
                    }
                }
                if (key != 1) {
                    for (int i = 0; i < 100; i++) {
                        if (patient[i].index == 0) {
                            endnum = i;//目前掛號序號最後一號
                            break;
                        }
                    }
                }
                printf("輸入姓名: ");
                scanf("%s", name);
                patient[endnum].index = endnum + 1;
                strcpy(patient[endnum].ID, ID);
                strcpy(patient[endnum].name, name);
                patient[endnum].state = 'N';
                /*將新增的資料寫入檔案*/
                rewind(fptr);
                fseek(fptr, sizeof(struct data) * endnum, SEEK_SET);
                fwrite(&patient[endnum], sizeof(struct data), 1, fptr);
                break;
            case 3:
                printf("輸入身分證號: ");
                scanf("%s", ID);
                /*將檔案中的資料讀入陣列*/
                rewind(fptr);
                for (int i = 0; i < 100; i++) {
                    fread(&patient[i], sizeof(struct data), 1, fptr);
                }
                /*搜尋是否有掛號*/
                key = 0;
                for (int i = 0; i < 100; i++) {
                    if (strcmp(patient[i].ID, ID) == 0) {
                        key = 1;// 有的話key = 1
                        printf("%d %s %s %c\n", patient[i].index, patient[i].ID, patient[i].name, patient[i].state);
                    }
                }
                if (key != 1) {
                    printf("沒有掛號\n");
                }
                break;
            case 4:
                printf("輸入掛號序號: ");
                scanf("%d", &tmp);

        }
        /*功能*/
        printf("1)檔案初始化 2)新增掛號 3)搜尋已掛號病患 4)已看診 5)取消掛號 6)印出所有掛號病患資料 7)印出尚未看診病患資料 -1)離開: ");
        scanf("%d", &opt);
    }

    fclose(fptr);
    system("pause");
    return 0;
}
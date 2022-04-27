#include <stdio.h>
#include <string.h>
#include "homework_headfile.h"



int main() {
    char Identify_code[20], mode[3];
    int func = -1;
    FILE *fptr;
    do {
        printf("請選擇功能 1)新增疫苗接種資訊 2)新增檢驗結果資訊 3)查詢個人資訊 4)顯示所有確診人員 5)刪除確診人員 -1)退出：");
        scanf("%d", &func);
        if (func != -1 && func != 4 && func != 5 && func != 3 && (func == 1 || func == 2)) {
            int check = 1;
            do {
                if (check == 0)
                    printf("身分證號輸入錯誤，請重新輸入！\n");
                printf("請輸入身分證字號：");
                scanf("%s", Identify_code);
            } while ((check = checkID(Identify_code)) != 1);
            strcat(Identify_code, ".cat");
        }
        mode[1] = '+';
        mode[2] = '\0';
        switch (func) {
            case 1:
                // 	(1) 新增疫苗接種資訊：輸入身分證號，找到此人的檔案，將新的疫苗接種資訊新增到檔案中。如果沒有此人的檔案，則新建立一個檔案。
                // 第幾劑、接種日期、疫苗品牌、接種醫院
                mode[0] = 'r';
                fptr = open_file(Identify_code, mode);
                insert_vaccine(fptr);
                fclose(fptr);
                break;
            case 2:
                // (2) 新增檢驗結果資訊：輸入身分證號，找到此人的檔案，將新的檢驗結果新增到檔案中。如果沒有此人的檔案，則新建立一個檔案。如果鑑驗結果為陽性，則將此人資訊新增到確診人員資料檔案中。
                // 檢驗日期、檢驗種類、檢驗地點、檢驗結果
                mode[0] = 'a';
                fptr = open_file(Identify_code, mode);
                insert_quarantineResult(fptr, Identify_code);
                break;
            case 3:
                // (3) 查詢個人資訊：輸入身分證號，找到此人的檔案，將所有資訊列印出來。如果沒有此人的檔案，顯示錯誤訊息。
                mode[0] = 'r';
                printf("請輸入身分證字號：");
                scanf(" %s", Identify_code);
                strcat(Identify_code, ".cat");
                fptr = fopen(Identify_code, "r");
                if (fptr == NULL)
                    printf("無此人資料！\n");
                else
                    print_info(fptr);
                break;
            case 4:
                // (4) 顯示所有確診人員：將確診人員資料檔案內紀錄的確診人員資訊全部列印出來。
                mode[0] = 'r';
                strcpy(Identify_code,"positive_check");
                strcat(Identify_code, ".cat");
                fptr = fopen(Identify_code, "r");
                if (fptr == NULL)
                    printf("無人確診！\n");
                else {
                    if (print_positive_person_info(fptr) == 0)
                        printf("無人確診！\n");
                }
                break;
            case 5:
                // (5) 刪除確診人員：輸入身分證號，將此人的資訊從確診人員資料檔案中刪除。如果檔案內沒有此人的資訊，顯示錯誤訊息。
                mode[0] = 'a';
                printf("請輸入身分證字號：");
                scanf("%s", Identify_code);
                strcat(Identify_code, ".cat");
                Identify_code[strlen(Identify_code)] = '\0';
                fptr = fopen("positive_check.cat","r+");
                if(fptr == NULL)
                    printf("無人確診！\n");
                else{
                    int count_del;
                    if((count_del=delete_positive(fptr,Identify_code))==0)
                        printf("無此人資訊！\n");
                    else{
                        printf("刪除成功");
                        printf("共刪除%d筆資料",count_del);
                    }
                }
                fclose(fptr);
                break;
            case -1:
                break;
            default:
                printf("輸入錯誤請重新輸入！\n");
        }
        fclose(fptr);
    } while (func != -1);

}



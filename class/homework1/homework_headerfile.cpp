//
// Created by Jing on 2022/4/8.
//
#include "homework_headfile.h"
#include "string.h"
#include "stdio.h"
#include "math.h"

int checkID(char *char_num) {
    char A[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'W', 'Z', 'I', 'O'};
    int int_num[10];
    for (int i = 0; i < 10; i++) {
        if (i == 0)//代表身分證第一碼
        {
            for (int j = 0; j < 26; j++) {//搜尋一樣的字，並把數字存入陣列
                if (char_num[0] == A[j])
                    int_num[0] = j + 10;
            }
        } else {
            int_num[i] = ((int) char_num[i] - 48);
        }
    }
    int P = floor(int_num[0] / 10) + (9 * (int_num[0] % 10));
    for (int i = 1; i < 8; i++) {
        P = P + (9 - i) * int_num[i];
    }
    P = P + int_num[8] + int_num[9];
    if (strlen(char_num) > 10)
        return 1;
    if (P % 10 == 0)
        return 1;
    else
        return 0;
}

int checkDAY(char *char_day) {
    int check = 1;
    char cpy_day[20];
    char *year, *month, *day;
    char base_year[5] = "1922", base_month[3] = "01", base_day[3] = "01";
    char up_year[5] = "2022", up_month[3] = "12", up_day[3] = "31";
    strcpy(cpy_day, char_day);
    year = strtok(cpy_day, "/");
    if (year != NULL)
        month = strtok(NULL, "/");
    else {
        check = 0;
    }
    if (month != NULL)
        day = strtok(NULL, "/");
    else
        check = 0;
    if (day == NULL)
        check = 0;
    if (check == 0)
        return check;
    else if (strcmp(year, base_year) < 0 || strcmp(month, base_month) < 0 || strcmp(day, base_day) < 0)
        check = 0;
    else if (strcmp(year, up_year) > 0 || strcmp(month, up_month) > 0 || strcmp(day, up_day) > 0)
        check = 0;
    else if (strlen(year) != 4 || strlen(month) != 2 || strlen(day) != 2)
        check = 0;
    else
        check = 1;
    return check;
}

int checkCOUNT_VACCINE(FILE *fptr, int countVaccine) {
    rewind(fptr);
    char type[20], conten1[50], content2[50], content3[50], content4[50];
    int count = 0;
    fscanf(fptr, "%s%s%s%s%s", type, conten1, content2, content3, content4);
    while (!(feof(fptr))) {
        if (strcmp(type, "vaccine") == 0) {
            count += 1;
        }
        fscanf(fptr, "%s%s%s%s%s", type, conten1, content2, content3, content4);
    }
    if (countVaccine <= count || countVaccine < 0)
        return 0;
    else
        return 1;
}

FILE *open_file(char *filename, char *mode) {
    FILE *fptr = fopen(filename, mode);
    if (fptr == NULL) {
        fptr = fopen(filename, "w+");
    }
    return fptr;
}

void insert_vaccine(FILE *fptr) {
    int count_vaccination = 0;
    int dayCheck = 1, vaccineCheck = 2;
    char vaccine_factory[50], vaccination_date[20], vaccination_place[50];
    do {
        if (vaccineCheck == 0)
            printf("第%d劑疫苗已接種完成，請重新輸入\n", count_vaccination);
        printf("請輸入此為第幾劑疫苗：");
        scanf("%d", &count_vaccination);
    } while ((vaccineCheck = checkCOUNT_VACCINE(fptr, count_vaccination)) != 1);
    printf("請輸入疫苗廠牌：");
    scanf(" %s", vaccine_factory);
    do {
        if (dayCheck == 0)
            printf("日期輸入錯誤請重新輸入！\n");
        printf("請輸入接種日期(yyyy/mm/dd ex:2022/12/01)：");
        scanf(" %s", vaccination_date);
    } while ((dayCheck = checkDAY(vaccination_date)) != 1);
    printf("請輸入接種院所：");
    scanf(" %s", vaccination_place);
    fprintf(fptr, "%s\t%d\t%s\t%s\t%s\n", "vaccine", count_vaccination, vaccine_factory, vaccination_date, vaccination_place);
}

void insert_quarantineResult(FILE *fptr, char *ID) {
    int dayCheck = 1, resultCheck = 1;
    char check_type[50], check_place[50], check_date[50], check_result[50];
    do {
        if (dayCheck == 0)
            printf("日期輸入錯誤請重新輸入！\n");
        printf("請輸入檢驗日期(yyyy/mm/dd ex:2022/12/01)");
        scanf("%s", check_date);
    } while ((dayCheck = checkDAY(check_date)) != 1);
    printf("清輸入檢驗種類");
    scanf("%s", check_type);
    printf("請輸入檢驗地點");
    scanf("%s", check_place);
    do {
        if (resultCheck == 0)
            printf("檢測結果輸入錯誤！\n");
        printf("請輸入檢測結果(y/n)");
        scanf("%s", check_result);
    } while ((resultCheck = (strcmp(check_result, "y") == 0 || strcmp(check_result, "n") == 0)) != 1);
    if (strcmp(check_result, "y") == 0) {
        insert_positive(ID, check_date, check_type, check_place, check_result);
    }
    fprintf(fptr, "%s\t%s\t%s\t%s\t%s\n", "quarantine", check_date, check_type, check_place, check_result);
}

void insert_positive(char *id, char date[50], char type[50], char place[50], char result[50]) {
    FILE *fptr = fopen("positive_check.cat", "a+");
    fprintf(fptr, "%s\t%s\t%s\t%s\t%s\n", result, date, type, place, id);
    fclose(fptr);
}

void print_info(FILE *fptr) {
    char file_content[50];
    fscanf(fptr, "%s", file_content);
    while (!feof(fptr)) {
        char content1[50], content2[50], content3[50], content4[50];
        if (strcmp(file_content, "vaccine") == 0)
            printf("%s\n%-20s%-20s%-20s%-20s\n", "疫苗接種： ", "第幾劑", "疫苗廠牌", "接種日期", "接種地點");
        else
            printf("%s\n%-20s%-20s%-20s%-20s\n", "確診篩檢： ", "檢驗日期", "檢驗種類", "檢驗地點", "檢測結果");
        fscanf(fptr, "%s%s%s%s", content1, content2, content3, content4);
        printf("%-16s%-15s%-15s%s\n", content1, content2, content3, content4);
        fscanf(fptr, "%s", file_content);
    }
}

int print_positive_person_info(FILE *fptr) {
    char is_positive[10];
    int count_positive = 0;
    char content1[20], contwnt2[20], content3[20], content4[20];
    fscanf(fptr, "%s", is_positive);
    fscanf(fptr, "%s%s%s%s", content1, contwnt2, content3, content4);
    while (!feof(fptr)) {
        if (strcmp(is_positive, "y") == 0) {
            count_positive += 1;
            printf("%-20s%-20s%-20s%-20s\n", content1, contwnt2, content3, content4);
        }
        fscanf(fptr, "%s", is_positive);
        fscanf(fptr, "%s%s%s%s", content1, contwnt2, content3, content4);
    }
    return count_positive;
}

struct people{
    char check[100] = {0};
    char time[50] = {0};
    char type[50] = {0};
    char place[50] = {0};
    char ID[100] = {0};
};

int delete_positive(FILE *fptr, char code[20]) {
    int count = 0, count_del = 0,count_data=0;
    FILE *temp = fopen("temp.cat", "w");
    while (!(feof(fptr))) {
        people people;
        //char check[50], time[50], ID[20], type[20], place[50];
        do {
            count = fscanf(fptr, "%s%s%s%s%s", people.check, people.time, people.type, people.place, people.ID);
            if(count!=-1)
                count_data += 1;
        } while ((strcmp(people.check, "y") == 0 && strcmp(people.ID, code) == 0) && count != -1);
        if (count != -1){
            fprintf(temp, "%s\t%s\t%s\t%s\t%s\n", people.check, people.time, people.type, people.place, people.ID);
            count_del += 1;

        }
    }
    fclose(temp);
    fclose(fptr);
    remove("positive_check.cat");
    rename("temp.cat", "positive_check.cat");
    return count_data - count_del;
}


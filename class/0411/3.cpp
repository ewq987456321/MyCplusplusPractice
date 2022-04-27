#include <stdio.h>
#include <string.h>

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
    else
        check = 1;
    return check;
}
    struct data {
        int up_pressure;
        int low_pressure;
        char date[50] = {0};
        char time[50];
    };

int checkTIME(char time[50]) {
    int check = 1;
    char cpy_day[20];
    char *year, *month, *day;
    char base_our[20] = "1",up_out[20] = "24" , base_min[20] = "00",up_min[20] = "59";
    strcpy(cpy_day, time);
    year = strtok(cpy_day, ":");
    if (year != NULL)
        month = strtok(NULL, ":");
    else {
        check = 0;
    }
    if (month != NULL){
        if(strcmp(year,base_our) < 0 || strcmp(year,up_out) >0)
            check =0;
        else if(strcmp(month,base_min) <0 || strcmp(month,up_min) >0)
            check =0;
        else
            check =1;
    }
    else
        check =0;

    return check;
}

int main() {
        int func = 1, check_print = 0, check_Day;
        char time[100];
        struct data person;
        FILE *fptr;
        do {
            printf("清輸入預選功能 1)輸入資料 2)查詢資料 -1)結束");
            scanf("%d", &func);
            switch (func) {
                case 1:
                    fptr = fopen("date.cat", "a");
                    do {
                        printf("請輸入日期(2022/12/01)：");
                        scanf("%s", person.date);
                    } while ((check_Day = checkDAY(person.date)) != 1);
                    do{
                        printf("清輸入時間(12:01)：");
                        scanf("%s", person.time);
                    }while((check_Day = checkTIME(person.time)) != 1);
                    do{
                        printf("請輸入收縮壓");
                        scanf("%d", &person.up_pressure);
                    }while(person.up_pressure <=0);
                    do{
                        printf("請輸入舒張壓");
                        scanf("%d", &person.low_pressure);
                    }while(person.low_pressure <=0);

                    fprintf(fptr, "%s\t%s\t%d\t%d\n", person.date, person.time, person.low_pressure, person.up_pressure);
                    fclose(fptr);
                    break;
                case 2:
                    fptr = fopen("date.cat", "r");
                    do {
                        printf("請輸入日期(2022/12/01)：");
                        scanf("%s", time);
                    } while ((check_Day = checkDAY(time)) != 1);
                    fscanf(fptr, "%s%s%d%d", person.date, person.time, &person.low_pressure, &person.up_pressure);
                    while (!(feof(fptr))) {
                        if (strcmp(person.date, time) == 0) {
                            printf("%s\t%s\t%d\t%d\n", person.date, person.time, person.low_pressure, person.up_pressure);
                            check_print = 1;
                        }
                        fscanf(fptr, "%s%s%d%d", person.date, person.time, &person.low_pressure, &person.up_pressure);
                    }
                    if (check_print == 0)
                        printf("查無資料\n");
                    fclose(fptr);
                    break;
                case -1:
                    break;
                default:
                    printf("input error~\n");
                    break;
            }
        } while (func != -1);
        return 0;
    }
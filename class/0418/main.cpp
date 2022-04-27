#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Person {
    int num = -1;
    char name[50] = {0};
    char ID[30] = {0};
    char check = 0;
};

void add_registered() {
    FILE *fptr;
    Person add_person;
    int count = 0;
    fptr = fopen("registered.cat", "r+");
    if (fptr != NULL) {
        rewind(fptr);
        fread(&count, sizeof(int), 1, fptr);
        char exist[100][50] = {0}, exist_check[100][2] = {0};
        int check_exist = 0;
        Person temp;
        for (int i = 0, count_exist = 0; i < count; i++, count_exist++) {
            fread(&temp, sizeof temp, 1, fptr);
            strcpy(exist[count_exist], temp.ID);
            strcpy(exist_check[count_exist], &temp.check);
        }
        rewind(fptr);
        do {
            cout << "請輸入身分證字號： ";
            cin >> add_person.ID;
            int checkk = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(add_person.ID, exist[i]) == 0 && exist_check[i][0] == 'n') {
                    checkk = 1;
                }
            }
            if (checkk != 1)
                check_exist = 1;
        } while (check_exist != 1);
        cout << "請輸入姓名： ";
        cin >> add_person.name;
        add_person.num = ++count;
        add_person.check = 'n';
        fwrite(&count, sizeof(count), 1, fptr);
        fseek(fptr, (sizeof(Person) * (count - 1)), SEEK_CUR);
        fwrite(&add_person, sizeof(add_person), 1, fptr);
    } else
        cout << "資料不存在\n";
    fclose(fptr);
}

void list_all() {
    FILE *fptr = fopen("registered.cat", "r");
    rewind(fptr);
    if (fptr != NULL) {
        int count;
        Person list_person;
        fread(&count, sizeof(count), 1, fptr);
        printf("%-16s%-28s%-20s%s", "號碼", "身分證字號", "姓名", "是否看診\n");
        for (int i = 0; i < count; i++) {
            fread(&list_person, sizeof(list_person), 1, fptr);
            if (list_person.num != -1)
                printf("%-14d%-20s%-20s%-20c\n", list_person.num, list_person.ID, list_person.name, list_person.check);
        }
    } else
        cout << "資料不存在\n";
    fclose(fptr);
}

void del_registered() {
    int func = 1;
    FILE *fptr = fopen("registered.cat", "r+");
    char del_ID[20];
    do {
        cout << "請輸入欲取消方式 1)依掛號序號 2)依身分證字號字號： ";
        cin >> func;
        switch (func) {
            case 1:
                cout << "請輸入欲取消『掛號序號』： ";
                cin >> del_ID;
                if (fptr != NULL) {
                    int count, num;
                    Person temp;
                    fread(&count, sizeof(count), 1, fptr);
                    num = atoi(del_ID);
                    fseek(fptr, sizeof(temp) * (num - 1), SEEK_CUR);
                    fread(&temp, sizeof(temp), 1, fptr);
                    if (temp.num != -1) {
                        if (temp.check == 'n') {
                            Person space;
                            fseek(fptr, -(sizeof(space)), SEEK_CUR);
                            fwrite(&space, sizeof(space), 1, fptr);
                        } else
                            cout << "此人以看診\n";
                    } else
                        cout << "此人尚未掛號\n";
                } else
                    cout << "無此檔案\n";
                fclose(fptr);
                break;
            case 2:
                cout << "請輸入欲取消『身分證字號』：";
                cin >> del_ID;
                if (fptr != NULL) {
                    int count, check_ID = 0,search=0;
                    Person temp;
                    fread(&count, sizeof(count), 1, fptr);
                    for (int i = 0; i < count; i++) {
                        fread(&temp, sizeof(temp), 1, fptr);
                        if (strcmp(temp.ID, del_ID) == 0 && temp.check != 'y') {
                            check_ID = 1;
                            search = i;
//                            break;
                        } else if (strcmp(temp.ID, del_ID) == 0 && temp.check != 'n') {
                            check_ID = 2;
//                            break;
                        }
                    }
                    if (check_ID == 1) {
                        rewind(fptr);
                        fread(&count,sizeof(count),1,fptr);
                        fseek(fptr, (sizeof(temp)*(search)), SEEK_CUR);
                        Person space;
                        fwrite(&space, sizeof(temp), 1, fptr);
                        cout << "成功取消\n";
                    } else if (check_ID == 2)
                        cout << "此人以看診";
                    else
                        cout << "此人無掛號資料\n";
                    fclose(fptr);
                } else
                    cout << "無此檔案\n";
                break;
            default:
                cout << "輸入錯誤請重新輸入\n";
                break;
        }
    } while (func != 1 && func != 2);

}

void search_registered() {
    char search_ID[20];
    cout << "請輸入欲查詢『身分證字號』： ";
    cin >> search_ID;
    FILE *fptr = fopen("registered.cat", "r");
    if (fptr != NULL) {
        int count, check_search = 0;
        Person temp, info;
        fread(&count, sizeof(count), 1, fptr);
        for (int i = 0; i < count; i++) {
            fread(&temp, sizeof(temp), 1, fptr);
            if (strcmp(temp.ID, search_ID) == 0) {
                info = temp;
                check_search = 1;
            }
        }
        if (check_search == 1) {
            cout << "掛號號碼： " << info.num << endl;
            cout << "身分證字號： " << info.ID << endl;
            cout << "姓名： " << info.name << endl;
            cout << "是否看診： " << info.check << endl;
            cout << "註： y:已看診  n:尚未看診\n";
        } else
            cout << "無此人掛號資料\n";
    } else
        cout << "無此檔案";
}

void file_init() {
    FILE *check;
    check = fopen("registered.cat", "w");
    Person space_struct;
    int space_int = 0;
    fwrite(&space_int, sizeof(space_int), 1, check);
    for (int i = 0; i < 100; i++) {
        fwrite(&space_struct, sizeof(space_struct), 1, check);
    }
    fclose(check);
}

void change_status() {
    int num, count;
    Person temp;
    cout << "請輸入掛號序號：";
    cin >> num;
    FILE *fptr = fopen("registered.cat", "r+");
    fread(&count, sizeof(count), 1, fptr);
    fseek(fptr, sizeof(temp) * (num - 1), SEEK_CUR);
    fread(&temp, sizeof(temp), 1, fptr);
    if (temp.num != -1) {
        if (temp.check != 'y') {
            fseek(fptr, -(sizeof(temp)), SEEK_CUR);
            temp.check = 'y';
            fwrite(&temp, sizeof(temp), 1, fptr);
            printf("修改成功\n");
        } else {
            printf("此人以看診\n");
        }
    } else {
        printf("此人未掛號\n");
    }
    fclose(fptr);
}

void list_no_see_doctor() {
    FILE *fptr = fopen("registered.cat", "r");
    rewind(fptr);
    if (fptr != NULL) {
        int count;
        Person list_person;
        fread(&count, sizeof(count), 1, fptr);
        printf("%-16s%-28s%-20s%s", "號碼", "身分證字號", "姓名", "是否看診\n");
        for (int i = 0; i < count; i++) {
            fread(&list_person, sizeof(list_person), 1, fptr);
            if (list_person.check != 'y' && list_person.num != -1)
                printf("%-14d%-20s%-20s%-20c\n", list_person.num, list_person.ID, list_person.name, list_person.check);
        }
    } else
        cout << "資料不存在\n";
    fclose(fptr);
}

int main() {
    int func = 1;
    do {
        cout << "請輸入預選功能1)檔案初始化 2)新增掛號 3)查詢已掛號病患 4)以看診 5)取消掛號 6)印出所有掛號病患資料 7)印出尚未看診病患資料 -1)結束： ";
//        cout << "請輸入欲選功能 1)新增掛號 2)取消掛號 3)列出所有掛號資料 4)查詢 -5)已看診 1)結束: ";
        cin >> func;
        switch (func) {
            case 1:
                file_init();
                break;
            case 2:
                add_registered();
                break;
            case 3:
                search_registered();
                break;
            case 4:
                change_status();
                break;
            case 5:
                del_registered();
                break;
            case 6:
                list_all();
                break;
            case 7:
                list_no_see_doctor();
                break;
            case -1:
                break;
            default:
                cout << "輸入錯誤請重新輸入" << endl;
        }
    } while (func != -1);
    return 0;
}

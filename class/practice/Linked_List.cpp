#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

struct Student {
    char ID[30] = {0};
    int grade = -1;
    Student *nextPtr = NULL;
};

// Add data in front of the first data.
Student *addData_TH(Student **head, Student *current, Student *temp)
{
    // If there is nothing in the record
    if (*head == NULL) {
        *head = temp; // Let head point to new_data's address
        current = *head;
    }
    else {
        Student *head_old = *head;
        *head = temp;             // Let head become new data
        temp->nextPtr = head_old; // link new_head to old_head
    }
    return current;
}

// Add data behind of the final data
Student *addData_TB(Student **head, Student *current, Student *temp)
{
    // If there is nothing in the record
    if (*head == NULL) {
        *head = temp;
        current = *head;
    }
    else {
        current->nextPtr = temp; // Let the final_data's nextPtr point to new_data
        current = temp;          // Let current point to new_data
    }
    return current;
}

// Add data proccess
void addData(Student **head)
{
    Student *current = *head; // current: where is to add data
    int num = 1;
    // Input how much data to add and avoid user input the number less than 0
    do {
        if (num < 0) cout << "輸入錯誤請重新輸入" << endl;
        cout << "請輸入要新增多少筆資料 (輸入「 0 」以退出): ";
        cin >> num;
    } while (num < 0);
    // Move to where the next node is space.
    while (current != NULL && current->nextPtr != NULL) {
        current = current->nextPtr;
    }
    for (int i = 0; i < num; i++) {
        Student *temp = (Student *)malloc(sizeof(Student));
        int check = 1, func;
        do {
            if (check == 0) cout << "輸入重複!\n";
            check = 1;
            Student *current_check = *head;
            cout << "請輸入學生ID:";
            cin >> temp->ID;
            for (; current_check != NULL; current_check = (current_check->nextPtr)) {
                if (strcmp(current_check->ID, temp->ID) == 0) {
                    check = 0;
                    break;
                }
            }
        } while (check != 1);
        // Input grade and avoid user input the number less than 0.
        do {
            cout << "請輸入學生成績: ";
            cin >> temp->grade;
        } while (temp->grade < 0);
        do {
            cout << "請選擇 1)新增在第一筆資料前 2)新增在最後面: ";
            cin >> func;
            switch (func) {
            case 1:
                current = addData_TH(head, current, temp);
                break;
            case 2:
                current = addData_TB(head, current, temp);
                break;
            default:
                cout << "輸入錯誤請重新輸入!\n";
                break;
            }
        } while (func != 1 && func != 2);
    }
}

void freeData(Student *head)
{
    Student *current = head, *temp = head;
    while (current->nextPtr != NULL) {
        temp = current->nextPtr;
        free(current);
        current = temp;
    }
}

void printAll(Student *head)
{
    Student *current = head;
    while (current != NULL) {
        cout << "studentID: " << current->ID << " | grade: " << current->grade << endl;
        current = current->nextPtr;
    }
}

// Search data with index.
void searchData_index(Student *head)
{
    int target = 1, i = 0;
    Student *current = head;
    // Input which index user wants to search and avoid user input the number less than 0.
    do {
        if (target < 0) cout << "輸入錯誤!\n";
        cout << "請輸入要搜尋的索引: ";
        cin >> target;
    } while (target < 0);
    // Avoid there is nothing in the record.
    if (current != NULL) {
        for (; i < target && current != NULL; i++) {
            current = current->nextPtr;
        }
        // Means the target index is more than the number of record
        if (i != target || current == NULL) {
            cout << "此目標無資料\n";
        }
        else
            cout << "Student-ID: " << current->ID << " grade: " << current->grade << endl;
    }
    else
        cout << "尚未新增任何資料!\n";
}

// Search data with student's ID.
void searchData_ID(Student *head)
{
    char target[30];
    int searched = 1; // record if search the data or not.
    Student *current = head;
    cout << "請輸入要搜尋的ID: ";
    cin >> target;
    if (current != NULL) {
        while (current != NULL && (searched = strcmp(target, current->ID)) != 0) {
            current = current->nextPtr;
        }
        if (searched == 0)
            cout << "Student-ID: " << current->ID << " grade: " << current->grade << endl;
        else
            cout << "查無此人資料!\n";
    }
    else
        cout << "尚未新增任何資料!\n";
}

// Search data proccess.
void searchData(Student *head)
{
    int func = 1;
    do {
        cout << "請選擇1) 根據索引 2)根據學生ID: ";
        cin >> func;
        switch (func) {
        case 1:
            searchData_index(head);
            break;
        case 2:
            searchData_ID(head);
            break;
        default:
            cout << "輸入錯誤請重新輸入!\n";
        }
    } while (func <= 0);
}

// Delete data with index.
Student *delData_index(Student *head)
{
    Student *current = head;
    if (current != NULL) {
        int target = 1;
        // Input target index and avoid user input the number less than 0.
        do {
            if (target < 0) cout << "輸入錯誤請重新輸入!\n";
            cout << "請輸入要刪除的index: ";
            cin >> target;
        } while (target < 0);
        // Move to the node in front of the target and avoid move over the record.
        for (int i = 0; i < target - 1 && current != NULL; i++) {
            current = current->nextPtr;
        }
        if (current != NULL) {
            // Delete the head data.
            if (current == head && target == 0) {
                Student *del = current;
                head = current->nextPtr;
                free(del);
            }
            else {
                Student *del = current->nextPtr;
                current->nextPtr = del->nextPtr;
                free(del);
            }
        }
        else
            cout << "資料不存在!\n";
    }
    else
        cout << "尚未新增任何資料!\n";
    return head;
}

// Delete data with student's ID.
Student *delData_ID(Student *head)
{
    Student *current = head;
    if (current != NULL) {
        char target[30];
        int searched;
        cout << "請輸入要刪除的學生ID: ";
        cin >> target;
        // Move to the node before target and avoid move over the record.
        while (current->nextPtr != NULL && (searched = strcmp(current->nextPtr->ID, target)) != 0 &&
               strcmp(current->ID, target) != 0) {
            current = current->nextPtr;
        }
        Student *del;
        // Delete head data.
        if (strcmp(current->ID, target) == 0) {
            del = current;
            head = current->nextPtr;
            free(del);
        }
        else if (searched == 0) {
            del = current->nextPtr;
            current->nextPtr = del->nextPtr;
            free(del);
        }
        else
            cout << "無此人資料!\n";
    }
    else
        cout << "尚未新增任何資料!\n";
    return head;
}

// Delete data proccess.
Student *delData(Student *head)
{
    int func = 1;
    do {
        cout << "請選擇 1) 透過索引刪除 2)透過學生ID刪除: ";
        cin >> func;
        switch (func) {
        case 1:
            head = delData_index(head);
            break;
        case 2:
            head = delData_ID(head);
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func != 1 && func != 2);
    return head;
}

int main()
{
    int func = 1;
    Student *head = 0;
    do {
        cout << "1) 新增資料 2) 查詢資料 3) 刪除資料 4)印出所有 -1) 結束: ";
        scanf("%d", &func);
        switch (func) {
        case 1:
            addData(&head);
            break;
        case 2:
            searchData(head);
            break;
        case 3:
            head = delData(head);
            break;
        case 4:
            printAll(head);
            break;
        case -1:
            freeData(head);
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func != -1);
}

#ifndef HEDER
#define HEDER

#include <string>
using namespace std;

class member {
public:
    string name = "";
    string ID = "";
    string phone_number = "";
    string role = "";
    member *member_next = NULL;
    void change_info(); // PERF:修改名稱 電話 角色
};

class group {
public:
    string group_name = "";
    bool assinged = false;
    member *list = NULL;
    group *group_next = NULL;
};

class work_type {
public:
    string type_name = "";
    work_type *work_type_next = NULL;
};

class work {
public:
    string work_name = "";
    string directions = "";
    string mark = "";
    string progress_rate = "";
    work_type *type = NULL; // one value which point to a work_type in list.
    group *member = NULL;   // one value which point to a member list
    work *work_next = NULL;

    void print_member();                                            // PERF:印出任務成員
    void change_type(class work_type *list);                        // TODO:直接新增類別(*list需修改)
    void change_group(class group *list);                           // PERF:修改小組
    void change_info(class work_type *t_list, class group *g_list); // PERF:修改名稱 描述 註記 進度
};

void add_work(class work **list, class group **g_list,
              class work_type **t_list); // add a new work  TODO:group_assigned 標註
void modify_work(class work *list, class work_type *t_list,
                 class group *g_list); // print all works  TODO:直接新增(*list需修改)
void print_works(class work *list);    // PERF:印出小組名稱

// PERF:新增小組
void add_group(class group **list); // add a new member in group
// PERF:修改小組名稱（搜尋->修改）
void modify_group(class group *list);

// PERF:新增小組成員
void add_member(class member **list);
// PERF:刪除成員
void del_member(class member **list);

// PERF:新增類別
void add_workType(class work_type **list);
// PERF:修改類別
void modify_workType(class work_type *list);

// PERF:釋放記憶體
void free_LK(class work *w_list, class group *g_list, class work_type *t_list);
#endif

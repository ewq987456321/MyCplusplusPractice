#include "header.h"
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

void member::change_info() {
    int func = -1;
    do {
        cout << "請選則1) 修改名字 2)修改電話號碼 3)修改角色 -1)退出";
        cin >> func;
        switch (func) {
        case 1:
            cout << "請輸入欲修改的名稱: ";
            cin >> name;
            cout << "修改成功\n";
            break;
        case 2:
            cout << "請輸入要修改的電話號碼: ";
            cin >> phone_number;
            cout << "修改成功\n";
            break;
        case 3:
            do {
                if (role.length() != 10) {
                    cout << "輸入錯誤請重新輸\n";
                }
                cout << "請輸入要修改的角色: ";
                cin >> role;
            } while (role.length() != 10);
            cout << "修改成功\n";
            break;
        case -1:
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func != 1 && func != 2 && func != 3 && func != -1);
}

void work::change_group(class group *list) {
    group *current = list;
    bool fined = false;
    if (current != NULL) {
        string temp;
        cout << "請輸入要更改成的小組名稱: ";
        cin >> temp;
        while (current != NULL) {
            if (current->group_name == temp) {
                fined = true;
                break;
            }
            current = current->group_next;
        }
        if (fined) {
            member = current;
            cout << "更改成功\n";
        } else {
            cout << "未搜尋到輸入的小組\n";
        }
    } else {
        cout << "尚未新增任何小組\n";
    }
}

void work::change_info(class work_type *t_list, class group *g_list) {
    int func = -1;
    do {
        cout << "請選則 1)修改任務名稱 2)修改描述 3)修改進度 4)修改註記 5)修改類別 6)修改小組 -1)退出";
        cin >> func;
        switch (func) {
        case 1:
            cout << "請輸入要修改的任務名稱: ";
            cin >> work_name;
            cout << "修改成功\n";
            break;
        case 2:
            cout << "請輸入要修改的描述: ";
            cin >> directions;
            cout << "修改成功\n";
            break;
        case 3:
            cout << "請輸入要修改的進度: ";
            cin >> progress_rate;
            cout << "修改成功\n";
            break;
        case 4:
            cout << "請輸入要修改的註記: ";
            cin >> mark;
            cout << "修改成功\n";
            break;
        case 5:
            change_type(t_list);
            break;
        case 6:
            change_group(g_list);
            break;
        case -1:
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func != 1 && func != 2 && func != 3 && func != 4 && func != 5 && func != -1);
}

void work::print_member() {
    class member *current = member->list;
    if (current != NULL) {
        while (current != NULL) {
            cout << current->name << " ";
            current = current->member_next;
        }
    } else {
        cout << "尚未指定小組";
    }
}

void work::change_type(class work_type *list) {
    class work_type *current = list;
    if (current != NULL) {
        string temp_type;
        bool fined = false;
        cout << "請輸入要修改的類別: ";
        cin >> temp_type;
        while (current != NULL && !(fined)) {
            if (current->type_name == temp_type) {
                fined = true;
                break;
            }
            current = current->work_type_next;
        }
        if (fined) {
            type = current;
        } else if (current == NULL) {
            cout << "類別列表無您輸入的內容\n";
            // TODO: 問要不要直接新增，若做可把若為空刪除
        }
    } else {
        cout << "尚未新增任何類別\n";
    }
}

void print_works(class work *list) {
    class work *current = list;
    if (current != NULL) {
        while (current != NULL) {
            cout << "任務名稱: " << current->work_name << endl;
            cout << "小組名稱: " << current->member->group_name << endl;
            cout << "成員: ";
            current->print_member();
            cout << "\n";
            cout << "描述: " << current->directions << endl;
            cout << "註記: " << current->mark << endl;
            cout << "類別: " << current->type->type_name << endl;
            cout << "進度: " << current->progress_rate << endl << endl;
            current = current->work_next;
        }
    } else {
        cout << "尚未新增任何任務\n";
    }
}

void modify_work(class work *list, class work_type *t_list, class group *g_list) {
    work *current = list;
    bool fined = false;
    if (current != NULL) {
        string temp_name;
        cout << "請輸入要修改的任務名稱: ";
        cin >> temp_name;
        while (current != NULL) {
            if (current->work_name == temp_name) {
                fined = true;
                break;
            }
            current = current->work_next;
        }
        if (fined) {
            current->change_info(t_list, g_list);
        } else {
            cout << "為搜尋到您輸入的內容\n";
        }
    } else {
        cout << "尚未新增任何任務\n";
        // TODO:問要不要新增
    }
}

void add_group(class group **list) {
    group *current = *list;
    group *add = (group *)malloc(sizeof(group)), *check = *list;
    bool inGroup = false;
    do {
        if (inGroup) cout << "小組重複\n";
        inGroup = false;
        check = *list;
        cout << "請輸入要新增的小組名稱: ";
        cin >> add->group_name;
        while (check != NULL) {
            if (check->group_name == add->group_name) {
                inGroup = true;
                break;
            }
            check = check->group_next;
        }
    } while (inGroup);
    add_member(&add->list);
    if (current == NULL) {
        *list = add;
    } else {
        add->group_next = current;
        *list = add;
    }
}

void modify_group(class group *list) {
    group *current = list;
    group *check = list;
    member *m_current;
    int func = 1;
    if (current != NULL) {
        cout << "請選擇 1)修改小組名稱 2)查看小組成員 3)修改成員訊息 4)新增成員 5)刪除成員: ";
        cin >> func;
        string temp;
        bool fined = false, inGroup = false;
        cout << "請輸入要查詢的小組名稱: ";
        cin >> temp;
        while (current != NULL) {
            if (current->group_name == temp) {
                fined = true;
                break;
            }
            current = current->group_next;
        }
        if (fined) {
            switch (func) {
            case 1:
                do {
                    check = list;
                    if (inGroup) cout << "小組名稱重複\n";
                    inGroup = false;
                    cout << "請輸入要修改成的小組名稱: ";
                    cin >> temp;
                    while (check != NULL) {
                        if (check == current) {
                            check = check->group_next;
                            continue;
                        }
                        if (check->group_name == temp) {
                            inGroup = true;
                            break;
                        }
                        check = check->group_next;
                    }
                } while (inGroup);
                current->group_name = temp;
                cout << "修改成功\n";
                break;
            case 2:
                m_current = current->list;
                while (m_current != NULL) {
                    cout << "name: " << m_current->name << endl;
                    cout << "ID: " << m_current->phone_number << endl;
                    cout << "rele: " << m_current->role << endl << endl;
                    m_current = m_current->member_next;
                }
                break;
            case 3:
                m_current = current->list;
                fined = false;
                cout << "請輸入要修改的成員ID: ";
                cin >> temp;
                while (m_current != NULL) {
                    if (m_current->ID == temp) {
                        fined = true;
                        break;
                    }
                    m_current = m_current->member_next;
                }
                if (fined) {
                    m_current->change_info();
                } else {
                    cout << "未找到輸入的成員\n";
                }
                break;
            case 4:
                add_member(&current->list);
                break;
            case 5:
                del_member(&current->list);
                break;
            case -1:
                break;
            default:
                cout << "輸入錯誤請重新輸入\n";
                break;
            }
        } else {
            cout << "未找到您輸入的小組\n";
        }
    } else {
        cout << "尚未新增任何小組\n";
    }
}

void add_workType(class work_type **list) {
    work_type *current = *list;
    work_type *check = *list;
    work_type *add = (work_type *)malloc(sizeof(work_type));
    bool inWorkType = false;
    do {
        if (inWorkType) {
            cout << "類別重複\n";
        }
        inWorkType = false;
        check = *list;
        cout << "請輸入要新增的類別: ";
        cin >> add->type_name;
        while (check != NULL) {
            if (check->type_name == add->type_name) {
                inWorkType = true;
                break;
            }
            check = check->work_type_next;
        }
    } while (inWorkType);
    if (current == NULL) {
        *list = add;
    } else {
        add->work_type_next = current;
        *list = add;
    }
}

void modify_workType(class work_type *list) {
    work_type *current = list;
    work_type *check = list;
    if (current != NULL) {
        string temp;
        bool fined = false, inWorkType = false;
        cout << "請輸入要修改的類別名稱: ";
        cin >> temp;
        while (current != NULL) {
            if (current->type_name == temp) {
                fined = true;
                break;
            }
            current = current->work_type_next;
        }
        if (fined) {
            do {
                if (inWorkType) cout << "類別重複\n";
                inWorkType = false;
                check = list;
                cout << "請輸入要修該成的類別名稱: ";
                cin >> temp;
                while (check != NULL) {
                    if (check == current) {
                        check = check->work_type_next;
                        continue;
                    }
                    if (check->type_name == temp) {
                        inWorkType = true;
                        break;
                    }
                    check = check->work_type_next;
                }
            } while (inWorkType);
            current->type_name = temp;
            cout << "修改成功\n";
        } else {
            cout << "未找到您輸入的類別\n";
        }
    } else {
        cout << "尚未新增任何類別\n";
    }
}

void add_work(class work **list, class group **g_list, class work_type **t_list) {
    class work *current = *list;
    class work *add = (work *)malloc(sizeof(work));
    class group *g_current = *g_list;
    class work_type *t_current = *t_list;
    string temp;
    bool fined = true;
    do {
        if (!(fined)) cout << "任務名稱重複\n";
        fined = true;
        current = *list;
        cout << "請輸入要新增的任務名稱: ";
        cin >> add->work_name;
        while (current != NULL) {
            if (current->work_name == add->work_name) {
                fined = false;
                break;
            }
            current = current->work_next;
        }
    } while (!(fined));
    cout << "請輸入新任務的描述: ";
    cin >> add->directions;
    cout << "請輸入新任務的註記: ";
    cin >> add->mark;
    cout << "請輸入要新任務的進度: ";
    cin >> add->progress_rate;
    if (t_current == NULL) {
        cout << "尚未新增任何類別\n";
        add_workType(t_list);
        add->type = *t_list;
    } else if (t_current != NULL) {
        do {
            if (!(fined)) cout << "未在類別類表中\n";
            fined = false;
            t_current = *t_list;
            cout << "請輸入新任務的類別: ";
            cin >> temp;
            while (t_current != NULL) {
                if (t_current->type_name == temp) {
                    fined = true;
                    break;
                }
                t_current = t_current->work_type_next;
            }
        } while (!(fined));
        add->type = t_current;
    }
    if (g_current == NULL) {
        cout << "尚未新增任何小組\n";
        add_group(g_list);
        add->member = *g_list;
    } else if (g_current != NULL) {
        do {
            if (!(fined)) cout << "未在小組類表中\n";
            fined = false;
            g_current = *g_list;
            cout << "請輸入新任務的小組: ";
            cin >> temp;
            while (g_current != NULL) {
                if (g_current->group_name == temp) {
                    fined = true;
                    break;
                }
                g_current = g_current->group_next;
            }
        } while (!(fined));
        add->member = g_current;
    }
    if (*list == NULL) {
        *list = add;
    } else {
        add->work_next = *list;
        *list = add;
    }
}

void free_LK(class work *w_list, class group *g_list, class work_type *t_list) {
    work *wtemp = w_list;
    group *gtemp = g_list;
    member *mtemp = NULL, *m_list = NULL;
    work_type *ttemp = t_list;
    while (w_list != NULL) {
        wtemp = w_list;
        w_list = w_list->work_next;
        free(wtemp);
    }
    while (g_list != NULL) {
        m_list = g_list->list;
        while (m_list != NULL) {
            mtemp = m_list;
            m_list = m_list->member_next;
            free(mtemp);
        }
        gtemp = g_list;
        g_list = g_list->group_next;
        free(gtemp);
    }
    while (t_list != NULL) {
        ttemp = t_list;
        t_list = t_list->work_type_next;
        free(ttemp);
    }
}

void add_member(class member **list) {
    regex puhone_check("^09[0-9]{8}$");
    member *check = *list;
    string add_ID;
    bool inMember = false;
    do {
        if (inMember) cout << "組員重複\n";
        inMember = false;
        check = *list;
        cout << "請輸入要新增的組員ＩＤ(若不繼續新增請輸入 -1 ): ";
        cin >> add_ID;
        if (add_ID != "-1") {
            member *add = (member *)malloc(sizeof(member));
            while (check != NULL) {
                cout << "已在小組: " << check->ID << endl;
                if (check->ID == add_ID) {
                    inMember = true;
                    break;
                }
                check = check->member_next;
            }
            if (!(inMember)) {
                add->ID = add_ID;
                cout << "請輸入性名: ";
                cin >> add->name;
                do {
                    if (!(regex_match(add->phone_number, puhone_check)) && add->phone_number != "")
                        // if (add->phone_number.length() != 10 && add->phone_number != "")
                        cout << "輸入錯誤請重新輸入\n";
                    cout << "請輸入電話: ";
                    cin >> add->phone_number;
                } // while (add->phone_number.length() != 10);
                while (!(regex_match(add->phone_number, puhone_check)));
                cout << "請輸入角色: ";
                cin >> add->role;
                if (*list != NULL) {
                    add->member_next = *list;
                    *list = add;
                } else {
                    *list = add;
                }
            }
        }
    } while (add_ID != "-1");
}

void del_member(class member **list) {
    member *prev = NULL;
    member *current = *list;
    bool fined = false;
    int func = 1;
    string del_temp;
    do {
        prev = NULL;
        current = *list;
        fined = false;
        cout << "請選擇 1)以成員ID刪除 2)以成員姓名刪除 -1)退出: ";
        cin >> func;
        switch (func) {
        case 1:
            cout << "請輸入要刪除的ID: ";
            cin >> del_temp;
            if (*list != NULL) {
                while (current != NULL) {
                    if (current->ID == del_temp) {
                        fined = true;
                        break;
                    }
                    prev = current;
                    current = current->member_next;
                }

                if (fined) {
                    if (prev != NULL) {
                        prev->member_next = current->member_next;
                        free(current);
                    } else {
                        cout << "del_head\n";
                        *list = current->member_next;
                        free(current);
                    }
                } else {
                    cout << "未找到輸入的ID\n";
                }
            } else {
                cout << "尚未新增任何成員\n";
            }
            break;
        case 2:
            cout << "請輸入要刪除姓名: ";
            cin >> del_temp;
            if (*list != NULL) {
                while (current != NULL) {
                    if (current->name == del_temp) {
                        fined = true;
                        break;
                    }
                    prev = current;
                    current = current->member_next;
                }

                if (fined) {
                    if (prev != NULL) {
                        prev->member_next = current->member_next;
                        free(current);
                    } else {
                        *list = current->member_next;
                        free(current);
                    }
                } else {
                    cout << "未找到輸入的姓名\n";
                }
            } else {
                cout << "尚未新增任何成員\n";
            }
            break;
        case -1:
            break;
        default:
            cout << "輸入錯誤請重新輸入\n";
            break;
        }
    } while (func != -1);
}

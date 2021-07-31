#include <iostream>
#include <ctime>

using namespace std;
int main() {
    int mon,day,n = 0;
    cin >> n;
    int eday[n-1];
    for(int i =0;i<n;i++){
        cin >> mon >> day;
        struct tm begin;
        begin.tm_year = 2011;
        begin.tm_mon = mon-1;
        begin.tm_mday = day-1;
        begin.tm_isdst = -1;
        time_t ends = mktime(&begin);
        struct tm * end = localtime(&ends);
        eday[i] = end->tm_wday;
    }
    for(int i=0;i<n;i++){
        if(eday[i] == 0){cout << "Sunday" << endl;}
        if(eday[i] == 1){cout << "Monday" << endl;}
        if(eday[i] == 2){cout << "Tuesday" << endl;}
        if(eday[i] == 3){cout << "Wednesday" << endl;}
        if(eday[i] == 4){cout << "Thursday" << endl;}
        if(eday[i] == 5){cout << "Friday" << endl;}
        if(eday[i] == 6){cout << "Saturday" << endl;}
        }

    return 0;
}

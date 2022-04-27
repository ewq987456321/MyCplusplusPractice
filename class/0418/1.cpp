#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    string str;
    char *num = new char,*temp;
    while(getline(cin,str)){
        num =(char *) str.c_str();
        long size=0;
        long double total=0;
        long double average=0;

        //  cin.getline(num,5000);
        if((temp = strtok(num," ")) != NULL){
            size += 1;
            total += atoi(temp);
        }
        while((temp = strtok(NULL," ")) != NULL){
            size += 1;
            total += atoi(temp);
        }
        average = total / size;
        cout << "Size: " << size << endl;
        cout.width(4);
        cout.fill('0');
        cout << "Average: " << fixed  << setprecision(3) << average << endl;
    }
    return 0;
}
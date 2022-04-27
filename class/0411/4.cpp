#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    long int count=0,add = 0;
    long double total=0.0;
    long double rate = 0;
    cin >> rate >> count >> add;
    for(int i=0;i<count;i++){
        total += add;
        total += total * rate;
    }
    cout << setprecision(12) << (long int)(total) << endl;
}
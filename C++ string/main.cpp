#include <iostream>
#include <string> // C++字串標頭黨

using namespace std;
int main() {
    string s1 = "hello"; //宣告string 類別
    string * s2 = new string("world"); // string 指標宣告
    cout << s1 << " " << *s2 << endl;
    char c1 = s1.at(0); // at(int) 取得字串位「字元」
    char c2 = s2->at(0); //物件「.」呼叫成員函數，指標「->」呼叫成員函數
    cout << c1 << " " << c2 << endl;
    cout << s1[0] << " " << (*s2)[0] << endl;
    return 0;
}

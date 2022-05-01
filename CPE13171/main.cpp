#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(){
    int num;
    cin >> num;
    map <char, string> colorPair{
        {'M', "100"},
        {'Y', "001"},
        {'C', "010"},
        {'R', "101"},
        {'B', "111"},
        {'G', "011"},
        {'V', "110"},
        {'W', "000"}
    };
    for(int l = 0; l < num; l++){
        int M,C,Y;
        string color, temp;
        cin >> M >> Y >> C >> color;
        for(unsigned long long i = 0; i < color.length(); i++){
            M -= (colorPair[color[i]][0] - '0');
            C -= (colorPair[color[i]][1] - '0');
            Y -= (colorPair[color[i]][2] - '0');
            //cout << "YES " << M << " " << Y << " " << C << endl;
        }
        if(M >= 0 && C >= 0 && Y >= 0)
            cout << "YES " << M << " " << Y << " " << C << endl;
        else
            cout << "NO" << endl;
    }
}

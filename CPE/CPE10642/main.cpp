#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    for(int l = 0;l<num;l++){
        int x1,y1,x2,y2;
        int SbaseX = 0, SbaseY = 0, EbaseX = 0, EbaseY = 0;
        long long stepS,stepE;
        cin >> x1 >> y1 >> x2 >> y2;
        SbaseY = x1 + y1;
        EbaseY = x2 + y2;
        stepS = (SbaseY * 2) - 1;
        stepE = (EbaseY * 2) - 1;
        if(SbaseY > 2){
            for(int i = SbaseY - 2; i > 0; i--){
                stepS += i;
            }
        }
        if(EbaseY > 2){
            for(int i = EbaseY - 2; i > 0; i--){
                stepE += i;
            }
        }
        if(SbaseY == 0)
            stepS = 0;
        if(EbaseY == 0)
            stepE = 0;
        //cout << stepS << " " << stepE << "\n";
        while(SbaseX != x1 && SbaseY != y1){
            SbaseX += 1;
            SbaseY -= 1;
            stepS += 1;
        }
        while(EbaseX != x2 && EbaseY != y2){
            EbaseX += 1;
            EbaseY += 1;
            stepE += 1;
        }
        //cout << stepS << " " << stepE << "\n";
        cout << "Case " << l+1 << ": " << abs(stepS - stepE) << endl;
    }
}

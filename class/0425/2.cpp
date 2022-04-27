#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>


int main(){
    srand(time(NULL));
    int num=1;
    int count[55]={0};
    do{
        printf("請輸入要多少個字元：");
        scanf("%d",&num);
    }while(num<=0);
    char *arr = (char*)malloc(sizeof(char)*num);
    for(int i =0;i<num;i++){
        int temp = rand()%5;
        switch(temp){
            case 0:
                arr[i] = rand()%26+'a';
                count[arr[i]-97+26]++;
                break;
            case 1:
                arr[i] = rand()%26+'A';
                count[arr[i]-65]++;
                break;
            case 2:
                if((rand()%26)==1){
                    arr[i] = ' ';
                    count[52]++;
                }
                else{
                    i--;
                }
                break;
            case 3:
                if((rand()%26)==1){
                    arr[i] = '.';
                    count[53]++;
                }
                else{
                    i--;
                }
                break;
            case 4:
                if((rand()%26)==1){
                    arr[i] = ',';
                    count[54]++;
                }
                else{
                    i--;
                }
                break;
        }
    }
    for(int i =0;i<55;i++){
        if(count[i]!=0){
            if(i<26){
                std::cout <<(char)(i+65) <<count[i] <<std::endl;
            }
            else if(i>26 && i<52){
                std::cout << (char)(i+97-26) <<count[i] <<std::endl;
            }
            else{
                if(i == 52)
                    std::cout << " " << count[i] <<std::endl;
                if(i==53)
                    std::cout << "." << count[i] <<std::endl;
                if(i==54)
                    std::cout << "," << count[i] <<std::endl;
            }
        }
    }
    std::cout << "原始：" << arr;
}

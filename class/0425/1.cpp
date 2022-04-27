#include <cstdio>
#include <cstdlib>

struct Direction{
    float x = 0;
    float y = 0;
};

int main(){
    int num=1,x=0,y=0;
    do{
        if(num <=0)
            printf("數項需大於0!\n");
        printf("請輸入要存多少個向量： ");
        scanf("%d",&num);
    }while(num<=0);
    Direction *dr = (Direction *)malloc(num*sizeof(Direction));
    for(int i =0;i<num;i++){
        printf("請輸入向量： ");
        scanf("%f%f",&dr[i].x,&dr[i].y);
        x += dr[i].x;
        y += dr[i].y;
    }
    printf("向量中心為： %f %f\n",(float)x/num,(float)y/num);
}

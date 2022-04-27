#include <stdio.h>

enum Hospital{
    Taipei=1,Dalin,Douliu,Chiayi,Guanshan,Yuli,Hualien,NONE=0
};

enum Department{
    Family_Medicine=1,Orthopedics,Emergency,Chest,Cardiology,Neurology,Pediatrics
};

struct Doctor{
    char ID[11];
    char name[50];
    Hospital hospital[10] = {NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE};
    Department department;
};

int main(){
int func =1;
int choose_hospital,choose_department;
int count_doctor=0;
int count_hospital=0;
Doctor doctor[100];
do{
    printf("Please choose a function you want to do 1)Insert a doctor. 2)Search doctors. -1)exit");
    scanf("%d",&func);
    switch(func){
        case 1:
            printf("請輸入姓名：");
            scanf(" %s",doctor[count_doctor].name);
            printf("請輸入身份證字號：");
            scanf(" %s",doctor[count_doctor].ID);
            printf("請輸入所屬科 1)家醫 2)骨科 3)急診 4)胸腔外科 5)心臟 6)神經 7)小兒科：");
            scanf(" %d",&doctor[count_doctor].department);
            do{
                printf("請輸入所屬醫院 1)台北 2)大林 3)斗六 4)嘉義 5)關山 6)玉里 7)花蓮 -1)結束：");
                scanf(" %d",&choose_hospital);
                int check_same=1;
                for(int i=0;i<=count_doctor;i++){
                    for(int j=0;j<7;j++){
                        if(doctor[i].hospital[j] == choose_hospital && doctor[i].ID == doctor[count_doctor].ID)
                            check_same = 0;
                    }
                }
                if(check_same != 0){
                    Hospital choose_HOSPITAL;
                    switch(choose_hospital){
                        case 1:
                            choose_HOSPITAL = Taipei;
                            break;
                        case 2:
                            choose_HOSPITAL = Dalin;
                            break;
                        case 3:
                            choose_HOSPITAL = Douliu;
                            break;
                        case 4:
                            choose_HOSPITAL = Chiayi;
                            break;
                        case 5:
                            choose_HOSPITAL = Guanshan;
                            break;
                        case 6:
                            choose_HOSPITAL = Yuli;
                            break;
                        case 7:
                            choose_HOSPITAL = Hualien;
                            break;
                    }
                    doctor[count_doctor].hospital[count_hospital] = choose_HOSPITAL;
                    count_hospital += 1;
                }
                else{
                    printf("輸入重複\n");
                }
            }while(choose_hospital != -1);
            count_doctor += 1;
            count_hospital =0;
            break;
        case 2:
            printf("請輸入所屬科 1)家醫 2)骨科 3)急診 4)胸腔外科 5)心臟 6)神經 7)小兒科：");
            scanf("%d",&choose_department);
            printf("請輸入所屬醫院 1)台北 2)大林 3)斗六 4)嘉義 5)關山 6)玉里 7)花蓮 -1)結束：");
            scanf("%d",&choose_hospital);
            for(int i=0;i<count_doctor;i++){
                if(doctor[i].department == choose_department){
                    for(int j=0;j<7;j++){
                        if(doctor[i].hospital[j] == choose_hospital){
                            printf("%s ",doctor[i].name);
                        }
                    }
                }
            }
            break;
        case -1:
            break;
        default:
            printf("input error!\n");
            break;
    }
}while(func != -1);
}

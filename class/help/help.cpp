#include<stdio.h>
#include<ctype.h>
#include<string.h>
void add(FILE* cfptr) {
 char IDcheck[10 + 5];
 char id[10 + 5];
 int number, Brand, key = 1, checknum[6] = { -1 }, i = 0;
 char brand[50], hospital[100], day[9] = {0}, result, checkday[6][9] = { 0 };
 int idnum[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 }; //建表法
 int  tmp, total = 0,check=0;//含第幾劑、接種日期、疫苗品牌、接種醫院、...等資訊。

 printf("請輸入身分證號:");
 scanf(" %s", id);
 while (check==0){
 if (id[0] <= 'z' && id[0] >= 'a')
 {
  id[0]=toupper(id[0]);
 }
 tmp=idnum[id[0]-'A'];//將英文字轉成數字
 if (id[1]-'0' != 1 && id[1]-'0' != 2)//這邊需要檢查id[1]只能為１ 或２
 {
  printf("輸入錯誤請重輸(id[1]只能為1或2):");
  scanf(" %s", id);
  check = 0;
 }
 else{
  total = (tmp % 10) * 9 + tmp / 10 + (id[1] - '0') * 8 + (id[2] - '0') * 7 + (id[3] - '0') * 6 + (id[4] - '0') * 5 + (id[5] - '0') * 4 + (id[6] - '0') * 3 + (id[7] - '0') * 2 + (id[8] - '0') * 1;
  if (!((10 - total % 10) == (id[9] - '0')) && !((total % 10 == 0) && id[9] == '0'))
  {
   printf("輸入錯誤請重輸");
   scanf(" %s", id);
   check = 0;
  }
  else if (strlen(id) != 10)//這邊需要檢查id[1]只能為１ 或２
  {
   printf("輸入錯誤請重輸:");
   scanf(" %s", id);
   check = 0;
  }
  else {
   check = 1;
  }
 }
 }
 rewind(cfptr);
 fscanf(cfptr, "%d", &key);
 while (!feof(cfptr))
 {
  if (key == 1)
  {
   fscanf(cfptr, "%s %d %s %s %s", IDcheck, &number, day, brand, hospital);
   if (strstr(IDcheck, id) != NULL) {
    checknum[i] = number;
    strcpy(checkday[i], day);
    i++;
   }
  }
  else if (key == 2) {
   fscanf(cfptr, "%s %s %s %s %c", IDcheck, day, brand, hospital, &result);
  }
  fscanf(cfptr, "%d", &key);
 }

 printf("請輸入打第幾劑:");
 scanf(" %d", &number);
 for (int j = 0; j < 6; j++)
 {

  if (checknum[j] == number)
  {
   printf("輸入錯誤，請重輸(此筆資料已輸入過):");
   scanf(" %d", &number);
   j = -1;

  }
  while (number <= 0 || number > 5)
  {
   printf("輸入錯誤，請重輸(目前開放到第五劑):");
   scanf(" %d", &number);
   j = -1;
  }
 }
 printf("請輸入接踵日期(例如:20220418):");
 scanf(" %s", day);
 for (int j = 0; j < 6; j++)
 {
  //printf("%s || %d \n", checkday[j], checknum[j]);
  if (strstr(checkday[j],day)!=NULL)
  {
   printf("輸入錯誤，請重輸(此筆日期已輸入過):");
   scanf(" %s", day);
   j =-1;
  }
  if (strcmp(day, checkday[j]) < 0 && checknum[j] < number)
  {
   printf("輸入錯誤，請重輸:");
   scanf(" %s", day);
   j = -1;

  }
  while (strlen(day) != 8 || (((day[4] - '0') * 10 + (day[5] - '0')) > 13 || ((day[4] - '0') * 10 + (day[5] - '0')) < 1) || (((day[6] - '0') * 10 + (day[7] - '0')) < 1 || ((day[6] - '0') * 10 + (day[7] - '0')) > 31))
  {
   printf("輸入錯誤重輸:");
   scanf(" %s", day);
   j = -1;
  }
 }

 printf("本次打的疫苗是，1)BNT  2)AZ  3)默德納  4)嬌生:");
 scanf(" %d", &Brand);
 while (!(Brand >= 1 && Brand <= 4))
 {
  printf("輸入錯誤，請重輸:");
  scanf(" %d", &Brand);
 }
 if (Brand == 1)
 {
  strcpy(brand, "BNT");
 }
 else if (Brand == 2)
 {
  strcpy(brand, "AZ");
 }
 else if (Brand == 3)
 {
  strcpy(brand, "默德納");
 }
 else if (Brand == 4)
 {
  strcpy(brand, "嬌生");
 }
 printf("施打醫院為:");
 scanf(" %s", hospital);
 key = 1;
 fprintf(cfptr, "%d %s %d %s %s %s\n",key, id, number, day, brand, hospital);
}
void check(FILE* cfptr) {
 char id[10 + 5],IDcheck[10+5];
 int  Brand, key = 2,number,i=0;
 char brand[50], hospital[100], day[50], result='a', checkday[6][9] = {0};
 int  tmp, total = 0, check = 0;
 int idnum[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 }; //建表法
 //含檢驗日期、檢驗種類、檢驗地點、檢驗結果

 printf("請輸入身分證號:");
 scanf(" %s", id);
 while (check == 0) {
  if (id[0] <= 'z' && id[0] >= 'a')
  {
   id[0] = toupper(id[0]);
  }
  tmp = idnum[id[0] - 'A'];//將英文字轉成數字
  if (id[1] - '0' != 1 && id[1] - '0' != 2)//這邊需要檢查id[1]只能為１ 或２
  {
   printf("輸入錯誤請重輸(id[1]只能為1或2):");
   scanf(" %s", id);
   check = 0;
  }
  else {
   total = (tmp % 10) * 9 + tmp / 10 + (id[1] - '0') * 8 + (id[2] - '0') * 7 + (id[3] - '0') * 6 + (id[4] - '0') * 5 + (id[5] - '0') * 4 + (id[6] - '0') * 3 + (id[7] - '0') * 2 + (id[8] - '0') * 1;
   if (!((10 - total % 10) == (id[9] - '0')) && !((total % 10 == 0) && id[9] == '0'))
   {
    printf("輸入錯誤請重輸");
    scanf(" %s", id);
    check = 0;
   }
   else if (strlen(id) != 10)//這邊需要檢查id[1]只能為１ 或２
   {
    printf("輸入錯誤請重輸:");
    scanf(" %s", id);
    check = 0;
   }
   else {
    check = 1;
   }
  }
 }
 rewind(cfptr);
 fscanf(cfptr, "%d", &key);
 while (!feof(cfptr))
 {
  if (key == 1)
  {
   fscanf(cfptr, "%s %d %s %s %s", IDcheck, &number, day, brand, hospital);
  }
  else if (key == 2) {
   fscanf(cfptr, "%s %s %s %s %c", IDcheck, day, brand, hospital, &result);
   if (strstr(IDcheck, id) != NULL) {
    strcpy(&checkday[i][0], day);
    i++;
   }
  }
  fscanf(cfptr, "%d", &key);
 }
 printf("請輸入檢驗日期(例如:20220418):");
 scanf(" %s", day);
 for (int j = 0; j < 6; j++)
 {
  //printf("%s %d", day, strlen(day));
  if (strstr(checkday[j], day) != NULL)
  {
   printf("輸入錯誤，請重輸(此筆日期已輸入過):");
   scanf(" %s", &day);
   j = -1;
  }
  while (strlen(day)!= 8 || (((day[4] - '0') * 10 + (day[5] - '0')) > 13 || ((day[4] - '0') * 10 + (day[5] - '0')) < 1) || (((day[6] - '0') * 10 + (day[7] - '0')) < 1 || ((day[6] - '0') * 10 + (day[7] - '0')) > 31))
  {
   printf("輸入錯誤重輸:");
   scanf(" %s", day);
   j = -1;
  }
 }
 printf("檢驗種類，1)PCR  2)快篩:");
 scanf(" %d", &Brand);
 while (!(Brand >= 1 && Brand <= 2))
 {
  printf("輸入錯誤，請重輸:");
  scanf(" %d", &Brand);
 }
 if (Brand == 1)
 {
  strcpy(brand, "PCR");
 }
 else if (Brand == 2)
 {
  strcpy(brand, "快篩");
 }

 printf("請輸入檢驗地點為:");
 scanf(" %s", hospital);

 printf("請輸入檢驗結果(C / T):");
 scanf(" %c", &result);
 while (result!='c' &&result!='C' && result!='T'&& result!='t')
 {
  printf("輸入錯誤，請重輸:");
  scanf(" %c", &result);
 }
 key = 2;
 fprintf(cfptr, "%d %s %s %s %s %c\n",key, id, day, brand, hospital,result);
}
void search(FILE* cfptr) {

 char id[10 + 5];
 char IDcheck[10 + 5];
 int number, Brand, key = 1, check = 0;;
 char brand[50], hospital[100], day[50] = {0}, result;
 int  tmp, total = 0, idcheck = 0;
 int idnum[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 }; //建表法

 printf("請輸入身分證號:");
 scanf(" %s", id);
 while (idcheck == 0) {
  if (id[0] <= 'z' && id[0] >= 'a')
  {
   id[0] = toupper(id[0]);
  }
  tmp = idnum[id[0] - 'A'];//將英文字轉成數字
  if (id[1] - '0' != 1 && id[1] - '0' != 2)//這邊需要檢查id[1]只能為１ 或２
  {
   printf("輸入錯誤請重輸(id[1]只能為1或2):");
   scanf(" %s", id);
   check = 0;
  }
  else {
   total = (tmp % 10) * 9 + tmp / 10 + (id[1] - '0') * 8 + (id[2] - '0') * 7 + (id[3] - '0') * 6 + (id[4] - '0') * 5 + (id[5] - '0') * 4 + (id[6] - '0') * 3 + (id[7] - '0') * 2 + (id[8] - '0') * 1;
   if (!((10 - total % 10) == (id[9] - '0')) && !((total % 10 == 0) && id[9] == '0'))
   {
    printf("輸入錯誤請重輸");
    scanf(" %s", id);
    idcheck = 0;
   }
   else if (strlen(id) != 10)//這邊需要檢查id[1]只能為１ 或２
   {
    printf("輸入錯誤請重輸:");
    scanf(" %s", id);
    idcheck = 0;
   }
   else {
    idcheck = 1;
   }
  }
 }
 rewind(cfptr);
 fscanf(cfptr, "%d", &key);
 while (!feof(cfptr))
 {
  if (key == 1)
  {
   fscanf(cfptr, "%s %d %s %s %s", IDcheck, &number, day, brand, hospital);
   if (strcmp(IDcheck, id)==0) {
    printf("施打第幾劑:%d   施打日期:%s   施打種類:%s   施打地點:%s\n", number, day, brand, hospital);
    check = 1;
   }
  }
  else if (key == 2) {
   fscanf(cfptr, "%s %s %s %s %c", IDcheck, day, brand, hospital, &result);
   if (strcmp(IDcheck, id) == 0) {
    printf("檢測時間:%s  檢測種類:%s  檢測地點:%s 檢測結果:%c\n", day, brand, hospital, result);
    check = 1;
   }
  }
  fscanf(cfptr, "%d", &key);
 }
 if (check ==0)
 {
  printf("錯誤訊息\n");
 }
}
void all(FILE* cfptr) {
 char id[10 + 5];
 char IDcheck[10 + 5];
 int number, Brand, key = 0, check = 0,checknum=0;
 char brand[50], hospital[100], day[9] = {0}, result;
 FILE* patient;

 if ((patient = fopen("patient.txt", "w+")) == NULL) {
  printf("檔案開檔失敗\n");
 }
 else {
  fprintf(patient, "確診人員身分證號  確診日期  檢測種類  檢測地點\n");
  rewind(cfptr);
  fscanf(cfptr, "%d", &key);
  while (!feof(cfptr))
  {
   if (key == 1)
   {
    fscanf(cfptr, "%s %d %s %s %s", IDcheck, &number, day, brand, hospital);
    //printf("%s %d %s %s %s\n", IDcheck, number, day, brand, hospital);
   }
   else if (key == 2) {
    fscanf(cfptr, "%s %s %s %s %c", IDcheck, day, brand, hospital, &result);
    //printf( "%s %s %s %s %c\n", IDcheck, day, brand, hospital, result);

    if (result=='t'||result=='T'){
     printf("確診人員身分證號:%s  確診日期:%s  施打的疫苗:%s  確診結果:%c\n", IDcheck, day, brand,result);
     fprintf(patient, "%s %s %s %s\n", IDcheck, day, brand,hospital);
     check = 1;
    }
   }
   fscanf(cfptr, "%d", &key);
   //printf("%d", key);
  }
 }
 if (check == 0)
 {
  printf("無確診\n");
 }
 fclose(patient);
}

void deletepeople(FILE* cfptr)
{
 char id[50] = { 0 };
 char IDcheck[50] = { 0 };
 int number, Brand, key = 1, check = 0, checknum = 0,check_key=0;
 char brand[50], hospital[100], day[9], result;
 FILE* patient;
 int  tmp, total = 0, idcheck = 0;
 int idnum[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33 }; //建表法


 if ((patient = fopen("patient.txt", "r+")) == NULL) {
  printf("檔案開檔失敗\n");
 }
 else {
  printf("請輸入身分證號:");
  scanf(" %s", id);
  while (idcheck == 0) {

    if (id[0] <= 'z' && id[0] >= 'a')
   {
    id[0] = toupper(id[0]);
   }
   tmp = idnum[id[0] - 'A'];//將英文字轉成數字
    if (id[1] - '0' != 1 && id[1] - '0' != 2)//這邊需要檢查id[1]只能為１ 或２
   {
    printf("輸入錯誤請重輸(id[1]只能為1或2):");
    scanf(" %s", id);
    idcheck = 0;
   }
   else {
    total = (tmp % 10) * 9 + tmp / 10 + (id[1] - '0') * 8 + (id[2] - '0') * 7 + (id[3] - '0') * 6 + (id[4] - '0') * 5 + (id[5] - '0') * 4 + (id[6] - '0') * 3 + (id[7] - '0') * 2 + (id[8] - '0') * 1;
    if (!((10 - total % 10) == (id[9] - '0')) && !((total % 10 == 0) && id[9] == '0'))
    {
     printf("輸入錯誤請重輸");
     scanf(" %s", id);
     idcheck = 0;
    }
    else if (strlen(id) != 10)
    {
     printf("輸入錯誤請重輸:");
     scanf(" %s", id);
     idcheck = 0;
    }
    else {
     idcheck = 1;
    }
   }
  }
  fprintf(patient, "確診人員身分證號  確診日期  檢測種類  檢測地點\n");
  fscanf(cfptr, "%d", &key);
   while (!feof(cfptr))
  {
   if (key == 1)
   {
    fscanf(cfptr, " %s %d %s %s %s", IDcheck, &number, day, brand, hospital);
   }
   else if (key == 2) {
    fpos_t position;


    fscanf(cfptr, " %s %s %s %s", IDcheck, day, brand, hospital);
    if (strcmp(IDcheck, id) == 0)
    {
     fgetpos(cfptr, &position);//記住要讀result之前的address
     /*fscanf(cfptr, " %c", &result);
     printf(" %c |||\n", result);*/
      result = 'c';
     fsetpos(cfptr, &position);//指標回到result之前的address
     fprintf(cfptr, " %c\n", result);

    /* printf("%c\n", result);
     ch=fprintf(cfptr, " %c", result);
     printf("|||||%d||||||\n", ch);
     i = 1;*/
     fgetpos(cfptr, &position);//記住要讀key之前的address
     fsetpos(cfptr, &position);
     check_key  = 1;
    }
    else {
     fscanf(cfptr, " %c", &result);
    }
   }
   fscanf(cfptr, "%d", &key);
   //printf("%d ||", key);
   //printf("%s %d %s %s %s\n", IDcheck, &number, day, brand, hospital);
  }
 }

 if (check_key != 1)
 {
  printf("輸入錯誤\n");
 }

 fclose(patient);
}
int main()
{
 FILE* cfptr;
 int choose = 0;
   while (choose != -1)
   {
    printf("1) 新增疫苗接種資訊  2) 新增檢驗結果資訊  3) 查詢個人資訊  4) 顯示所有確診人員  5) 刪除確診人員  -1)結束:");
    scanf(" %d", &choose);
    switch (choose)
    {
    case 1:
     cfptr = fopen("hospital.txt", "a+");
     add(cfptr);
     fclose(cfptr);
     break;
    case 2:
     cfptr = fopen("hospital.txt", "a+");
     check(cfptr);
     fclose(cfptr);
     break;
    case 3:
     cfptr = fopen("hospital.txt", "r+");
     search(cfptr);
     fclose(cfptr);
     break;
    case 4:
     cfptr = fopen("hospital.txt", "r+");
     all(cfptr);
     fclose(cfptr);
     break;
    case 5:
     cfptr = fopen("hospital.txt", "r+");
     deletepeople(cfptr);
     fclose(cfptr);
     break;
    case -1:
     break;
    default:
     printf("輸入錯誤\n");
     break;
    }
   }
  return 0;
}

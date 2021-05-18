#include <stdio.h>

struct Datedata {
    int year,month,day;
};
typedef struct Datedata DateData ;
struct BloggerData {
    char ID[13], nickname[21];
    int loginTimes, articles, money;
    DateData lastLogin;
    char gender; char verified, hidden, blacklisted;
};
typedef struct BloggerData bloggerdata ;
void printdata (bloggerdata member[],int i)
{
     printf("[帳號]%-12s[暱稱]%-20s[上站]%7d次[文章]%7d篇\n",member[i].ID,member[i].nickname,member[i].loginTimes,member[i].articles);
     printf("[認證]%-12s[上次] %d 年 %2d 月 %2d 日",member[i].verified?"已經通過認證":"尚未通過認證",member[i].lastLogin.year,member[i].lastLogin.month,member[i].lastLogin.day);
            if (member[i].gender=='B') printf("[性別] 我是帥哥");
            if (member[i].gender=='G') printf("[性別] 我是美女");
            if (member[i].gender=='A') printf("[性別] 我是動物");
            if (member[i].gender=='P') printf("[性別] 我是植物");
            if (member[i].gender=='R') printf("[性別] 我是礦物");
            if (member[i].gender=='U') printf("[性別] 我是未知");
            if (member[i].money<0) printf("[財產] 負債累累\n");
            if (member[i].money>=0 && member[i].money<=999) printf("[財產] 家境清寒\n");
            if (member[i].money>=1000 && member[i].money<=9999) printf("[財產] 家境普通\n");
            if (member[i].money>=10000 && member[i].money<=19999) printf("[財產] 家境小康\n");
            if (member[i].money>=20000 && member[i].money<=29999) printf("[財產] 家境富有\n");
            if (member[i].money>=30000) printf("[財產] 家財萬貫\n");
}
int main()
{
    DateData input;
    int i,step,k; char inputid[13];
    FILE * fp = fopen("data.binary","rb");
    if (fp == NULL) {printf("ERROR!"); return 0;}
    fseek(fp,0,SEEK_END);
    int fsize = ftell(fp);
    rewind(fp);
    int bloggertotal = fsize / sizeof(bloggerdata);
    bloggerdata * member = (bloggerdata*)malloc(fsize);
    fread(member,sizeof(bloggerdata),bloggertotal,fp);fclose(fp);
        printf("開啟 BBS 系統... 請輸入今天日期 (年/月/日)：");
        scanf("%d/%d/%d",&input.year,&input.month,&input.day);
        do {printf("\n【BBS 功\能選單】\n");
        printf("1. 登入\n2. 發表文章\n3. 印出個人資料\n4. 查詢網友資料\n5. 登出\n0. 關閉 BBS 系統\n");
        printf("請選擇動作：");
        scanf("%d",&step); getchar();
        switch (step){
            case 1 :
                printf("請輸入帳號：");
                gets(inputid);
                for(i = 0; i<bloggertotal;i++)
                {
                    if(!strcmp(member[i].ID,inputid))
                    {
                        printf("%s 您好，這是您第 %d 次上站\n",inputid,(member[i].loginTimes)+1);
                        member[i].loginTimes++;
                        member[i].lastLogin.year = input.year;
                        member[i].lastLogin.month = input.month;
                        member[i].lastLogin.day = input.day;
                        k = i;
                    }
                } break;
            case 2 :
                member[k].articles++;
                printf("\n您已發表第 %d 篇文章",member[k].articles);
                break;
            case 3 :
                printdata(member,k);
                break;
            case 4 :
                printf("請輸入帳號：");
                gets(inputid);
                for (i = 0;i<bloggertotal;i++)
                {
                    if(!strcmp(member[i].ID,inputid))
                    {
                        printdata(member,i);
                    }
                }
                break;
            case 5 :
                printf("再見！下次再來玩！\n");
                printf("%s 已登出。",member[k].ID);
                break;
        }
        }while(step!=0);
        if (step==0)
        {
            fp = fopen("data.binary","wb");
            if (fp == NULL) {printf("ERROR!"); return 0;}
            fwrite(member,sizeof(bloggerdata),bloggertotal,fp);
            printf("\n關閉 BBS 系統... OK!");
            fclose(fp);
        }
    return 0 ;
}

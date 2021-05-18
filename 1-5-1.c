#include <stdio.h>
#include <stdlib.h>
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
            if (member[i].money<0) printf("[財產] 負債累累");
            if (member[i].money>=0 && member[i].money<=999) printf("[財產] 家境清寒");
            if (member[i].money>=1000 && member[i].money<=9999) printf("[財產] 家境普通");
            if (member[i].money>=10000 && member[i].money<=19999) printf("[財產] 家境小康");
            if (member[i].money>=20000 && member[i].money<=29999) printf("[財產] 家境富有");
            if (member[i].money>=30000) printf("[財產] 家財萬貫");
}
int main()
{
    int i;
    FILE * fp = fopen("data.binary","rb");
    if (fp == NULL) {printf("ERROR!"); return 0;}
    fseek(fp,0,SEEK_END);
    int fsize = ftell(fp);
    rewind(fp);
    int bloggertotal = fsize / sizeof(bloggerdata);
    bloggerdata * member = (bloggerdata*)malloc(fsize);
    fread(member,sizeof(bloggerdata),bloggertotal,fp);
    fclose(fp);
        for (i = 0 ;i<bloggertotal;i++)
        {
            printdata(member,i);
            printf("\n\n");
        }
    return 0;
}

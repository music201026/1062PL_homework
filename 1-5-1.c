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
     printf("[�b��]%-12s[�ʺ�]%-20s[�W��]%7d��[�峹]%7d�g\n",member[i].ID,member[i].nickname,member[i].loginTimes,member[i].articles);
     printf("[�{��]%-12s[�W��] %d �~ %2d �� %2d ��",member[i].verified?"�w�g�q�L�{��":"�|���q�L�{��",member[i].lastLogin.year,member[i].lastLogin.month,member[i].lastLogin.day);
            if (member[i].gender=='B') printf("[�ʧO] �ڬO�ӭ�");
            if (member[i].gender=='G') printf("[�ʧO] �ڬO���k");
            if (member[i].gender=='A') printf("[�ʧO] �ڬO�ʪ�");
            if (member[i].gender=='P') printf("[�ʧO] �ڬO�Ӫ�");
            if (member[i].gender=='R') printf("[�ʧO] �ڬO�q��");
            if (member[i].gender=='U') printf("[�ʧO] �ڬO����");
            if (member[i].money<0) printf("[�]��] �t�Ųֲ�");
            if (member[i].money>=0 && member[i].money<=999) printf("[�]��] �a�ҲM�H");
            if (member[i].money>=1000 && member[i].money<=9999) printf("[�]��] �a�Ҵ��q");
            if (member[i].money>=10000 && member[i].money<=19999) printf("[�]��] �a�Ҥp�d");
            if (member[i].money>=20000 && member[i].money<=29999) printf("[�]��] �a�ҴI��");
            if (member[i].money>=30000) printf("[�]��] �a�]�U�e");
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

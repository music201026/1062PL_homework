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
     printf("[�b��]%-12s[�ʺ�]%-20s[�W��]%7d��[�峹]%7d�g\n",member[i].ID,member[i].nickname,member[i].loginTimes,member[i].articles);
     printf("[�{��]%-12s[�W��] %d �~ %2d �� %2d ��",member[i].verified?"�w�g�q�L�{��":"�|���q�L�{��",member[i].lastLogin.year,member[i].lastLogin.month,member[i].lastLogin.day);
            if (member[i].gender=='B') printf("[�ʧO] �ڬO�ӭ�");
            if (member[i].gender=='G') printf("[�ʧO] �ڬO���k");
            if (member[i].gender=='A') printf("[�ʧO] �ڬO�ʪ�");
            if (member[i].gender=='P') printf("[�ʧO] �ڬO�Ӫ�");
            if (member[i].gender=='R') printf("[�ʧO] �ڬO�q��");
            if (member[i].gender=='U') printf("[�ʧO] �ڬO����");
            if (member[i].money<0) printf("[�]��] �t�Ųֲ�\n");
            if (member[i].money>=0 && member[i].money<=999) printf("[�]��] �a�ҲM�H\n");
            if (member[i].money>=1000 && member[i].money<=9999) printf("[�]��] �a�Ҵ��q\n");
            if (member[i].money>=10000 && member[i].money<=19999) printf("[�]��] �a�Ҥp�d\n");
            if (member[i].money>=20000 && member[i].money<=29999) printf("[�]��] �a�ҴI��\n");
            if (member[i].money>=30000) printf("[�]��] �a�]�U�e\n");
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
        printf("�}�� BBS �t��... �п�J���Ѥ�� (�~/��/��)�G");
        scanf("%d/%d/%d",&input.year,&input.month,&input.day);
        do {printf("\n�iBBS �\\����j\n");
        printf("1. �n�J\n2. �o��峹\n3. �L�X�ӤH���\n4. �d�ߺ��͸��\n5. �n�X\n0. ���� BBS �t��\n");
        printf("�п�ܰʧ@�G");
        scanf("%d",&step); getchar();
        switch (step){
            case 1 :
                printf("�п�J�b���G");
                gets(inputid);
                for(i = 0; i<bloggertotal;i++)
                {
                    if(!strcmp(member[i].ID,inputid))
                    {
                        printf("%s �z�n�A�o�O�z�� %d ���W��\n",inputid,(member[i].loginTimes)+1);
                        member[i].loginTimes++;
                        member[i].lastLogin.year = input.year;
                        member[i].lastLogin.month = input.month;
                        member[i].lastLogin.day = input.day;
                        k = i;
                    }
                } break;
            case 2 :
                member[k].articles++;
                printf("\n�z�w�o��� %d �g�峹",member[k].articles);
                break;
            case 3 :
                printdata(member,k);
                break;
            case 4 :
                printf("�п�J�b���G");
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
                printf("�A���I�U���A�Ӫ��I\n");
                printf("%s �w�n�X�C",member[k].ID);
                break;
        }
        }while(step!=0);
        if (step==0)
        {
            fp = fopen("data.binary","wb");
            if (fp == NULL) {printf("ERROR!"); return 0;}
            fwrite(member,sizeof(bloggerdata),bloggertotal,fp);
            printf("\n���� BBS �t��... OK!");
            fclose(fp);
        }
    return 0 ;
}

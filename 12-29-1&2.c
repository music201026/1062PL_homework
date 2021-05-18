#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IRONHEAD 1
#define WHIRLLEG 2
#define BELLSHIELD 4
#define GHOSTHAND 8
#define LIGHTBODY 16
#define KINGKONGLEG 32
#define LIONROAR 64
#define RULAIPALM 128
struct PlayerData{
    char name[30]; // name of the player
    int level; // level of the player
    char skill; // kongfu records which the player has learned
};
typedef struct PlayerData playerdata;
int main()
{
   playerdata player[100];
   FILE * fptr = fopen("playerdata.txt","r");
   if(fptr== NULL){

        printf("ERROR");
        return 0;
   }
   char*p; int k,times = -1,step,i;
   char buf[1000],inputname[10],inputkung[20];
   while(fgets(buf,sizeof(buf),fptr)!=NULL)
   {
        strtok(buf,"\r\n");
        if (strcmp(buf,"[player]")==0){ times++; player[times].skill = 0;}
        if (strncmp(buf, "name=", strlen("name="))==0)
        {
            p = buf + strlen("name=");
            strcpy(player[times].name , p);
        }
        if (strncmp(buf,"level=",strlen("level="))==0)
        {
            p = buf + strlen("level=");
            k = atoi(p);
            player[times].level = k;
        }

        if (strncmp(buf,"skill=",strlen("skill="))==0)
        {
                p = buf + strlen("skill=");
                if (!strcmp(p,"�K�Y�\\")) player[times].skill =  player[times].skill | IRONHEAD ;
                if (!strcmp(p,"�ۭ��a��L"))player[times].skill =  player[times].skill | WHIRLLEG ;
                if (!strcmp(p,"�����n�K���m")) player[times].skill =  player[times].skill | BELLSHIELD ;
                if (!strcmp(p,"���v�ள��")) player[times].skill =  player[times].skill | GHOSTHAND ;
                if (!strcmp(p,"���\\���W��")) player[times].skill =  player[times].skill | LIGHTBODY ;
                if (!strcmp(p,"�j�O����L")) player[times].skill =  player[times].skill | KINGKONGLEG ;
                if (!strcmp(p,"��l�q")) player[times].skill = player[times].skill | LIONROAR;
                if (!strcmp(p,"�p�ӯ��x")) player[times].skill =  player[times].skill | RULAIPALM ;
        }
   }
        do{
        printf("1. �x�s�s�Ƿ|�\\��\n");
        printf("2. �d�ߪ��a�Ƿ|���\\��\n");
        printf("3. �d�߾Ƿ|�\\�Ҥ����a\n");
        printf("4. ���}\n");
        //printf("%c",player[0].skill);
        printf("�п�J�ʧ@�G");
        scanf("%d",&step); getchar();
        switch(step)
        {
            case 1 :
                printf("\n�п�J���a�G");
                gets(inputname);
                printf("�п�J�\\�ҡG");
                gets(inputkung);
                for (i = 0;i<times;i++)
                {
                    if (strcmp(inputname,player[i].name)==0)
                    {
                        if (!strcmp(inputkung,"�K�Y�\\")) player[i].skill =  player[i].skill | IRONHEAD ;
                        if (!strcmp(inputkung,"�ۭ��a��L")) player[i].skill =  player[i].skill | WHIRLLEG ;
                        if (!strcmp(inputkung,"�����n�K���m")) player[i].skill =  player[i].skill | BELLSHIELD ;
                        if (!strcmp(inputkung,"���v�ள��")) player[i].skill =  player[i].skill | GHOSTHAND ;
                        if (!strcmp(inputkung,"���\\���W��")) player[i].skill =  player[i].skill | LIGHTBODY ;
                        if (!strcmp(inputkung,"�j�O����L")) player[i].skill =  player[i].skill | KINGKONGLEG ;
                        if (!strcmp(inputkung,"��l�q")) player[i].skill = player[i].skill | LIONROAR;
                        if (!strcmp(inputkung,"�p�ӯ��x")) player[i].skill =  player[i].skill | RULAIPALM ;
                    }
                }
                printf("�x�s%s�Ƿ|%s���\\\n",inputname,inputkung);
                break;
            case 2 :
                printf("\n�п�J���a�G");
                gets(inputname);
                for (i = 0;i<times;i++)
                {
                    if (strcmp(inputname,player[i].name)==0)
                    {
                        printf("Name: %s\n",player[i].name);
                        printf("Level: %d\n",player[i].level);
                        printf("Skills:\n");
                        if (player[i].skill&IRONHEAD) printf("     �K�Y�\\\n");
                        if ((player[i].skill&WHIRLLEG)==WHIRLLEG) printf("     �ۭ��a��L\n");
                        if ((player[i].skill&BELLSHIELD)==BELLSHIELD) printf("     �����n�K���m\n");
                        if ((player[i].skill&GHOSTHAND)==GHOSTHAND) printf("     ���v�ள��\n");
                        if ((player[i].skill&LIGHTBODY)==LIGHTBODY) printf("     ���\\���W��\n");
                        if ((player[i].skill&KINGKONGLEG)==KINGKONGLEG) printf("     �j�O����L\n");
                        if ((player[i].skill&LIONROAR)==LIONROAR) printf("     ��l�q\n");
                        if ((player[i].skill&RULAIPALM)==RULAIPALM) printf("     �p�ӯ��x\n");
                    }
                }
                break;
            /*case 3:
                printf("�п�J�d�ߪ��\�ҡG");
                gets(inputkung);
                printf("�Ƿ|�o�ǥ\�Ҫ����a���G");
                for (i = 0;i<times;i++)
                {
                    if(player[i].skill&)
                }*/


        }
        }while(step!=4);

   return 0;
}

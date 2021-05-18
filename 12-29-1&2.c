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
                if (!strcmp(p,"鐵頭功\")) player[times].skill =  player[times].skill | IRONHEAD ;
                if (!strcmp(p,"旋風地堂腿"))player[times].skill =  player[times].skill | WHIRLLEG ;
                if (!strcmp(p,"金鐘罩鐵布衫")) player[times].skill =  player[times].skill | BELLSHIELD ;
                if (!strcmp(p,"鬼影擒拿手")) player[times].skill =  player[times].skill | GHOSTHAND ;
                if (!strcmp(p,"輕功\水上飄")) player[times].skill =  player[times].skill | LIGHTBODY ;
                if (!strcmp(p,"大力金剛腿")) player[times].skill =  player[times].skill | KINGKONGLEG ;
                if (!strcmp(p,"獅子吼")) player[times].skill = player[times].skill | LIONROAR;
                if (!strcmp(p,"如來神掌")) player[times].skill =  player[times].skill | RULAIPALM ;
        }
   }
        do{
        printf("1. 儲存新學會功\夫\n");
        printf("2. 查詢玩家學會的功\夫\n");
        printf("3. 查詢學會功\夫之玩家\n");
        printf("4. 離開\n");
        //printf("%c",player[0].skill);
        printf("請輸入動作：");
        scanf("%d",&step); getchar();
        switch(step)
        {
            case 1 :
                printf("\n請輸入玩家：");
                gets(inputname);
                printf("請輸入功\夫：");
                gets(inputkung);
                for (i = 0;i<times;i++)
                {
                    if (strcmp(inputname,player[i].name)==0)
                    {
                        if (!strcmp(inputkung,"鐵頭功\")) player[i].skill =  player[i].skill | IRONHEAD ;
                        if (!strcmp(inputkung,"旋風地堂腿")) player[i].skill =  player[i].skill | WHIRLLEG ;
                        if (!strcmp(inputkung,"金鐘罩鐵布衫")) player[i].skill =  player[i].skill | BELLSHIELD ;
                        if (!strcmp(inputkung,"鬼影擒拿手")) player[i].skill =  player[i].skill | GHOSTHAND ;
                        if (!strcmp(inputkung,"輕功\水上飄")) player[i].skill =  player[i].skill | LIGHTBODY ;
                        if (!strcmp(inputkung,"大力金剛腿")) player[i].skill =  player[i].skill | KINGKONGLEG ;
                        if (!strcmp(inputkung,"獅子吼")) player[i].skill = player[i].skill | LIONROAR;
                        if (!strcmp(inputkung,"如來神掌")) player[i].skill =  player[i].skill | RULAIPALM ;
                    }
                }
                printf("儲存%s學會%s成功\\n",inputname,inputkung);
                break;
            case 2 :
                printf("\n請輸入玩家：");
                gets(inputname);
                for (i = 0;i<times;i++)
                {
                    if (strcmp(inputname,player[i].name)==0)
                    {
                        printf("Name: %s\n",player[i].name);
                        printf("Level: %d\n",player[i].level);
                        printf("Skills:\n");
                        if (player[i].skill&IRONHEAD) printf("     鐵頭功\\n");
                        if ((player[i].skill&WHIRLLEG)==WHIRLLEG) printf("     旋風地堂腿\n");
                        if ((player[i].skill&BELLSHIELD)==BELLSHIELD) printf("     金鐘罩鐵布衫\n");
                        if ((player[i].skill&GHOSTHAND)==GHOSTHAND) printf("     鬼影擒拿手\n");
                        if ((player[i].skill&LIGHTBODY)==LIGHTBODY) printf("     輕功\水上飄\n");
                        if ((player[i].skill&KINGKONGLEG)==KINGKONGLEG) printf("     大力金剛腿\n");
                        if ((player[i].skill&LIONROAR)==LIONROAR) printf("     獅子吼\n");
                        if ((player[i].skill&RULAIPALM)==RULAIPALM) printf("     如來神掌\n");
                    }
                }
                break;
            /*case 3:
                printf("請輸入查詢的功夫：");
                gets(inputkung);
                printf("學會這些功夫的玩家為：");
                for (i = 0;i<times;i++)
                {
                    if(player[i].skill&)
                }*/


        }
        }while(step!=4);

   return 0;
}

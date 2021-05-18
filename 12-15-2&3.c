#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct player
{
    char name[100];
    int exp,health,speed,attack;
};
struct monster
{
     char mon[10];
     int exp,health,speed,attack,proExp;
};
typedef struct player playerdata;
typedef struct monster monsterdata;
void initialplayer(playerdata*p)
{
    printf("請輸入玩家的名字：");
    gets(p->name);
    p->health = (rand()%251)+350;
    p->speed =(rand()%21)+100;
    p->attack = (rand()%21)+40;
    p->exp = 0;
}
void initialmonster(monsterdata*p)
{
    strcpy(p->mon,"半獸人");
    p->health = (rand()%21)+150;
    p->speed = (rand()%16)+35;
    p->attack = (rand()%11)+20;
    p->proExp = 15;
}
void print(playerdata p)
{
    printf("\n%s\n",p.name);
    printf("體力%d,速度%d,攻擊力%d,經驗值%d\n",p.health,p.speed,p.attack,p.exp);
}
void attack_p2m(playerdata *p,monsterdata *m)
{
    printf("草帽小子攻擊，造成半獸人失血 %d 點。\n",p->attack);
    m->health -= p->attack;
}
void attack_m2p(playerdata *p,monsterdata *m)
{
    printf("半獸人攻擊，造成草帽小子失血%d點。\n",m->attack);
    p->health -= m->attack;
}
int main()
{
    playerdata player;
    int monstertotal = 3;
    monsterdata monster[3];
    int i;
    srand ((unsigned int)time(NULL));
    initialplayer(&player);
    for(i = 0;i<3;i++)initialmonster(&monster[i]);
    for (i= 0;i<3;i++)
    {
        print(player);
        printf("\n碰到一隻半獸人!(半獸人體力為%d,速度%d,攻擊力%d)\n",monster[i].health,monster[i].speed,monster[i].attack);
        if(monster[i].speed>player.speed)
            attack_m2p(&player,&monster[i]);
        while(player.health>0&&monster[i].health>0)
        {
            attack_p2m(&player,&monster[i]);
            if(monster[i].health>0)
                attack_m2p(&player,&monster[i]);

            if (player.health<=0)
                printf("%s死了。",player.name);
            else if (monster[i].health<=0)
            {
                printf("半獸人死了。\n");
                player.exp += monster[i].proExp;
                printf("%s獲得經驗值%d。\n",player.name,monster[i].proExp);
            }
        }
    }
    return 0;
}

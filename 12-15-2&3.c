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
    printf("�п�J���a���W�r�G");
    gets(p->name);
    p->health = (rand()%251)+350;
    p->speed =(rand()%21)+100;
    p->attack = (rand()%21)+40;
    p->exp = 0;
}
void initialmonster(monsterdata*p)
{
    strcpy(p->mon,"�b�~�H");
    p->health = (rand()%21)+150;
    p->speed = (rand()%16)+35;
    p->attack = (rand()%11)+20;
    p->proExp = 15;
}
void print(playerdata p)
{
    printf("\n%s\n",p.name);
    printf("��O%d,�t��%d,�����O%d,�g���%d\n",p.health,p.speed,p.attack,p.exp);
}
void attack_p2m(playerdata *p,monsterdata *m)
{
    printf("��U�p�l�����A�y���b�~�H���� %d �I�C\n",p->attack);
    m->health -= p->attack;
}
void attack_m2p(playerdata *p,monsterdata *m)
{
    printf("�b�~�H�����A�y����U�p�l����%d�I�C\n",m->attack);
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
        printf("\n�I��@���b�~�H!(�b�~�H��O��%d,�t��%d,�����O%d)\n",monster[i].health,monster[i].speed,monster[i].attack);
        if(monster[i].speed>player.speed)
            attack_m2p(&player,&monster[i]);
        while(player.health>0&&monster[i].health>0)
        {
            attack_p2m(&player,&monster[i]);
            if(monster[i].health>0)
                attack_m2p(&player,&monster[i]);

            if (player.health<=0)
                printf("%s���F�C",player.name);
            else if (monster[i].health<=0)
            {
                printf("�b�~�H���F�C\n");
                player.exp += monster[i].proExp;
                printf("%s��o�g���%d�C\n",player.name,monster[i].proExp);
            }
        }
    }
    return 0;
}

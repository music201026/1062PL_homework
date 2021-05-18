#include <stdio.h>
#include <string.h>
char * strstrL(char *sent, char *list[], int size)
{
    int i ;
    char*ansp; char*min = NULL;
    for (i = 0;i<size;i++)
    {
        ansp = strstr(sent,list[i]);
        if (ansp!=NULL&&ansp<min||min==NULL) min = ansp;
    }
    return min ;
    ansp = min +1;
}
int main(){
    char sentence1[300] = "英國1名女大生有天掉了提款卡、錢包，沒錢搭車回家，卻遇到1名「街友英雄」要用身上僅剩的3英鎊解救她。";
    char sentence2[300] = "國際油價今年下半年以來，跌幅高達46％，幾近腰斬，但物價仍漲個不停，「回不去了」。";
    int punctTotal = 4;
    char * punct[4] = {"「", "」", "，", "。"};
    int punctLen =strlen(punct[0]);
    char *p;
    p  = strstrL(sentence1,punct,4);
    while(p!=NULL)
    {
        *p = ' ';
        *(p+1) = '\n';
        p  = strstrL(sentence1,punct,4);
    }
    printf("%s",sentence1);
    p = strstrL(sentence2,punct,4);
    while(p!=NULL)
    {
        *p = '*';
        *(p+1) = '*';
        p  = strstrL(sentence2,punct,4);
    }
    printf("\n%s",sentence2);

return 0 ;
}

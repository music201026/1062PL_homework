#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int indexOfList_icmp(char *str, char *list[], int size)
{
    int a,i ;
        for (i = 0;i<size;i++)
        {
            a = stricmp(str,list[i]);
            if (a==0) return i;
        }
        return -1 ;
}
int main()
{
  char document[1000]="National Taiwan Ocean University was originally established in 1953 as a junior college for the study of maritime science and technology.\nAfter eleven years, in 1964, we became a maritime college which offered bachelor's and master's degrees in various fields of maritime studies. During this period, funds for running the college came from the Taiwan Provincial Government of the Republic of China.\nIn 1979 the national government took over the funding and we became the National Maritime College. After another decade, in 1989, the college grew into a full-fledged university, National Taiwan Ocean University (NTOU).";
  char punc[10]=" ,'.()\n";
  char * wordlist[1000],*token;
  int frequency[1000],wtotal = 0,a,i;
    token=strtok(document,punc);
   while(token!=NULL){
        a = indexOfList_icmp(token,wordlist,wtotal);
        if(a!=-1)
        {
            frequency[a]++;
        }
        if(a==-1)
        {
            wordlist[wtotal] = token;
            frequency[wtotal] = 1;
            wtotal++;
        }
        //printf("[%s] length = %d\n",p,strlen(p));
        token=strtok(NULL,punc);
    }
  for (i= 0;i<wtotal;i++) printf("%s %d\n",wordlist[i],frequency[i]);
return 0;
}

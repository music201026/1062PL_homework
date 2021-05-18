#include <stdio.h>
int main (){
char ch; int answer = 0, base;
printf("請輸入進位制：");
scanf("%d",&base); // get base from keyboard
printf("請輸入以該進位制表示的數：");
getchar(); // in order to get rid of the previous new line
    while ( (ch = getchar()) != '\n')
    {
       if(ch>='A'&&ch<='Z')
       {
           if (ch - 'A'+10>=base) break;
           answer = answer*base +(ch-'A'+10);
       }
        if (ch>='a'&&ch<='z')
        {
            if (ch-'a'+10>=base) break;
            answer = answer*base +(ch-'a'+10);
        }
        if (ch>='0'&&ch<='9')
        {
            if (ch-'0'>=base) break;
            answer = answer*base +(ch-'0');
        }
    }
printf("輸入的數以十進位表示則為  ");
printf("%d",answer);
return 0;
}

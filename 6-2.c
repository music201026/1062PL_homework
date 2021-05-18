#include <stdio.h>
int printMonthCalendar(int month, int startday)
{
char * monthname[12] = {"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int i,nowwkdays;
printf("【%s】\n",monthname[month-1]);
printf("日 一 二 三 四 五 六\n");
    for (i = 0 ; i<startday ; i++)
    {
        printf("   ");
    }
    for (i = 1 ;i<=days[month-1];i++)
    {
        printf("%2d ",i);
        if ((i+startday)%7==0) printf("\n");
    }
    printf("\n");
nowwkdays = (i+startday)%7-1;
return nowwkdays;
}
int main () {
int nowwkdays,month,startday;
printf("請問 1 月 1 日是星期幾？(0 表示星期天、1 表示星期一，依此類推) ");
scanf("%d",&startday);
for (month= 0 ;month < 12 ;month++)
{
    startday = printMonthCalendar(month+1,startday);
}

return 0 ;
}


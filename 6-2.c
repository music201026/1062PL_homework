#include <stdio.h>
int printMonthCalendar(int month, int startday)
{
char * monthname[12] = {"�@��","�G��","�T��","�|��","����","����","�C��","�K��","�E��","�Q��","�Q�@��","�Q�G��"};
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int i,nowwkdays;
printf("�i%s�j\n",monthname[month-1]);
printf("�� �@ �G �T �| �� ��\n");
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
printf("�а� 1 �� 1 ��O�P���X�H(0 ��ܬP���ѡB1 ��ܬP���@�A�̦�����) ");
scanf("%d",&startday);
for (month= 0 ;month < 12 ;month++)
{
    startday = printMonthCalendar(month+1,startday);
}

return 0 ;
}


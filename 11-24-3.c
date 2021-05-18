#include <stdio.h>
 void getdate (int *year,int *month ,int *day)
 {      do{
        printf("(輸入格式:西元年/月/日):");
        scanf("%d/%d/%d",year,month,day);
      }while(isInvalidDate(*year, *month, *day));
 }

 int getzodiac(int month,int day)
 {
     int zodiaccode ;
     int beginning[12] = {20,20,21,21,21,22,23,23,23,23,22,22};
     if (day<beginning[month-1]) month = (month+10)%12 +1;
     zodiaccode = (month+9)%12 ;
     return zodiaccode ;
 }

 int main (){
    int matchScore[12][12]={ // matchScore[girl's zodiac][boy's zodiac]
                                90, 75, 82, 47, 94, 65, 85, 70, 99, 58, 88, 79,
                                68, 88, 72, 75, 45, 97, 57, 78, 61, 93, 66, 81,
                                79, 76, 89, 71, 81, 57, 93, 69, 86, 64, 99, 48,
                                52, 82, 78, 89, 61, 84, 66, 92, 70, 87, 74, 97,
                                97, 56, 79, 69, 87, 72, 81, 45, 92, 77, 84, 62,
                                61, 91, 76, 88, 66, 89, 49, 81, 72, 95, 55, 84,
                                85, 74, 98, 58, 88, 77, 90, 71, 80, 47, 95, 64,
                                60, 80, 68, 97, 65, 84, 73, 87, 47, 76, 57, 92,
                                92, 70, 81, 65, 98, 58, 86, 68, 89, 75, 78, 44,
                                43, 97, 70, 80, 59, 92, 51, 85, 64, 88, 74, 77,
                                72, 41, 91, 58, 78, 64, 96, 51, 82, 69, 87, 60,
                                71, 78, 46, 93, 61, 65, 74, 99, 54, 82, 69, 88};
    char * zodiacname[12] = {"牡羊","金牛","雙子","巨蟹","獅子","處女","天秤","天蠍","射手","摩羯","水瓶","雙魚"};
    int boyyear,boymonth,boyday,girlyear,girlmonth,girlday;

    printf("請輸入男生的生日。\n"); getdate(&boyyear,&boymonth,&boyday);
    printf("請輸入女生的生日。\n"); getdate(&girlyear,&girlmonth,&girlday);

    int boycode = getzodiac(boymonth,boyday);
    int girlcode = getzodiac(girlmonth,girlday);

    printf("男生是%s座，女生是%s座。\n",zodiacname[boycode],zodiacname[girlcode]);
    printf("兩人的速配指數是%d!!!\n",matchScore[girlcode][boycode]);
    return 0;
 }
int isLeapYear(int year){
    if (year%400 == 0)
    {
        return 1 ;
    }
    if (year % 4 ==0 && year % 100 !=0)
    {
        return 1 ;
    }
    else {return 0;}
}
int isInvalidDate(int year,int month,int day)
{
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year))
    {
        mon[1]=29;
    }
    if (year<=0 || month<=0 ||day<=0 || day>mon[month-1] || month > 12)
    {
        printf("Not a legal date !\n");
        return 1;
    }
    else return 0;
}


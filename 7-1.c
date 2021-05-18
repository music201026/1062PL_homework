#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int checkPrize(int ticket[], int first[], int special)
{
    int matchnumber = 0,matchspecial = 0 ,prizecode = 0,i,j;
    for (i = 0 ; i<6 ; i++)
    {
        for (j = 0 ; j<6 ;j++)
        {
             if(ticket[i]==first[j]) matchnumber++ ;
        }
        if (ticket[i]==special) matchspecial++ ;
    }
    prizecode = matchnumber*2-4+matchspecial;
    if (matchnumber==3&&matchspecial==0) prizecode = 1;
    if (matchnumber==2) prizecode = 2;

    return prizecode ;

}
void shuffling(int a[], int N )
{
    int i;
    for (i = 0 ; i < N ; i++) a[i] = i;
    while (N!=1)
    {
        int k = rand() % N ;
       // printf("%d\n",k);
        int t = a[k];
        a[k] = a[N-1];
        a[N-1] = t;
        N--;
    }

}


int main() {
    srand ((unsigned int)time(NULL));
    int rightnumber [49],number[6],count,i,j,c,k;
    int prizecode;
    int first[6], ticket[6], special,mynum[6];
    char *prizeName[9] = {"", "General", "Seventh", "Sixth", "Fifth", "Fourth", "Third", "Second", "First"};
    int prize[9] = {0, 400, 400, 1000, 1286,9781,32705,1569878,19100192};
   // for (k = 0 ; k<49 ; k++)printf("%d",rightnumber[k]);
    for (count = 0;count < 5 ; count++)
    {
        shuffling(rightnumber,49);
        for ( i = 0 ; i<6;i++) number[i] = rightnumber[i] ;
        printf("\nThe first-prize numbers are ");
        for ( j = 0 ; j<6;j++) printf("%d ",number[j]+1);
        printf("\n");
        c = rightnumber[6];
        printf("The special number is %d\n",c+1);
        printf("Your ticket numbers are ");
        shuffling(rightnumber,49);
        for (i = 0 ;i<6 ;i++) mynum[i] = rightnumber[i];
        for (j= 0 ;j<6 ;j++) printf("%d ",mynum[j]+1);
        prizecode = checkPrize(mynum,number,c);
        if (prizecode > 0) printf("\nYou have won the %s Prize which is NT$%d!!\n", prizeName[prizecode], prize[prizecode]);
        else printf("\nYou did not win any prize.\n");
    }


    printf("\nInput the first-prize numbers: ");
    for (i = 0; i < 6; i++) scanf("%d",&first[i]);
    printf("Input the special number: ");
    scanf("%d",&special);
    printf("Input the numbers on the lottery ticket: ");
    for (j = 0; j < 6; j++) scanf("%d",&ticket[j]);

    prizecode = checkPrize(ticket,first,special);
    if (prizecode > 0) printf("You have won the %s Prize which is NT$%d!!\n", prizeName[prizecode], prize[prizecode]);
    else printf("You did not win any prize.\n");

    int allwinning = 0,allmoney = 300000,z;
    double ROI ;

    for (z=0 ;z<6000 ;z++)
    {
      shuffling(rightnumber,49);
      for ( i = 0 ;i<6 ;i++)
            number[i] = rightnumber[i] ;
      c = rightnumber[6];
      shuffling(rightnumber,49);
      for (i = 0 ;i<6 ;i++)
            mynum[i] = rightnumber[i];
      prizecode = checkPrize(mynum,number,c);
      if (prizecode<0) prizecode = 0 ;
      allwinning+=prize[prizecode];
    }
    printf("Simulating buying 6000 tickets...\n");
    ROI = allwinning*1.0/allmoney*1.0;
    printf("You spent $300000 and won %d.\n",allwinning);
    printf("ROI is %f",ROI);


    return 0;
}

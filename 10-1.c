#include <stdio.h>
int fa (int m,int n)
{
    if (m==0) return n+1;
    else if (m>0&&n==0) return fa(m-1,1);
    else if (m>0&&n>0) return fa(m-1,fa(m,n-1));
}

int main (){
int i,j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("A(%d, %d) = %d\n",i,j,fa(i,j));
        }
    }


return 0 ;
}

#include <stdio.h>
int fc (int n,int k)
{
    if(k==0) return 1;
    else if (k==n) return 1;
    else return fc(n-1,k-1)+fc(n-1,k);
}

int main () {
int i,j;
    for (i=1;i<=6;i++)
    {
        for (j=0;j<=i;j++)
        {
            printf("C(%d, %d) = %d\n",i,j,fc(i,j));
        }
    }


return 0 ;
}

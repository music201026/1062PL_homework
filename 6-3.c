#include <stdio.h>
#include <math.h>
double myExp(double x,double tolerance)
{
    double sum = 0 ,term1 = 1;
    int k = 1;
    while (term1 > tolerance)
    {
        sum += term1;
        term1 = term1*x/k;
        k++;
    }
    return sum ;
}
double mySine(double x,double tolerance)
{
    double sum = x ,a = x;
    int k = 1;
    while (a > tolerance || (-a)> tolerance)
    {
        a *= -x*x/(k+1)/(k+2);
        sum += a;
        k = k+2;
            }
    return sum ;
}


int main (){
double x,tolerance,i;
printf("�п�J�ƭȡG");
scanf("%lf",&x);
printf("�п�J�e�\�~�t�ȡG");
scanf("%lf",&tolerance);
printf("�п�ܨ禡 [1] exp(x) [2] sin(x)�G");
scanf("%d",&i);
    if (i==1)
    {
        printf("e^%f ~= %.20f\n",x,myExp(x,tolerance));
        printf("e^%f == %.20f\n",x, exp(x));
    }
    else
    {
        printf("sin(%f) ~= %.20f\n",x,mySine(x,tolerance));
        printf("sin(%f) == %.20f\n",x,sin(x));
    }
return 0 ;
}

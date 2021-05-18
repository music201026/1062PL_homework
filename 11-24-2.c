#include <stdio.h>
void strangeFunc(int a[], int size)
{
    int * p = a;
    int * q = a + size ;
        while (p<q)
        {
             if (*p < 0 && *q < 0){
                int t;
                t = *p;
                *p = *q ;
                *q = t ;
                p++; q--;
            }
             if (*p>=0)p++;
             if (*q>=0)q--;

        }
}


void print (int a[],int size)
{
    int i;
    printf("{");

    for (i = 0 ;i < size ;i++) {if (i<=size -1){printf(",");}printf("%d",a[i]);}
    printf("}\n");
}
int main() {
    int a[13] = {65, 0, -5, -22, 9, 231, 43, -7, 11, -65, 0, -18, 65};
    int b[12] = {65, 0, -5, -22, 9, 231, 43, -7, 11, 65, 0, -18};
    int c[12] = {65, 0, 5, 22, 9, 231, 43, 7, 11, 65, 0, 18};

    print(a,13);
    print(b,12);
    print(c,12);

    strangeFunc(a, 13);
    strangeFunc(b,12);
    strangeFunc(c,12);

    printf("\n");

    print(a,13);
    print(b,12);
    print(c,12);

    return 0;
}

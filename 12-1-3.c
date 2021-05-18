#include <stdio.h>
void delSpace(char str[])
{
    char *p; char*q;
    q = str; p =str ;
    while (*q!='\0')q++;
    while(*q=='\0'&&q>=p)
    {
        --q;
        if (*q == ' ')*q = '\0';
    }
    q =str;
    while (*q!='\0'&&*q==' ')
    {
        ++q;
    }
    while (*q!='\0')
    {
        *p  = *q; ++q;
        if (*p==' ') while (*q==' ') ++q;
        ++p;
    }
    *p = '\0';

}
int main() {
    char str1[] = "Test    string    1";
    char str2[] = "   Test string    2   ";
    char str3[] = "    ";
    printf("Before:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);
    delSpace(str1);
    delSpace(str2);
    delSpace(str3);
    printf("\nAfter:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);
    return 0;
}


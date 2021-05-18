#include <stdio.h>
void encrypt(char str1[])
{
    char*p; p = str1;
    while (*p!='\0')
    {
        if (*p>='A'&&*p<='Z') *p = (*p-'A'+2)%26 +'A';
        if (*p>='a'&&*p<='z') *p  = (*p-'a'+2)%26 +'a' ;
        if (*p>='0'&&*p<='9') *p  = (*p -'0'+9)%10 +'0';
        //printf("&&");
        p++;


    }
}


int main() {
    char str1[100] = "A funny guy. @@";
    encrypt(str1);
    //printf("%%%%");
    printf("Encrypted str1: %s\n", str1);
    printf("Input a line: ");
    gets(str1);
    encrypt(str1);
    printf("Encrypted line: %s\n", str1);
    return 0;
}

#include <stdio.h>
#include <string.h>
char * strstrL(char *sent, char *list[], int size)
{
    int i ;
    char*ansp; char*min = NULL;
    for (i = 0;i<size;i++)
    {
        ansp = strstr(sent,list[i]);
        if (ansp!=NULL&&ansp<min||min==NULL) min = ansp;
    }
    return min ;
    ansp = min +1;
}
int main(){
    char sentence1[300] = "�^��1�W�k�j�ͦ��ѱ��F���ڥd�B���]�A�S���f���^�a�A�o�J��1�W�u��ͭ^���v�n�Ψ��W�ȳѪ�3�^��ѱϦo�C";
    char sentence2[300] = "��ڪo�����~�U�b�~�H�ӡA�^�T���F46�H�A�X��y�١A�����������Ӥ����A�u�^���h�F�v�C";
    int punctTotal = 4;
    char * punct[4] = {"�u", "�v", "�A", "�C"};
    int punctLen =strlen(punct[0]);
    char *p;
    p  = strstrL(sentence1,punct,4);
    while(p!=NULL)
    {
        *p = ' ';
        *(p+1) = '\n';
        p  = strstrL(sentence1,punct,4);
    }
    printf("%s",sentence1);
    p = strstrL(sentence2,punct,4);
    while(p!=NULL)
    {
        *p = '*';
        *(p+1) = '*';
        p  = strstrL(sentence2,punct,4);
    }
    printf("\n%s",sentence2);

return 0 ;
}

#include <Stdio.h>
#include <string.h>
int indexOfList(char str[], char *list[], int itemTotal)
{
        int th = 0,a,i ;
        for (i = 0;i<itemTotal;i++)
        {
            a = strcmp(str,list[i]);
            if (a==0) return ++th;
            th++;
        }
        return -1 ;
}
int main (){
    char input[100];
    char leave[10]="quit";
    int n = 1,th;
    int countryTotal = 21;

    char *country[21] = {
        "China",
        "Japan",
        "Korea",
        "India",
        "Indonesia",
        "Malaysia",
        "Singapore",
        "Thailand",
        "Viet Nam",
        "Taiwan",
        "Mexico",
        "Brazil",
        "Canada",
        "USA",
        "the United Kingdom",
        "Italy",
        "Spain",
        "France",
        "Germany",
        "Australia",
        "New Zealand"
    };
    int population[21] = {
	1369436, 126795, 50074, 1295292, 254455,
	29902, 5507, 67726, 92423, 23434, 125386,
	206078, 35588, 319449, 64331, 59789, 46260,
	64121, 80646, 23622, 4495
    };
    printf("Welcome to the World Population Database!");
        while(n>0)
        {
            printf("\nInput a country (input quit to exit): ");
            gets(input);
            int a = strcmp(input,leave);
            if(a==0) break;
            th = indexOfList(input,country,countryTotal);
            if (th==-1)printf("Sorry, we cannot find %s in our database.",input);
            else printf("The population of %s is %d thousands.",input,population[th-1]);
        }
    printf("\nThank you for using World Population Database!");
    return 0;
}



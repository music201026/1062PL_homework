#include <stdio.h>
#define width 10
#define height 5
char maze[2 * height + 1][2 * width + 1];

void intmaze ()
{
    int i,j;
    for (i=0;i<2*height+1;i++)
    {
        for (j=0;j<2*width+1;j++)
        {
            maze[1][0] = ' ';
            maze[1][1] = ' ';
            maze[2 * height -1][2 * width ] = ' ';
            if(i%2!=0 &&j%2!=0) maze[i][j] = '?';
            else maze[i][j] = '#';
        }
    }
}

void printmaze()
{
    int i,j;
    for (i=0;i<2*height+1;i++)
    {
        for (j=0;j<2*width+1;j++)
        {
            printf("%c",maze[i][j]);
            if (j==20)printf("\n");
        }
    }
}
void createmaze (int x,int y)
{
int z = 1,k,a,b,i,count;
    int offsetX[4] = {-2, 2, 0, 0};
    int offsetY[4] = {0, 0, -2, 2};
    while (z>0)
    {
        k = rand()%4;
        count = 0;
        for (i=0;i<4;i++)
        {
            if (maze[x+offsetX[i]][y+offsetY[i]]=='?') count++;
        }
        if (count==0) break;
        if (maze[x+offsetX[k]][y+offsetY[k]]!='?') continue;
        maze[x+offsetX[k]][y+offsetY[k]] = ' ';
        maze[x+offsetX[k]/2][y+offsetY[k]/2] = ' ';
        a = x+offsetX[k];
        b = y+offsetY[k];
        createmaze(a,b);
    }


}
int main (){
srand((unsigned int)time(NULL));
intmaze();
createmaze(1, 1);
printmaze();
return 0;
}

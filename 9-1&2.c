#include <stdio.h>
int board[4][8];

void shuffling(int a[],int N)
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

void gameInit() {
int i,j,a[32];
shuffling(a,32);
    for (i = 0 ; i<4 ; i++)// set every element to 0 by yourself
    {
        for (j = 0 ; j<8 ;j++)
        {
            board[i][j] = -a[i*8+j]-1;
        }
    }
}

void printBoard() {
int i,j;
char * chess[33] ={"  ","卒","卒","卒","卒","卒","包","包","馬","馬","車","車","象","象","士","士","將",
                    "兵","兵","兵","兵","兵","炮","炮","傌","傌","捙","捙","相","相","仕","仕","帥"};
    printf("x\\y 0   1   2   3   4   5   6   7\n");// your first basic problem
    printf(" ┌─┬─┬─┬─┬─┬─┬─┬─┐\n");
    for (i = 0 ;i<4 ; i++)
    {
        printf("%d",i);
        for (j = 0;j<8 ;j++)
        {
            if (board[i][j]<0)printf("│●");
            else printf("│%s",chess[board[i][j]]);
        }
        if (j==8)printf("│\n");
        if (i<3)printf(" ├─┼─┼─┼─┼─┼─┼─┼─┤\n");
    }
    printf(" └─┴─┴─┴─┴─┴─┴─┴─┘\n");

}

int main() {
    // your main function
    srand ((unsigned int)time(NULL));
    int i,j,a,b,c,p=1,f,u;
    int movingX[4] = {-1, 1, 0, 0};
    int movingY[4] = {0, 0, -1, 1};
    gameInit();
    while (p>0)
    {
        printBoard();
        printf("\nNow it's turn for Player 1.");
        printf("Choose a cell (-1 for exit):");
        scanf("%d%d",&a,&b);
            if (board[a][b]<0)
            {
                board[a][b] = board[a][b]*-1;
            }
            else if (board[a][b]==0)continue;
            else
            {
                printf("Move to which direction (0, 1, 2, 3 for up, down, left, and right): ");
                scanf("%d",&c);
                f = a+movingX[c];
                u = b+movingY[c];
                if (a+movingX[c]<0||b+movingY[c]<0||a+movingX[c]>8||b+movingY[c]>8)continue;
                board[f][u] = board[a][b];
                board[a][b] = 0 ;
            }

    }
    return 0;
}

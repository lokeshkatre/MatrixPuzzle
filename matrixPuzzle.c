#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}
void white() {
  printf("\033[0;37m");
}
void purple() {
  printf("\033[0;35m");
}
void green() {
  printf("\033[0;32m");
}

void blue () {
  printf("\033[1;34m");
}
int main()
{
    char name[20];

    int matrix[4][4], arr[16], win[4][4], i, j, num, flag, n,trial=1;
    srand(time(0));
    
    printf("\n\n\nPlayers Name:");
    scanf("%[^\n]s",name);

    system("cls");
    yellow();
    printf("\t\t------");
    red();
    printf("MATRIX PUZZLE");
    yellow();
    printf("------\n");
    blue();
    printf("\n\t\t    RULES OF THE GAME\n");
    green();
    printf("\n1.You can move only 1 step at a time using arrow key");
    white();
    printf("\n\t\t\tMove Up     :  by Up arrow key");
    printf("\n\t\t\tMove Down   :  by Down arrow key");
    printf("\n\t\t\tMove Right  :  by Right arrow key");
    printf("\n\t\t\tMove Left   :  by Left arrow key");
    green();
    printf("\n\n2.You can move number to empty position only");

    printf("\n\n3.For your each valid move your : your total number of moves will decrease by 1");

    printf("\n\n4.Winning situation : Number in 4*4 matrix should be in order from 0 to 15\n");
    white();
    printf("\n\t\t\tWinning situation:\n");
    purple();
    printf("\n\t\t\t---------------------");
    printf("\n\t\t\t|  1 |  2 |  3 |  4 |");
    printf("\n\t\t\t|  5 |  6 |  7 |  8 |");
    printf("\n\t\t\t|  9 | 10 | 11 | 12 |");
    printf("\n\t\t\t| 13 | 14 | 15 |    |");
    printf("\n\t\t\t---------------------");
    green();
    printf("\n\n5.You can exit the game at any time by pressing \'E\' or \'e\'");
    white();
    printf("\n\n\tSo Try to win in minimum number of moves ");
    blue();
    printf("\n\n\t\t\t\tHAPPY GAMING , GOOD LUCK!");
    yellow();
    printf("\nEnter any key to start ");
    getch();
    do{
    n = rand() % 21 + 10;
    for (i = 0; i < 16; i++)
    {
        if (i == 15)
            arr[i] = 32;
        else
            arr[i] = i + 1;
    }
    num = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            win[i][j] = arr[num];
            num++;
        }
    for (i = 0; i < 15; i++)
    {
        int temp = arr[i];
        int randIndex = rand() % 13;
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
    num = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            matrix[i][j] = arr[num];
            num++;
        }

    flag = -1;

    int x = 3, y = 3;
    for (int k = 0; k <=n; k++)
    {
        system("cls");
        blue(); 
        printf("\n\n\t\tPLAYER'S NAME : ");
        green();
        printf("%s ,",name);
        blue();
        printf(" MOVE REMAINING : ");
        green();
        printf("%d",(n-k)/2);
        yellow();
        printf("\n\n\t\t-------------------\n\t\t");
        num = 0;
        for (i = 0; i < 4; i++)
        {
            printf("| ");
            for (j = 0; j < 4; j++)
            {
                if (i == x && j == y)
                    printf("  %c |", matrix[i][j]);
                else
                { if (matrix[i][j] > 9)
                    printf(" %d |", matrix[i][j]);
                else
                    printf("  %d |", matrix[i][j]);
                }
                num++;
            }
            if (num % 4 == 0)
                printf("\n\t\t");
        }
        printf("-----------------\n");
        // checking if current matrix is win matrix or not
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
            {
                if (matrix[i][j] != win[i][j])
                    break;
                else
                    flag = 1;
            }
        char ch = getch();
        white();
        printf("You passed-%d", ch);
        if (ch == 75)
        {
            matrix[x][y] = matrix[x][y - 1];
            matrix[x][y - 1] = 32;
            printf("%d %d", x, y);
            y--;
        }
        else if (ch == 77)
        {
            matrix[x][y] = matrix[x][y + 1];
            matrix[x][y + 1] = 32;
            y++;
        }
        else if (ch == 80)
        {
            matrix[x][y] = matrix[x + 1][y];
            matrix[x + 1][y] = 32;
            x++;
        }
        else if (ch == 72)
        {
            matrix[x][y] = matrix[x - 1][y];
            matrix[x - 1][y] = 32;
            x--;
        }
        if (ch == 69 || ch == 101)
        {
            return 0;
        }
    }
    trial--;
    system("cls");
    if(flag==1)
    {
        blue();
        printf("Lokesh , YOU WON THE GAME!");
        printf("\nYOU WON THE GAME BY %d POINTS",n);
        purple();
        printf("\n\nEnter 'y' or 'Y' to continue and 'e' or 'E' for exit");
        char c=getch();
        if(c=='y'||c=='Y')
        trial++;
        else if(c=='e' || c=='E')
        return 0;
    }
    else 
    {
        red();
        printf("Lokesh , YOU LOST THE GAME!");
        purple();
        printf("\n\nEnter 'y' or 'Y' to continue and 'e' or 'E' for exit");
        char c=getch();
        if(c=='y'||c=='Y')
        trial++;
        else if(c=='e' || c=='E')
        return 0;

    }
    }while(trial>0);
 return 0;
}
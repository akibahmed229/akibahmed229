#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int snakewatergun(char you, char com)
{

    if (you == com)
    {
        return 0;
    }
    if (you == 's' && com == 'g')
    {
        return -1;
    }
    else if (you == 'g' && com == 's')
    {
        return 1;
    }
    if (you == 'w' && com == 'g')
    {
        return 1;
    }
    else if (you == 'g' && com == 'w')
    {
        return -1;
    }
    if (you == 'w' && com == 's')
    {
        return -1;
    }
    else if (you == 's' && com == 'w')
    {
        return 1;
    }
    else
    {
        return -2;
    }
}
int main()
{

    int num;
    srand(time(0));
    num = rand() % 100 + 1;

    char you, computer;

    if (num < 33)
    {
        computer = 's';
    }
    else if (num > 33 && num < 66)
    {
        computer = 'w';
    }
    else
    {
        computer = 'g';
    }

    printf("ENTER 's' for snake,'w' for water,'g' for gun \n");
    scanf("%c", &you);

    int result = snakewatergun(you, computer);

    if (result == 1)
    {
        printf("You win!\n");
    }
    else if (result == -1)
    {
        printf("You losse\n");
    }

    else if (result == 0)
    {
        printf("**************Game draw***************\n");
    }

    if (result == -1 || result == 1 || result == 0)
    {

        printf("You Choose %c AND Computer Chosse %c.", you, computer);
    }

    else if (result == -2)
    {
        printf("YOU CHOOSE INVALID OPTION---------->>>  PLEASE TRY AGAIN!!\n");
    }

    return 0;
}
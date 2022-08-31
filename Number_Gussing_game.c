#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int number, guess, nguesses = 1;
    srand(time(0));
    number = rand() % 100 + 1; // generate a random number between 100-200
    // printf("The random number is %d\n", number);

    do
    {
        printf("Guess a number between 1-100\n");
        scanf("%d", &guess);

        if (guess < number)
        {

            printf("Guess a higher number\n");
        }
        else if (number < guess)
        {
            printf("Guess a lower number\n");
        }
        else
        {
            printf("\t\tYour guess Number %d  matched with random Number %d  & you guessed it in %d ATTAMPED!!\n", guess, number, nguesses);
        }
        nguesses++;

    } while (number != guess);

    return 0;
}
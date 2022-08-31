#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Enc(char *c)
{
    char *ptr = c;
    while (*ptr != '\0')
    {
        *ptr = *ptr + 5;
        ptr++;
    }
}
void Dec(char *b)
{
    char *ptr = b;
    while (*ptr != '\0')
    {
        *ptr = *ptr - 5;
        ptr++;
    }
}
int main()
{
    char c[100];
    char b[100];
    char enter,yes = 'y';

    while (yes == 'y')
    {
        int i;
        printf("Enter 1 if you want to encrypte\nEnter 2 if you want to decrypte\n");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
        system("cls");
            printf("Enter thre message you want to encrypte:\t");
            fflush(stdin);
            gets(c);
            Enc(c);
            printf("Encrypted massage is:\t\t\t\t%s\n", c);
            break;
        case 2:
        system("cls");
            printf("Enter thre message you want to decrypte:\t");
            fflush(stdin);
            gets(b);
            Dec(b);
            printf("Decrypted message is:\t\t\t\t%s\n", b);
            break;
        default:
            printf("you choose invalid option");
            break;
        }

        printf("\n\n");
        printf("\t \t \t \t \tDO you want to continue [y/n]:\t");
        scanf("%c", &yes);
        printf("\n\n");

    }
    return 0;
}

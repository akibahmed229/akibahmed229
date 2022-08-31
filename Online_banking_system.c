#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float blance;
} user;

int main()
{
    user usr, user1;
    int opt, choice;
    FILE *fp;
    char filename[50], phone[50], password[50];
    char cont = 'y';
    float amount;

    printf("\nWhat do you want to do?");
    printf("\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d", &opt);

    if (opt == 1)
    {
        system("cls");
        printf("Enter your account number:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your password:\t\t");
        scanf("%s", usr.password);
        usr.blance = 0;
        strcpy(filename, usr.phone);

        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(user), 1, fp);
        if (fwrite != 0)
        {
            printf("\n\nAccount successfully register");
        }
        else
        {
            printf("\n\nSomthing went worng please try again");
        }
        fclose(fp);
    }
    if (opt == 2)
    {
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("\nPassword:\t");
        scanf("%s", password);
        fp = fopen(strcat(phone, ".dat"), "r");

        if (fp == NULL)
        {
            printf("\nAccount number not registered");
        }
        else
        {
            fread(&usr, sizeof(user), 1, fp);
            fclose(fp);
            if (!strcmp(password, usr.password))
            {

                while (cont == 'y')
                {
                    system("cls");

                    printf("\n\t\t\tWelcome %s", usr.phone);
                    printf("\n\n");
                    printf("\nPress 1 for blance inquiry");
                    printf("\nPress 2 for depositing cash");
                    printf("\nPress 3 for cash withdraw");
                    printf("\nPress 4 for online transfer");
                    printf("\npress 5 for change password");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current blance is TK.%.2f", usr.blance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.blance += amount;
                        fp = fopen(phone, "w");
                        fwrite(&usr, sizeof(user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\nSuccessfully Deposited.");
                        }
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f", &amount);
                        usr.blance -= amount;
                        fp = fopen(phone, "w");
                        fwrite(&usr, sizeof(user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\nYou have withdraw Tk.%.f", amount);
                        }
                        fclose(fp);
                        break;
                    case 4:
                        printf("\nPlease Enter the phone number to transfer the blance:\t");
                        scanf("%s", &phone);
                        printf("\nPlease Enter the amount of transfer:\t");
                        scanf("%f", &amount);
                        fflush(stdin);
                        if (amount > usr.blance)
                        {
                            printf("\nInsufficient blance");
                        }
                        else
                        {
                            strcpy(filename, phone);
                            fp = fopen(strcat(phone, ".dat"), "r");
                            if (fp == NULL)
                            {
                                printf("\nphone number is not register");
                            }

                            else
                            {
                                fread(&user1, sizeof(user), 1, fp);
                                fclose(fp);
                                fp = fopen(phone, "w");
                                user1.blance += amount;
                                fwrite(&user1, sizeof(user), 1, fp);
                                fclose(fp);
                                if (fwrite != NULL)
                                {
                                    printf("\nSuccessfully transfer TK.%.2f to %s", amount, usr.phone);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "r");
                                    fread(&usr, sizeof(user), 1, fp);
                                    fclose(fp);
                                    fp = fopen(usr.phone, "w");
                                    usr.blance -= amount;
                                    fwrite(&usr, sizeof(user), 1, fp);
                                    fclose(fp);
                                }
                            }
                        }
                        break;

                    case 5:
                        printf("\nPlease enter your password:\t");
                        scanf("%s", password);
                        strcpy(usr.password, password);
                        fp = fopen(strcat(filename, ".dat"), "r");
                        fread(&usr, sizeof(user), 1, fp);
                        fclose(fp);
                        fp = fopen(phone, "w");
                        fwrite(&usr, sizeof(user), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\nPassword successfully changed");
                        }
                        fclose(fp);
                        break;

                    default:
                        printf("\n\t\tInvalid option");
                    }

                    printf("\n\n");
                    printf("\nDo you want to continue the transaction [y/n]:\t");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("\nInvalid password");
            }
        }
    }
    return 0;
}
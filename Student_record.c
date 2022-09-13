#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

typedef struct user
{
    char user_name[30];
    char user_password[30];

} user;

void account()
{
    user usr;
    FILE *pfp;

    char filename[50];

    printf("\nEnter Your Email:\t");
    scanf("%s", &usr.user_name);

    printf("\nEnter Your Password:\t");
    scanf("%s", &usr.user_password);

    strcpy(filename, usr.user_name);
    pfp = fopen(strcat(filename, ".txt"), "w");
    fwrite(&usr, sizeof(user), 1, pfp);

    if (fwrite != NULL)
    {
        printf("\nAccount successfully register");
    }

    else
    {
        printf("\nSomthing went worng!!!");
    }
    fclose(pfp);
}

typedef struct student
{
    int roll_number;
    char name[20];

    struct subject
    {
        int subject_code;
        char subject_name[20];
        int mark;
    } sub[3];

    int total;
    float percentage;

} student;

void create()
{
    FILE *pfp;

    student *s;  // student
    int n, i, j; // n = number of student, i = each student , j = each student mark;

    printf("\nEnter how many student you want:\t");
    scanf("%d", &n);
    printf("\n\n");

    s = (student *)calloc(n, sizeof(student));
    pfp = fopen("mystudents.txt", "w+");

    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].percentage = 0;

        printf("Enter RollNo:\t");
        scanf("%d", &s[i].roll_number);
        fflush(stdin);

        printf("Enter Name:\t");
        scanf("%[^\n]s", &s[i].name);
        printf("\n");

        for (j = 0; j < 3; j++) // j => 3 becaouse we declare struct subject array => 3
        {
            printf("Enter Marks of Subject%d:\t", j + 1);
            scanf("%d", &s[i].sub[j].mark);

            s[i].total += s[i].sub[j].mark;
        }
        printf("\n");
        s[i].percentage = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, pfp);
    }

    fclose(pfp);
    free(s);
}

void display()
{

    student s1;
    FILE *pfp;
    int j;

    pfp = fopen("mystudents.txt", "r");
    while (fread(&s1, sizeof(student), 1, pfp))
    {
        printf("\n ================= || %-5d%-20s", s1.roll_number, s1.name);
        for (j = 0; j < 3; j++)
        {
            printf("%d |", s1.sub[j].mark);
        }
        printf("%5d%7.2f || =================", s1.total, s1.percentage);
    }

    fclose(pfp);
}

void append()
{
    FILE *pfp;

    student *s;  // student
    int n, i, j; // n = number of student, i = each student , j = each student mark;

    printf("\nEnter how many student you want:\t");
    scanf("%d", &n);
    printf("\n\n");

    s = (student *)calloc(n, sizeof(student));
    pfp = fopen("mystudents.txt", "a"); // "a" = apeend or add new student record in file

    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].percentage = 0;

        printf("Enter RollNo:\t");
        scanf("%d", &s[i].roll_number);
        fflush(stdin);

        printf("Enter Name:\t");
        scanf("%[^\n]s", &s[i].name);
        printf("\n");

        for (j = 0; j < 3; j++) // j => 3 becaouse we declare struct subject array => 3
        {
            printf("Enter Marks of Student %d:\t", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        printf("\n");
        s[i].percentage = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, pfp);
    }

    fclose(pfp);
    free(s);
}

void no_of_record()
{
    student s1;
    FILE *pfp;
    pfp = fopen("mystudents.txt", "r");
    fseek(pfp, 0, SEEK_END);              // it will seek number of  record in file
    int n = ftell(pfp) / sizeof(student); // it will give number of rescord in file n
    printf("\n\nNO OF RECORD = %d", n);
    fclose(pfp);
}

void search()
{
    student s1;
    FILE *pfp;
    int j, rollnum, found = 0;

    printf("Enter RollNo to search:\t");
    scanf("%d", &rollnum);

    pfp = fopen("mystudents.txt", "r");

    while (fread(&s1, sizeof(student), 1, pfp))
    {
        if (s1.roll_number == rollnum)
        {
            found = 1;
            printf("\n%-5d%-20s", s1.roll_number, s1.name);
            for (j = 0; j < 3; j++)
            {

                printf("%d", s1.sub[j].mark);
            }
            printf("%5d%7.2f", s1.total, s1.percentage);
        }
    }

    if (!found)
    {
        printf("\nRecord Not Found\n");
    }
    fclose(pfp);
}

void update()
{
    student s1;
    FILE *pfp;
    FILE *pfp1;
    int j, rollnum, found = 0;

    printf("Enter RollNo to update:\t");
    scanf("%d", &rollnum);

    pfp = fopen("mystudents.txt", "r");
    pfp1 = fopen("temp.txt", "w"); // to update the recored creat a temp file and pass the value of mystudent

    while (fread(&s1, sizeof(student), 1, pfp))
    {
        if (s1.roll_number == rollnum)
        {
            found = 1;
            s1.total = 0;
            s1.percentage = 0;

            fflush(stdin);
            printf("Enter New Name:\t");
            scanf("%[^\n]s", &s1.name);
            printf("\n\n");

            for (j = 0; j < 3; j++) // j => 3 becaouse we declare struct subject array => 3
            {
                printf("Enter New Marks of Subject %d:\t", j + 1);
                scanf("%d", &s1.sub[j].mark);
                s1.total += s1.sub[j].mark;
            }
            printf("\n");
            s1.percentage = s1.total / 3.0;
        }
        fwrite(&s1, sizeof(student), 1, pfp1); // will store mystudent.txt value
    }

    fclose(pfp);
    fclose(pfp1);

    if (found)
    {
        pfp = fopen("mystudents.txt", "w");
        pfp1 = fopen("temp.txt", "r");

        while (fread(&s1, sizeof(student), 1, pfp1)) // while in read mode temp.txt
        {
            fwrite(&s1, sizeof(student), 1, pfp); // it will write  or store updated student details in them main mystudents.txt file
        }
        fclose(pfp);
        fclose(pfp1);
    }

    else
    {
        printf("\nRecord Not Found\n");
    }
}

void delete_record()
{
    student s1;
    FILE *pfp;
    FILE *pfp1;
    int j, rollnum, found = 0;

    printf("Enter RollNo to update:\t");
    scanf("%d", &rollnum);

    // to delete record we have to open file same as Void update
    pfp = fopen("mystudents.txt", "r");
    pfp1 = fopen("temp.txt", "w");

    while (fread(&s1, sizeof(student), 1, pfp))
    {
        if (s1.roll_number == rollnum) // if roll number match given student number
        {
            found = 1;
        }
        else
        {
            fwrite(&s1, sizeof(student), 1, pfp1);
        }
    }

    fclose(pfp);
    fclose(pfp1);

    if (found)
    {
        pfp = fopen("mystudents.txt", "w");

        pfp1 = fopen("temp.txt", "r");

        while (fread(&s1, sizeof(student), 1, pfp1)) // while in read mode temp.txt
        {
            fwrite(&s1, sizeof(student), 1, pfp); // it will write  or store nothin in the mystudents.txt
        }
        fclose(pfp);
        fclose(pfp1);
    }

    else
    {
        printf("\nRecord Not Found\n");
    }
}

void short_total_on_screen()
{

    student *s, s1; // create a initial pointer to get the first student adress
    FILE *pfp;
    pfp = fopen("mystudents.txt", "r");
    fseek(pfp, 0, SEEK_END);
    int n = ftell(pfp) / sizeof(student); // The n size is number of student details has file stored

    s = (student *)calloc(n, sizeof(student)); // creating Dynamic accolation memeory As the number of student details (n) can be updated over time
    rewind(pfp);

    for (int i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, pfp); // open file and read i number student details (n) each time
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].total < s[j].total) //  will compare total for student (i=0 with j= i+1)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1; // j student total will be top
            }
        }
    }

    for (int i = 0; i < n; i++) // it will shot the student buy the avrage higest percentenc
    {
        printf("\n%-5d%-20s", s[i].roll_number, s[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", s[i].sub[j].mark);
        }
        printf("%5d%7.2f", s[i].total, s[i].percentage);
    }

    fclose(pfp);
    free(s);
}

void short_total_in_file()
{
    student *s, s1; // create a initial pointer to get the first student adress
    FILE *pfp;
    pfp = fopen("mystudents.txt", "r");
    fseek(pfp, 0, SEEK_END);
    int n = ftell(pfp) / sizeof(student); // The n size is number of student details has file stored

    s = (student *)calloc(n, sizeof(student)); // creating Dynamic accolation memeory As the number of student details (n) can be updated over time
    rewind(pfp);

    for (int i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, pfp); // open file and read i number student details (n) each time
    }
    fclose(pfp); // closing file
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i].total < s[j].total) //  will compare total for student (i=0 with j= i+1)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1; // j student total will be top
            }
        }
    }

    // after shorting

    pfp = fopen("mystudents.txt", "w");

    for (int i = 0; i < n; i++) // it will shot the student buy the avrage higest percentenc
    {
        printf("\n%-5d%-20s", s[i].roll_number, s[i].name);
        for (int j = 0; j < 3; j++)
        {

            printf("%d ", s[i].sub[j].mark);
        }
        printf("%5d%7.2f", s[i].total, s[i].percentage);
        fwrite(&s[i], sizeof(student), 1, pfp); // short file and save in mystudents.txt file
    }

    fclose(pfp);
    free(s);
}

void short_name_on_screen()
{

    student *s, s1; // create a initial pointer to get the first student adress
    FILE *pfp;
    pfp = fopen("mystudents.txt", "r");
    fseek(pfp, 0, SEEK_END);
    int n = ftell(pfp) / sizeof(student); // The n size is number of student details has file stored

    s = (student *)calloc(n, sizeof(student)); // creating Dynamic accolation memeory As the number of student details (n) can be updated over time
    rewind(pfp);

    for (int i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, pfp); // open file and read i number student details (n) each time
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0) //  will compare name of  student (i=0 with j= i+1)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1; // j student total will be top
            }
        }
    }

    for (int i = 0; i < n; i++) // it will short the student buy the avrage higest percentage
    {
        printf("\n%-5d%-20s", s[i].roll_number, s[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", s[i].sub[j].mark);
        }
        printf("%5d%7.2f", s[i].total, s[i].percentage);
    }

    fclose(pfp);
    free(s);
}

void short_name_on_file()
{

    student *s, s1; // create a initial pointer to get the first student adress
    FILE *pfp;
    pfp = fopen("mystudents.txt", "r");
    fseek(pfp, 0, SEEK_END);
    int n = ftell(pfp) / sizeof(student); // The n size is number of student details has file stored

    s = (student *)calloc(n, sizeof(student)); // creating Dynamic accolation memeory As the number of student details (n) can be updated over time
    rewind(pfp);

    for (int i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, pfp); // open file and read i number student details (n) each time
    }

    fclose(pfp);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0) //  will compare name of  student (i=0 with j= i+1)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1; // j student total will be top
            }
        }
    }

    pfp = fopen("mystudents.txt", "w");

    for (int i = 0; i < n; i++) // it will short the student buy the avrage higest percenteage
    {
        printf("\n%-5d%-20s", s[i].roll_number, s[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", s[i].sub[j].mark);
        }
        printf("%5d%7.2f", s[i].total, s[i].percentage);
        fwrite(&s[i], sizeof(student), 1, pfp);
    }

    fclose(pfp);
    free(s);
}

void delay(int a)
{
    int add, time, i;

    time = a * 1000000;
    for (i = 0; i < time; i++)
    {
        add *= i;
        add++;
        add++;
    }
}

void fordelay()
{
    int i;
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t");
    for (i = 0; i < 3; i++)
    {
        printf("* ");
        delay(100);
    }
    system("cls");
}

int main()
{
    user usr;
    FILE *pfp;
    int choice, first_choice;
    char user_name[50];
    char user_password[50];

    fordelay();
    printf("\n|===============================WELCOME TO LOGIN & SIGN UP PAGE===============================|");
    printf("\n|                                      ****************                                       |");
    printf("\n|                              Software Developed By AKIB AHMED                               |");
    printf("\n|                                                                                             |");
    printf("\n|_____________________________________________________________________________________________|");
    printf("\n\n\n\n");
    printf("\n1.CREATE NEW ACCOUNT");
    printf("\n2.LOGIN INTO ACCOUNT");
    printf("\n0.EXIT");

    printf("\n\nEnter Your Choice:\t");
    scanf("%d", &first_choice);
    if (first_choice == 1)
    // will creat new account
    {
        system("cls");
        printf("\n| ==============================CREATE YOUR ACCOUNT============================== |");
        printf("\n\n");
        account();
    }
    else if (first_choice == 2)
    // will check if the password is worng or right
    {
        system("cls");

        printf("\n| ==============================LOGIN TO ACCESS ALL OF THE FEATURES============================== |");
        printf("\n\n");

        printf("Enter Your Email:\t");
        scanf("%s", &user_name);

        printf("\nEnter Your Password:\t");
        scanf("%s", &user_password);

        pfp = fopen(strcat(user_name, ".txt"), "r");

        if (pfp == NULL)
        {
            printf("\nAccount not register");
        }

        else
        {
            fread(&usr, sizeof(user), 1, pfp);
            fclose(pfp);

            if (!strcmp(user_password, usr.user_password))
            {
                system("cls");

                do
                // if password matched it will exicute the following pogramming
                {
                    printf("\n| ==============================WELCOME TO THE SOFTWARE============================== |");
                    printf("\n|                               Developed By AKIB AHMED                               |");
                    printf("\n|_____________________________________________________________________________________|");
                    printf("\n\n");

                    printf("\n1. CREATE");
                    printf("\n2. DISPLAY");
                    printf("\n3. APPEND");
                    printf("\n4. NO OF RECORDS");
                    printf("\n5. SERCH RECORDS");
                    printf("\n6. UPDATE");
                    printf("\n7. DELETE");
                    printf("\n8. SHORT BY TOTAL DESCENDING - ON SCREEN");
                    printf("\n9. SHORT BY TOTAL DESCENDING - IN SCREEN");
                    printf("\n10. SHORT BY NAME - IN SCREEN");
                    printf("\n11. SHORT BY NAME - IN FILE");
                    printf("\n0. EXIT");

                    printf("\n\nEnter Your Choice:\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================ENTER STUDENT DETAILES============================== |");
                        printf("\n\n");
                        create();
                        break;
                    case 2:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================DISPLAYING STUDENT DETAILES============================== |");
                        printf("\n\n");
                        display();
                        printf("\n\n");
                        break;
                    case 3:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================ADD NEW STUDENT DETEAILSE============================== |");
                        printf("\n\n");
                        append();
                        printf("\n\n");
                        break;
                    case 4:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================DISPLAYING NUMBER OF RECORD HAV BEEN WRITEN============================== |");
                        printf("\n\n");
                        no_of_record();
                        printf("\n\n");
                        break;
                    case 5:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================SEARCHE STUDENT DETAILES============================== |");
                        printf("\n\n");
                        search();
                        printf("\n\n");
                        break;
                    case 6:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================UPDATE STUDENT DETAILES============================== |");
                        printf("\n\n");
                        update();
                        printf("\n\n");
                        break;
                    case 7:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================DELETE STUDENT DETAILES============================== |");
                        printf("\n\n");
                        delete_record();
                        printf("\n\n");
                        break;
                    case 8:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================SHORTING STUDENT DETAILES BY TOTAL IN DISPLAY============================== |");
                        printf("\n\n");
                        short_total_on_screen();
                        printf("\n\n");
                        break;
                    case 9:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================SHORTING STUDENT DETAILES BY TOTAL IN FILE============================== |");
                        printf("\n\n");
                        short_total_in_file();
                        printf("\n\n");
                        break;
                    case 10:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================SHORTING STUDENT DETAILES BY NAME IN DISPLAY============================== |");
                        printf("\n\n");
                        short_name_on_screen();
                        printf("\n\n");
                        break;
                    case 11:
                        system("cls");
                        fordelay();
                        printf("\n| ==============================SHORTING STUDENT DETAILES BY NAME IN DISPLAY============================== |");
                        printf("\n\n");
                        short_name_on_file();
                        printf("\n\n");
                        break;
                    }

                } while (choice != 0);
            }
            else
            {
                printf("\nWorng Password");
            }
        }
    }

    return 0;
}

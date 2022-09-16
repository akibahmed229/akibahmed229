#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;

    cout << "\t\t\t___________________________________________________________________\n\n\n";
    cout << "\t\t\t||                  Welcome to the login page                    ||\n\n\n";
    cout << "\t\t\t______________________________MENUE________________________________\n\n\n";
    cout << "\t\t\t| Press 1 to LOGIN                                                |" << endl;
    cout << "\t\t\t| Press 2 to REGISTER                                             |" << endl;
    cout << "\t\t\t| Press 3 if you forgot your password                             |" << endl;
    cout << "\t\t\t| Press 4 to EXIT                                                 |" << endl;
    cout << "\n\t\t\tPlease enter your choice:\t";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t Thanyou!  \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\tPlease select form options given above \n"
             << endl;
        main();
    }

    return 0;
}

void login()
{
    int count;
    string user_id, password, id, pass;
    system("cls");

    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USER NAME :\t";
    cin >> user_id;
    cout << "\t\t\t PASSWORD :\t";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == user_id && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << user_id << "\n Your Login was successfull \n Thanks for logging in !\n";
        main();
    }
    else
    {
        cout << "\n Login Error \n Please check your username and password\n";
        main();
    }
}

void registration()
{
    string r_userid, r_password, r_id, r_pass;
    system("cls");

    cout << "\t\t\t Enter the username : ";
    cin >> r_userid;
    cout << "\t\t\t Enter the passwprd : ";
    cin >> r_password;

    ofstream f1("records.txt", ios::app);
    f1 << r_userid << " " << r_password << endl;
    f1.close();
    system("cls");
    cout << "\n\t\t\t Registration is seccessfull! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");

    cout << "\t\t\t You forgot the password? No worries \n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter Your choice :";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string s_userid, s_id, s_pass;
        cout << "\n\t\t\t Enter the username which you remember :";
        cin >> s_userid;

        ifstream f2("records.txt");
        while (f2 >> s_id >> s_pass)
        {
            if (s_id == s_userid)
            {
            }
            count = 1;
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your accoundt is found! \n";
            cout << "\n\n Your password is: "
                 << s_pass;
            main();
        }
        else
        {
            cout << "\n\t Sorry! your account is not found! \n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "\t\t\t Worng Choice ! please try again " << endl;
        forgot();
    }
}
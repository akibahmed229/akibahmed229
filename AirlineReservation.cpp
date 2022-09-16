#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

void main_menu(); // Function prototype

class Management
{
public:
    Management()
    {
        main_menu();
    }
};

class Details
{
public:
    static string name, gender, adress;
    int phone_num, age;
    static int customer_id;
    char arr[100];

    void information()
    {
        cout << "Enter the Customer ID:\t";
        cin >> customer_id;
        cout << "Enter the Name:\t";
        cin >> name;
        cout << "Enter the Age:\t";
        cin >> age;
        cout << "Enter the Adress:\t";
        cin >> adress;
        cout << "Gender:\t";
        cin >> gender;
        cout << "Your Detailes are saved" << endl
             << endl
             << endl;
    }
};

int Details::customer_id;
string Details::name;
string Details::gender;
string Details::adress;

class Registration
{
public:
    static int choic;
    int choic1;
    int back;
    static float charges;

    void flights()
    {
        string flightN[] = {"Dubai", "Canada", "UK", "US", "Australia", "Europe"};

        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << ".Flight to:\t"
                 << flightN[i] << endl;
        }
        cout << "\nWelcome to The Airlines!" << endl;
        cout << "\nPress The number of the Country you want to book the Flight:\t";
        cin >> choic;

        switch (choic)
        {
        case 1:
        {
            system("cls");
            cout << "_____________________________Welcome To Dubai Emirates_____________________________\n"
                 << endl;
            cout << "Your comfort is our Priority> Enjoy the journey!" << endl;
            cout << "Following are the Flights\n"
                 << endl;
            cout << "1. DUB -498" << endl;
            cout << "" << (__DATE__) << " 8:00pm"
                 << " 14000.TK" << endl;
            cout << "2. DUB -508" << endl;
            cout << "" << (__DATE__) << " 11:00am"
                 << " 10000.TK" << endl;
            cout << "3. DUB -690" << endl;
            cout << "" << (__DATE__) << " 6:00am"
                 << " 9000.TK" << endl;

            cout << "\nSelect the Flight you want to Book:\t";
            cin >> choic1;

            if (choic1 == 1)
            {
                charges = 14000;
                cout << "\nYou have successfully booked the Flight DUB -498" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 2)
            {
                charges = 10000;
                cout << "\nYou have successfully booked the Flight DUB -508" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 3)
            {
                charges = 9000;
                cout << "\nYou have successfully booked the Flight DUB -690" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else
            {
                cout << "Invalid input ,Shifting to the previous menu" << endl;
                flights();
            }
            cout << "\n\nPress any key to go back Main Menu:\t";
            cin >> back;

            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
            break;
        }
        case 2:
        {
            system("cls");
            cout << "_____________________________Welcome To Canadian Airlines_____________________________\n"
                 << endl;
            cout << "Your comfort is our Priority> Enjoy the journey!" << endl;
            cout << "Following are the Flights\n"
                 << endl;
            cout << "1. CA -102" << endl;
            cout << "" << (__DATE__) << " 8:00pm"
                 << " 34000.TK" << endl;
            cout << "2. CA -201" << endl;
            cout << "" << (__DATE__) << " 11:00am"
                 << " 29000.TK" << endl;
            cout << "3. CA -178" << endl;
            cout << "" << (__DATE__) << " 6:00am"
                 << " 40000.TK" << endl;

            cout << "\nSelect the Flight you want to Book:\t";
            cin >> choic1;

            if (choic1 == 1)
            {
                charges = 34000;
                cout << "\nYou have successfully booked the Flight CA -102" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 2)
            {
                charges = 29000;
                cout << "\nYou have successfully booked the Flight CA -201" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 3)
            {
                charges = 40000;
                cout << "\nYou have successfully booked the Flight CA -178" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else
            {
                cout << "Invalid input ,Shifting to the previous menu" << endl;
                flights();
            }
            cout << "\n\nPress any key to go back Main Menu:\t";
            cin >> back;

            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
            break;
        }
        case 3:
        {
            system("cls");
            cout << "_____________________________Welcome To UK Airlines_____________________________\n"
                 << endl;
            cout << "Your comfort is our Priority> Enjoy the journey!" << endl;
            cout << "Following are the Flights\n"
                 << endl;
            cout << "1. UK -333" << endl;
            cout << "" << (__DATE__) << " 8:00pm"
                 << " 44000.TK" << endl;
            cout << "2. Uk -A47" << endl;
            cout << "" << (__DATE__) << " 11:00am"
                 << " 40000.TK" << endl;

            cout << "\nSelect the Flight you want to Book:\t";
            cin >> choic1;

            if (choic1 == 1)
            {
                charges = 44000;
                cout << "\nYou have successfully booked the Flight UK -333" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 2)
            {
                charges = 40000;
                cout << "\nYou have successfully booked the Flight UK -A47" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else
            {
                cout << "Invalid input ,Shifting to the previous menu" << endl;
                flights();
            }
            cout << "\n\nPress any key to go back Main Menu:\t";
            cin >> back;

            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
            break;
        }
        case 4:
        {
            system("cls");
            cout << "_____________________________Welcome To US Airlines_____________________________\n"
                 << endl;
            cout << "Your comfort is our Priority> Enjoy the journey!" << endl;
            cout << "Following are the Flights\n"
                 << endl;
            cout << "1. US -698" << endl;
            cout << "" << (__DATE__) << " 8:00pm"
                 << " 37000.TK" << endl;
            cout << "2. US -348" << endl;
            cout << "" << (__DATE__) << " 11:00am"
                 << " 39000.TK" << endl;
            cout << "3. US -420" << endl;
            cout << "" << (__DATE__) << " 6:00am"
                 << " 42000.TK" << endl;

            cout << "\nSelect the Flight you want to Book:\t";
            cin >> choic1;

            if (choic1 == 1)
            {
                charges = 37000;
                cout << "\nYou have successfully booked the Flight US -698" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 2)
            {
                charges = 39000;
                cout << "\nYou have successfully booked the Flight US -348" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 3)
            {
                charges = 42000;
                cout << "\nYou have successfully booked the Flight US -420" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else
            {
                cout << "Invalid input ,Shifting to the previous menu" << endl;
                flights();
            }
            cout << "\n\nPress any key to go back Main Menu:\t";
            cin >> back;

            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
            break;
        }
        case 5:
        {
            system("cls");
            cout << "_____________________________Welcome To Australian Airlines_____________________________\n"
                 << endl;
            cout << "Your comfort is our Priority> Enjoy the journey!" << endl;
            cout << "Following are the Flights\n"
                 << endl;
            cout << "1. AUS -798" << endl;
            cout << "" << (__DATE__) << " 8:00pm"
                 << " 44000.TK" << endl;
            cout << "2. AUS -708" << endl;
            cout << "" << (__DATE__) << " 11:00am"
                 << " 340000.TK" << endl;
            cout << "3. AUS -790" << endl;
            cout << "" << (__DATE__) << " 6:00am"
                 << " 42000.TK" << endl;

            cout << "\nSelect the Flight you want to Book:\t";
            cin >> choic1;

            if (choic1 == 1)
            {
                charges = 44000;
                cout << "\nYou have successfully booked the Flight AUS -798" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 2)
            {
                charges = 34000;
                cout << "\nYou have successfully booked the Flight AUS -708" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 3)
            {
                charges = 42000;
                cout << "\nYou have successfully booked the Flight AUS -790" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else
            {
                cout << "Invalid input ,Shifting to the previous menu" << endl;
                flights();
            }
            cout << "\n\nPress any key to go back Main Menu:\t";
            cin >> back;

            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
            break;
        }
        case 6:
        {
            system("cls");
            cout << "_____________________________Welcome To European Airlines_____________________________\n"
                 << endl;
            cout << "Your comfort is our Priority> Enjoy the journey!" << endl;
            cout << "Following are the Flights\n"
                 << endl;
            cout << "1. EU -555" << endl;
            cout << "" << (__DATE__) << " 8:00pm"
                 << " 15000.TK" << endl;
            cout << "2. EU -589" << endl;
            cout << "" << (__DATE__) << " 11:00am"
                 << " 11000.TK" << endl;

            cout << "\nSelect the Flight you want to Book:\t";
            cin >> choic1;

            if (choic1 == 1)
            {
                charges = 15000;
                cout << "\nYou have successfully booked the Flight EU -555" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else if (choic1 == 2)
            {
                charges = 11000;
                cout << "\nYou have successfully booked the Flight EU -589" << endl;
                cout << "You can go back to menu and take the Ticket" << endl;
            }
            else
            {
                cout << "Invalid input ,Shifting to the previous menu" << endl;
                flights();
            }
            cout << "\n\nPress any key to go back Main Menu:\t";
            cin >> back;

            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
            break;
        }
        default:
        {
            cout << "Invalid input, Shifting to Main Menu !" << endl;
            main_menu();
            break;
        }
        }
    }
};

float Registration::charges;
int Registration::choic;

class Ticket : public Registration, public Details
{
public:
    void bill()
    {
        system("cls");
        string destination = "";
        ofstream outf("records.txt");
        {
            outf << "________________________________________Ahmed Airlines__________________________________________" << endl;
            outf << "____________________________________________Ticket______________________________________________" << endl;
            outf << "________________________________________________________________________________________________" << endl;

            outf << "Customer ID:\t\t   " << Details::customer_id << endl;
            outf << "Customer Name:\t\t " << Details::name << endl;
            outf << "Customer Gender:\t " << Details::gender << endl;
            outf << "\n\n\n\tDescription" << endl
                 << endl;
            if (Registration::choic == 1)
            {
                destination = "Dubai";
            }
            else if (Registration::choic == 2)
            {
                destination = "Canada";
            }
            else if (Registration::choic == 3)
            {
                destination = "UK";
            }
            else if (Registration::choic == 4)
            {
                destination = "Us";
            }
            else if (Registration::choic == 5)
            {
                destination = "US";
            }
            else if (Registration::choic == 5)
            {
                destination = "Europe";
            }
            outf << "Destination:\t\t" << destination << endl;
            outf << "Flight cost:\t\t" << Registration::charges << endl;
        }
        outf.close();
    }

    void display()
    {
        ifstream ifs("records.txt");
        {
            if (!ifs)
            {
                cout << "File Error!" << endl;
            }
            while (!ifs.eof())
            {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
};

void main_menu()
{
    int lchoice;
    int schoice;
    int back;
    system("cls");

    cout << "\t                      AHMED AIRLINES\n"
         << endl;
    cout << "__________________________Main Menu_______________________________" << endl;
    cout << "__________________________________________________________________" << endl;
    cout << "\t\t\t\t\t\t" << endl;
    cout << "\t|\t Press 1 to add the Customer Details           \t|" << endl;
    cout << "\t|\t Press 2 for Flight Registration               \t|" << endl;
    cout << "\t|\t Press 3 for Ticket and Charges                \t|" << endl;
    cout << "\t|\t Press 4 to Exit                               \t|" << endl;
    cout << "__________________________________________________________________" << endl;

    cout << "\n\nEnter the Choice:\t";
    cin >> lchoice;

    Details d;
    Registration r;
    Ticket t;

    switch (lchoice)
    {
    case 1:
        system("cls");
        cout << "________________________Customer_________________________________\n"
             << endl;
        d.information();
        cout << "Press any Key to go back to Main Menu:\t";
        cin >> back;
        main_menu();
        break;
    case 2:
        system("cls");
        cout << "______________Book a Flight Using this System_____________________\n"
             << endl;
        r.flights();
        break;
    case 3:
        system("cls");
        cout << "_________________________Get your Ticket__________________________\n"
             << endl;
        t.bill();
        cout << "Your ticket is printed, you can collect it \n"
             << endl;
        cout << "Press 1 to Display Your ticket:\t";
        cin >> back;
        system("cls");

        if (back == 1)
        {
            t.display();
            cout << "Press any key to go back Main Menu:\t";
            cin >> back;
            if (back == 1)
            {
                main_menu();
            }
            else
            {
                main_menu();
            }
        }
        else
        {
            main_menu();
        }
        break;
    case 4:
    {
        cout << "\n\n\t_____________________________Thank You__________________________" << endl;
    }
    break;
    default:
        system("cls");

        {
            cout << "Invalid Input, Please try again\n"
                 << endl;
            main_menu();
        }
        break;
    }
}

int main()
{
    Management Mobj;

    return 0;
}
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class contact
{
private:
    char fName[50], lName[50], adress[50], email[50];
    long long phNo;

public:
    void createContact()
    {
        cout << "Enter your fitst name:   \t";
        cin >> fName;
        cout << "Enter your Last name:    \t";
        cin >> lName;
        cout << "Enter your phone number: \t";
        cin >> phNo;
        cout << "Enter your adress:       \t";
        cin >> adress;
        cout << "Enter your email:        \t";
        cin >> email;
    }

    void showContact()
    {
        cout << "Name:    \t" << fName << " " << lName << endl;
        cout << "Phone:   \t" << phNo << endl;
        cout << "Adress:  \t" << adress << endl;
        cout << "Email:   \t" << email << endl;
    }

    void writeOnFile()
    {
        char ch;
        ofstream f1;                                // writing on file object declearation
        f1.open("CMS.dat", ios::binary | ios::app); // .dat is binary file so opening the file into binary and append mode
        do
        {
            createContact();                                         // callin the createContact function
            f1.write(reinterpret_cast<char *>(this), sizeof(*this)); // writing the input on file & (this)->calling the member data
            cout << "\n\nDo you have next data?[y/n]:\t";
            cin >> ch;
        } while (ch == 'y');

        cout << "\n\nContact has been Successfully Created..." << endl;
        f1.close();
    }

    void readFromFile()
    {
        ifstream f2;                     // reading mode object declearation
        f2.open("CMS.dat", ios::binary); // reading file into binary mode

        cout << "\n=================================================================\n"
             << endl;
        cout << "                        LIST OF CONTACT" << endl;
        cout << "\n=================================================================\n"
             << endl;

        while (!f2.eof()) // until end of file
        {
            if (f2.read(reinterpret_cast<char *>(this), sizeof(*this))) // read from file
            {
                showContact(); // calling the showContact function
                cout << "\n=================================================================\n"
                     << endl;
            }
        }
        f2.close();
    }

    void serchOnFile()
    {
        ifstream f3; // reading mode object declearation
        long long phone;

        cout << "\n=================================================================\n"
             << endl;
        cout << "\n                         SEARCH ON FILE                          " << endl;
        cout << "\n=================================================================\n"
             << endl;
        cout << "Enter Phone NO:\t";
        cin >> phone;

        f3.open("CMS.dat", ios::binary); // open file in binary mode
        while (!f3.eof())                // until end of file
        {
            if (f3.read(reinterpret_cast<char *>(this), sizeof(*this))) // read from file
            {
                if (phone == phNo) // if existing phone number match given phone number
                {
                    showContact(); // calling ShowContact
                    return;
                }
            }
        }
        cout << "\n\nNO record Found!" << endl;
        f3.close();
    }

    void deleteFromFile()
    {
        long long phone;
        int flag = 0;
        ofstream f4; // reading mode object declearation
        ifstream f5; // writing on file object declearation

        f5.open("CMS.dat", ios::binary);  // open binary into reading mode
        f4.open("temp.dat", ios::binary); // open binary into writing mode

        cout << "\n=================================================================\n"
             << endl;
        cout << "\n                         DELETE A FILE                           " << endl;
        cout << "\n=================================================================\n"
             << endl;

        cout << "Enter Phone No to DELETE!:\t";
        cin >> phone;

        while (!f5.eof()) // until end of file
        {
            if (f5.read(reinterpret_cast<char *>(this), sizeof(*this))) // read from CMS file
            {
                if (phNo != phone) // if existing phone number dosn't match given number
                {
                    f4.write(reinterpret_cast<char *>(this), sizeof(*this)); // write on temp file
                }
                else // if the existing phone number match given number
                {
                    // will do nothing mean it will not store match number details
                    flag = 1; // returning flag a value
                }
            }
        }
        f5.close();
        f4.close();

        remove("CMS.dat");             // remove the old CMS file
        rename("temp.dat", "CMS.dat"); // rename tem file into CMS file

        flag == 1 ? cout << "\tContact Deleted..." << endl : cout << "\n\n\tContact Not found..." << endl; // Flag =1, mean contact found else contact not found
    }

    void editContact()
    {
        long long phone;
        fstream f6; // Declearing object for read and write mode at the same time

        cout << "\n=================================================================\n"
             << endl;
        cout << "                            Edit Contact                           " << endl;
        cout << "\n=================================================================\n"
             << endl;
        cout << "\n\nEnter the Phone Number to be Edit:\t";
        cin >> phone;

        f6.open("CMS.dat", ios::binary | ios::out | ios::in); // opening the file in binary,read & write mode
        while (!f6.eof())                                     // until end of file
        {
            if (f6.read(reinterpret_cast<char *>(this), sizeof(*this))) // read from file
            {
                if (phone == phNo) // if existing phone number matched given phone number
                {
                    cout << "\nEnter new record" << endl;
                    createContact(); // calling the creatContact function

                    long long position = -1 * sizeof(*this);                 // to get the position of of current record
                    f6.seekp(position, ios::cur);                            // moving the cursor to the position where we want to record new contact
                    f6.write(reinterpret_cast<char *>(this), sizeof(*this)); // after moving the cursor writing on file new record

                    cout << endl
                         << endl
                         << "\tContact Successfully update..." << endl;
                    return;
                }
            }
        }
        cout << "\n\nNo Record Found" << endl;
        f6.close();
    }
};

int main()
{
    system("cls");
    // color xy,x= backgrounf color, y= text color
    system("Color 3F");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   * WELCOME TO THE CONTACT MANAGEMENT SYSTEM *        " << endl;
    cout << "\n\n\n\t\t\t\t         * ENTER ANY KEY TO CONTINUE *        " << endl;
    getch(); // Pause the screen until the user enter somthing

    while (1)
    {
        contact c1;
        int choice;

        system("cls");
        system("Color 64");

        cout << "\n                    CONRACT MANAGEMENT SYSTEM                    " << endl;
        cout << "\n                            MAIN MENU                            " << endl;
        cout << "\n=================================================================\n"
             << endl;
        cout << "[1] Add a new Contact  " << endl;
        cout << "[2] List of all Contact" << endl;
        cout << "[3] Serch for Contact  " << endl;
        cout << "[4] Delete a Contact   " << endl;
        cout << "[5] Edit a Contact     " << endl;
        cout << "[0] Exit               " << endl;
        cout << "\n=================================================================\n"
             << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            c1.writeOnFile();
            break;
        case 2:
            system("cls");
            c1.readFromFile();
            break;
        case 3:
            system("cls");
            c1.serchOnFile();
            break;
        case 4:
            system("cls");
            c1.deleteFromFile();
            break;
        case 5:
            system("cls");
            c1.editContact();
            break;
        case 0:
            system("cls");
            cout << "\n\n\n\t\t\tThank You For Using Using CMS" << endl
                 << endl;
            exit(0);
            break;
        default:
            continue;
            break;
        }
        int opt;

        cout << "\n\n..::Enter The Choice:\n[1] Main Menu\t\t[0] Exit\n:";
        cin >> opt;

        switch (opt)
        {
        case 0:
            system("cls");
            cout << "\n\n\n\t\t\tThank You For Using Using CMS" << endl
                 << endl;
            exit(0);
            break;

        default:
            continue;
        }
    }
    return 0;
}
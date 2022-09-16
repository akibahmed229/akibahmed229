#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class shopping
{
private:
    int product_code;
    float price;
    float discount;
    string product_name;

public:
    void menu();          // Main menu where all the operation takein
    void administrator(); // Administrator panel only Administrator can login
    void buyer();         // buyer panel where buyer can buy item listed
    void add();           // Will add item by administrator
    void edit();          // Administrator can Edit itme with existing one
    void remove_item();   // Administrator can remove item
    void list();          // List of all item what administrator add to the panel
    void receipt();       // Recipet or the details of product buyer buyed
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    system("cls");
    cout << "\t\t\t__________________________________________________________________\n";
    cout << "\t\t\t                       SuperMarket Main Menu                      \n";
    cout << "\t\t\t                                                                  \n";
    cout << "\t\t\t__________________________________________________________________\n";
    cout << "\t\t\t                                                                  \n";
    cout << "\t\t\t| 1) Administrator              |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| 2) Buyer                      |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t| 3) Exit                       |\n";
    cout << "\t\t\t|                               |\n";
    cout << "\n\t\t\t please select!:\t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "_______________________________________________________________ Please Login_______________________________________________________\n";
        cout << "\n\t\t\t Enter Email:\t";
        cin >> email;
        cout << "\t\t\t Enter password:\t";
        cin >> password;

        if (email == "akib4418@gmail.com" && password == "qwerty")
        {
            administrator();
        }
        else
        {
            cout << "\nInvalid Email/Password";
        }
        break;
    case 2:
        system("cls");
        buyer();
        break;
    case 3:
        system("cls");
        exit(0);
        break;
    default:
        cout << "\nPlease select from the given opetions";
    }
    goto m;
}

void shopping::administrator()
{
m:
    int choice;

    system("cls");
    cout << "\n\n\n\t\t\t Adminastrator Menu";
    cout << "\n\t\t\t|______1) Add The Product_______|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|______2) Modify The product____|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|______3) Delete The product____|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|______4) Back to Main Menu_____|";

    cout << "\n\n\t Please enter your choice:\t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        remove_item();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\nInvalid Choice!";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;

    cout << "\n\t\t\t Buyer Menu \n";
    cout << "\t\t\t_________________\n";
    cout << "\t\t\t 1) Buy Product  \n";
    cout << "                       \n";
    cout << "\t\t\t 2) Go back      \n";

    cout << "\n\n\t\t\t Enter Your Choice:\t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "\nInvalid choice";
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c; // code
    int token = 0;
    float p, d; // price & discount
    string n;   // product name

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\t Product code of the product:\t";
    cin >> product_code;
    cout << "\n\t Name of the product:\t";
    cin >> product_name;
    cout << "\n\t Price of the product:\t";
    cin >> price;
    cout << "\n\t Discount on the product:\t";
    cin >> discount;

    data.open("database.txt", ios::in); // open reading mode
    if (!data)                          // If the File dosn't exist it will create new file and insert data
    {
        data.open("database.txt", ios::app | ios::out); // appand mode and write mode
        data << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
        data.close();
    }
    else // If the file esist then it will insert new data
    {
        data >> c >> n >> p >> d; // initializing index of file
        while (!data.eof())
        {
            if (c == product_code) // Given code == product_code
            {
                token++; // will return token 1
            }
            data >> c >> n >> p >> d; // reading form the file
        }
        data.close();
        if (token == 1)
        {
            goto m; // if the data insert successfull the it will go back again if u wnat to insert any more data
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << product_code << " " << product_name << " " << price << " " << discount << "\n"; // writing to the file
            data.close();
        }
    }
    cout << "\n\n\t\t Record Inserted!";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey; // product key
    int token = 0, c;
    float p, d; // price & discount
    string n;   // name of product

    cout << "\n\t\t\t Modify The Record";
    cout << "\n\t\t\t Product code:\t";
    cin >> pkey;

    data.open("database.txt", ios::in); // open in read mode (old file)
    if (!data)
    {
        cout << "\n\nFile Doesn't Exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);          // Open new file in append & write mode
        data >> product_code >> product_name >> price >> discount; // Initializing the index file (old file)
        while (!data.eof())                                        // while end of file
        {
            if (pkey == product_code) // given product key = existing product key
            {
                cout << "\n\t\t Product new code:\t";
                cin >> c;
                cout << "\n\t\t Name of the product:\t";
                cin >> n;
                cout << "\n\t\t Price:\t";
                cin >> p;
                cout << "\n\t\t Discount:\t";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n"; // Will write new details in the existing file old data
                cout << "\n\n\n\t_____________________________________________RECORD EDITED__________________________________________________";
                token++;
            }
            else // else the file will remain same
            {
                data1 << " " << product_code << " " << product_name << " " << price << " " << discount << "\n";
            }
            data >> product_code >> product_name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");                  // Remove the old file
        rename("database1.txt", "database.txt"); // will insert the new file data into recreated old file
        if (token == 0)
        {
            cout << "\n\n Record Not Found Sorry!";
        }
    }
}

void shopping::remove_item()
{
    fstream data, data1;
    int pkey, token = 0; // product key

    cout << "\n\n\t____________________________++++++DELETE PRODUCT++++++________________________________";
    cout << "\n\t Product code:\t";
    cin >> pkey;
    data.open("database.txt", ios::in); // open file in reading mode (old)
    if (!data)                          // if file dosn't exist
    {
        cout << "File dosn't exist";
    }
    else // if file exist
    {
        data1.open("database1.txt", ios::app | ios::out);          // open file in writing & append mode (new file)
        data >> product_code >> product_name >> price >> discount; // Initializing the index file (old file)
        while (!data.eof())                                        // while end of file it will read data
        {
            if (product_code == pkey) // if entered product key match existing product key
            {
                // will write nothing in the file
                cout << "\n\nProduct deleted successfully";
                token++;
            }
            else // if entered product key dosn't match existing product key
            {
                // File will remain the same
                data1 << " " << product_code << " " << product_name << " " << price << " " << discount;
            }
            data >> product_code >> product_name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");                  // remove old file
        rename("database1.txt", "database.txt"); // will insert the new file data into recreate old file
        if (token == 0)
        {
            cout << "\n\nRecord not found";
        }
    }
}

void shopping::list()
{
    // Will show the list of data added to the database file
    fstream data;

    data.open("database.txt", ios::in); // reading from file
    cout << "\n\n________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n________________________________________________\n";

    data >> product_code >> product_name >> price >> discount;
    while (!data.eof()) // show the data until end of file
    {
        cout << product_code << "\t\t" << product_name << "\t\t" << price << "\n";
        data >> product_code >> product_name >> price >> discount;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100]; // creating array of code
    int arrq[100]; // creating array of quantity
    char choice;
    int c = 0;       // count
    float amount;    // amount of buyed product
    float dis = 0;   // Discount of buyed product
    float total = 0; // Total price of buyed product

    system("cls");
    cout << "\n\n\n\t\t\t RECIEPT ";
    data.open("database.txt", ios::in); // Opening file in reading mode
    if (!data)                          // if data not found
    {
        cout << "\n\n Emty database";
    }
    else // if data found
    {
        data.close();
        list();
        cout << "\n________________________________________\n";
        cout << "\n                                        \n";
        cout << "\n          Please place the order        \n";
        cout << "\n                                        \n";
        cout << "\n________________________________________\n";

        do
        {
        m:
            cout << "\nEnter Product code:\t";
            cin >> arrc[c];
            cout << "\nEnter the Product quantity:\t";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i]) // if array code [count] = array code [i]
                {
                    cout << "\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++; // will add a value every time it run
            cout << "\n\n Do you want to buy another product? if yes then press [y/n]:\t";
            cin >> choice;
        } while (choice == 'y');
        system("cls");

        cout << "\n\n\t\t_____________________________________________RECEIPT___________________________________________________\n";
        cout << "\nProduct No\t\tProduct Name\t\tProduct quantity\t\tPrice\t\tAmount\t\tAmount with Discount\n";

        // Display the data
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);                        // opening file in reading mode
            data >> product_code >> product_name >> price >> discount; // initializating index file
            while (!data.eof())                                        // read until end of file
            {
                if (product_code == arrc[i]) // if existing product code = array_code[count]
                {
                    amount = price * arrq[i];                 // existing price * array_code[count]
                    dis = amount - (amount * discount / 100); // amount - (amount * existing discount / 100)
                    total = total + dis;                      // total * dis
                    cout << "\n"
                         << product_code << "\t\t\t" << product_name << "\t\t\t" << arrq[i] << "\t\t\t\t" << price << "\t\t" << amount << "\t\t\t" << dis; // display the data
                }
                data >> product_code >> product_name >> price >> discount; // initializing the data
            }
            data.close();
        }
    }
    cout << "\n\n\n_________________________________________________________________________________________________________________________________";
    cout << " Total Amount:\t"
         << total << "\n\n\n";
}

int main()
{
    shopping market;
    market.menu();
    return 0;
}
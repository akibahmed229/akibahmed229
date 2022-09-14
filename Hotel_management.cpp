#include <iostream>
using namespace std;

int main()
{
    int quant;
    int choice;
    // quantity
    int qty_rooms = 0, qty_pasta = 0, qty_burger = 0, qty_noodles = 0, qty_chicken = 0, qty_shake = 0;
    // food items sold
    int sold_rooms = 0, sold_pasta = 0, sold_burger = 0, sold_noodles = 0, sold_chicken = 0, sold_shake;
    // total price of item
    int total_rooms = 0, total_pasta = 0, total_burger = 0, total_noodles = 0, total_chicken = 0, total_shake = 0;

    cout << "\n\t Quantity of items we have";
    cout << "\nRooms avaliable:";
    cin >> qty_rooms;
    cout << "\n Quantity of pasta:";
    cin >> qty_pasta;
    cout << "\n Quantity of burger:";
    cin >> qty_burger;
    cout << "\n Quantity of noodels:";
    cin >> qty_noodles;
    cout << "\n Quantity of chicken:";
    cin >> qty_chicken;
    cout << "\n Quantity of shake:";
    cin >> qty_shake;

m:
    cout << "\n\t\t\t Please select from the menu options ";
    cout << "\n\n 1) Rooms";
    cout << "\n 2) Pasta";
    cout << "\n 3) Burger";
    cout << "\n 4) Noodles";
    cout << "\n 5) Shake";
    cout << "\n 6) Chicken";
    cout << "\n 7) Information reagarding sales and collection ";
    cout << "\n 8) Exit";

    cout << "\n\nPlease Enter your choice! ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\n Enter the number of rooms you want: ";
        cin >> quant;
        if (qty_rooms - sold_rooms >= quant)
        {
            sold_rooms = sold_rooms + quant;
            total_rooms = total_rooms + (quant * 1200);
            cout << "\n\n\t\t" << quant << "Rooms have been alloted to you ";
        }
        else
        {
            cout << "\n\t Only " << qty_rooms - sold_rooms << " Rooms reamining in hotel ";
        }
        break;
    case 2:
        cout << "\n\n Enter Pasta Quantity :";
        cin >> quant;
        if (qty_pasta - sold_pasta >= quant)
        {
            sold_pasta = sold_pasta + quant;
            total_pasta = total_pasta + (quant * 250);
            cout << "\n\n\t\t" << quant << " Pasta is the order!";
        }
        else
        {
            cout << "\n\t Only " << qty_pasta - sold_pasta << " Pasta reamining in hotel ";
        }
        break;
    case 3:
        cout << "\n\n Enter Burger Quantity :";
        cin >> quant;
        if (qty_burger - sold_burger >= quant)
        {
            sold_burger = sold_burger + quant;
            total_burger = total_burger + (quant * 120);
            cout << "\n\n\t\t" << quant << " Burger is the order!";
        }
        else
        {
            cout << "\n\t Only " << qty_burger - sold_burger << " Burger reamining in hotel ";
        }
        break;
    case 4:
        cout << "\n\n Enter Noodles Quantity :";
        cin >> quant;
        if (qty_noodles - sold_noodles >= quant)
        {
            sold_noodles = sold_noodles + quant;
            total_noodles = total_noodles + (quant * 140);
            cout << "\n\n\t\t" << quant << " Noodles is the order!";
        }
        else
        {
            cout << "\n\t Only " << qty_noodles - sold_noodles << " Noodles reamining in hotel ";
        }
        break;
    case 5:
        cout << "\n\n Enter Shake Quantity :";
        cin >> quant;
        if (qty_shake - sold_shake >= quant)
        {
            sold_shake = sold_shake + quant;
            total_shake = total_shake + (quant * 120);
            cout << "\n\n\t\t" << quant << " shake is the order!";
        }
        else
        {
            cout << "\n\t Only " << qty_shake - sold_shake << " shake reamining in hotel ";
        }
        break;
    case 6:
        cout << "\n\n Enter Chicken Quantity :";
        cin >> quant;
        if (qty_chicken - sold_chicken >= quant)
        {
            sold_chicken = sold_chicken + quant;
            total_chicken = total_chicken + (quant * 150);
            cout << "\n\n\t\t" << quant << " Chicken is the order!";
        }
        else
        {
            cout << "\n\t Only " << qty_chicken - sold_chicken << " Chicken reamining in hotel ";
        }
        break;
    case 7:
        cout << "\n\tDetails of sales and collection ";
        cout << "\n\n Number of rooms we had : " << qty_rooms;
        cout << "\n\n Number of rooms we gave for rent : " << sold_rooms;
        cout << "\n\n Reamining rooms : " << qty_rooms - sold_rooms;
        cout << "\n\n Total rooms collection for the day : " << total_rooms;

        cout << "\n\n Number of pasta we had : " << qty_pasta;
        cout << "\n\n Number of pasta we gave for rent : " << sold_pasta;
        cout << "\n\n Reamining pasta : " << qty_pasta - sold_pasta;
        cout << "\n\n Total pasta collection for the day : " << total_pasta;

        cout << "\n\n Number of burger we had : " << qty_burger;
        cout << "\n\n Number of burger we gave for rent : " << sold_burger;
        cout << "\n\n Reamining burger : " << qty_burger - sold_burger;
        cout << "\n\n Total burger collection for the day : " << total_burger;

        cout << "\n\n Number of noodles we had : " << qty_noodles;
        cout << "\n\n Number of noodles we gave for rent : " << sold_noodles;
        cout << "\n\n Reamining noodles : " << qty_noodles - sold_noodles;
        cout << "\n\n Total noodles collection for the day : " << total_noodles;

        cout << "\n\n Number of shake we had : " << qty_shake;
        cout << "\n\n Number of shake we gave for rent : " << sold_shake;
        cout << "\n\n Reamining shake : " << qty_shake - sold_shake;
        cout << "\n\n Total shake collection for the day : " << total_shake;

        cout << "\n\n Number of chicken we had : " << qty_chicken;
        cout << "\n\n Number of chicken we gave for rent : " << sold_chicken;
        cout << "\n\n Reamining chicken : " << qty_chicken - sold_chicken;
        cout << "\n\n Total chicken collection for the day : " << total_chicken;

        cout << "\n\n\n Total Collection for the day: " << total_rooms + total_burger + total_chicken + total_noodles + total_pasta + total_shake;
        break;
    case 8:
        exit(0);
        break;
    default:
        cout << "\n Please select the number mentioned above! ";
    }
    goto m;
    return 0;
}
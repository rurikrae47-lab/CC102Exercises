#include <iostream>
using namespace std;

int main()
{
    int shop[5][10] = {0};
    int choice;
    int row, col, hours;
    double sale;

    do
    {
        cout << "\n===== COMPUTER SHOP RENTAL SYSTEM =====\n";
        cout << "1. View Computer Layout\n";
        cout << "2. Rent a Computer\n";
        cout << "3. Return a Computer\n";
        cout << "4. Reset Rental System\n";
        cout << "5. Exit\n";
        cout << "=======================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n      1   2   3   4   5   6   7   8   9  10\n";
            cout << "    +---+---+---+---+---+---+---+---+---+---+\n";

            for (int i = 0; i < 5; i++)
            {
                cout << "  " << char('A' + i) << " |";
                for (int j = 0; j < 10; j++)
                {
                    if (shop[i][j] < 10)
                        cout << " " << shop[i][j] << " |";
                    else
                        cout << shop[i][j] << " |";
                }
                cout << endl;
            }
            cout << "    +---+---+---+---+---+---+---+---+---+---+\n\n";
        }

        else if (choice == 2)
        {
            cout << "Enter row number (1-5): ";
            cin >> row;
            cout << "Enter column number (1-10): ";
            cin >> col;
            cout << "Enter number of hours: ";
            cin >> hours;

            row = row - 1;
            col = col - 1;

            if (row < 0 || row > 4 || col < 0 || col > 9)
            {
                cout << "Invalid row or column!\n";
            }
            else if (hours <= 0)
            {
                cout << "Hours must be greater than 0!\n";
            }
            else if (shop[row][col] > 0)
            {
                cout << "Computer unit " << char('A' + row) << (col + 1)
                     << " already rented!\n";
            }
            else
            {
                shop[row][col] = hours;
                cout << "Computer unit " << char('A' + row) << (col + 1)
                     << " successfully rented for " << hours << " hour(s)!\n";
            }
        }

        else if (choice == 3)
        {
            cout << "Enter row number (1-5): ";
            cin >> row;
            cout << "Enter column number (1-10): ";
            cin >> col;

            row = row - 1;
            col = col - 1;

            if (row < 0 || row > 4 || col < 0 || col > 9)
            {
                cout << "Invalid row or column!\n";
            }
            else if (shop[row][col] == 0)
            {
                cout << "Computer unit " << char('A' + row) << (col + 1)
                     << " is already available!\n";
            }
            else
            {
                sale = shop[row][col] * 20.0;
                cout << "Computer unit " << char('A' + row) << (col + 1)
                     << " has been returned.\n";
                cout << "Rental Sale: P" << sale << "\n";
                shop[row][col] = 0;
            }
        }

        else if (choice == 4)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    shop[i][j] = 0;
                }
            }
            cout << "Rental system reset successfully!\n";
        }

        else if (choice == 5)
        {
            cout << "Thank you for using the system. Goodbye!\n";
        }

        else
        {
            cout << "Invalid choice! Please enter 1-5.\n";
        }

    } while (choice != 5);

    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;
    do {
        double sales[5][4];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                sales[i][j] = 0;
            }
        }

        char more = 'y';
        while (more == 'y' || more == 'Y') {
            int salesperson, product;
            double amount;

            cout << "Salesperson: ";
            cin >> salesperson;
            cout << "Product: ";
            cin >> product;
            cout << "Amount: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] = sales[product - 1][salesperson - 1] + amount;

            cout << "Add another entry? (y/n): ";
            cin >> more;
        }

        cout << "\n";
        cout << setw(10) << left  << "Product"
             << setw(12) << right << "1"
             << setw(12) << right << "2"
             << setw(12) << right << "3"
             << setw(12) << right << "4"
             << setw(12) << right << "Total" << endl;
        cout << "--------------------------------------------------------------------------\n";

        double grandTotal = 0;
        double colTotal[4] = {0, 0, 0, 0};

        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << setw(10) << left << i + 1;
            for (int j = 0; j < 4; j++) {
                cout << setw(12) << right << fixed << setprecision(2) << sales[i][j];
                rowTotal = rowTotal + sales[i][j];
                colTotal[j] = colTotal[j] + sales[i][j];
            }
            cout << setw(12) << right << fixed << setprecision(2) << rowTotal << endl;
            grandTotal = grandTotal + rowTotal;
        }

        cout << "--------------------------------------------------------------------------\n";
        cout << setw(10) << left << "Total";
        for (int j = 0; j < 4; j++) {
            cout << setw(12) << right << fixed << setprecision(2) << colTotal[j];
        }
        cout << setw(12) << right << fixed << setprecision(2) << grandTotal << endl;

        cout << "\nDo you want to run again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

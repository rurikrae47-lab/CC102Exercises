#include <iostream>
#include <vector>
using namespace std;

int main() {
    char ans;

    do {
        int students, days;
        cout << "Enter number of students: "; cin >> students;
        cout << "Enter number of days: "; cin >> days;

        vector<vector<int>> att(students, vector<int>(days));

        for (int i = 0; i < students; i++) {
            cout << "Student " << i + 1 << " attendance: ";
            for (int j = 0; j < days; j++)
                cin >> att[i][j];
        }

        cout << "\nStudent ";
        for (int d = 1; d <= days; d++) cout << "D" << d << " ";
        cout << "Total Percentage Remarks\n";

        cout << "------- ";
        for (int d = 1; d <= days; d++) cout << "-- ";
        cout << "----- ---------- -------\n";

        for (int i = 0; i < students; i++) {
            int total = 0;
            for (int j = 0; j < days; j++) total += att[i][j];

            double percent = (double)total / days * 100;

            cout << i + 1 << "       ";
            for (int j = 0; j < days; j++) cout << att[i][j] << "  ";
            cout << total << "     " << percent << "%     ";
            cout << (percent < 50 ? "DRP" : "OK") << "\n";
        }

        cout << "\nRun again? (y/n): "; cin >> ans;

    } while (ans == 'y' || ans == 'Y');
}

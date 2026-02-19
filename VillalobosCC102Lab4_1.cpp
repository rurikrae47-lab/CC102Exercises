#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;
    do {
        int students, quizzes;
        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[100][100];

        for (int i = 0; i < students; i++) {
            cout << "Student " << i + 1 << " scores: ";
            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
            }
        }

        cout << "\nStudent  Q1      Q2      Q3      Q4      Average\n";
        cout << "--------------------------------------------------\n";

        for (int i = 0; i < students; i++) {
            double sum = 0;
            cout << i + 1 << "        ";
            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "      ";
                sum = sum + scores[i][j];
            }
            double avg = sum / quizzes;
            cout << fixed << setprecision(2) << avg << endl;
        }

        cout << "\nDo you want to run again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

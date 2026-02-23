#include "header.h"
#include <iostream>
using namespace std;

int main() {
    int id, tenure;
    string name;
    double amount, rate;

    Loan defaultLoan;
    cout << "\nDisplaying Default Loan:";
    defaultLoan.displayDetails();

    cout << "\n\nEnter Loan ID: ";
    cin >> id;

    cout << "Enter Applicant Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Loan Amount: ";
    cin >> amount;

    cout << "Enter Annual Interest Rate (%): ";
    cin >> rate;

    cout << "Enter Loan Tenure (in months): ";
    cin >> tenure;

    Loan userLoan(id, name, amount, rate, tenure);

    cout << "\nDisplaying User Loan:";
    userLoan.displayDetails();

    return 0;
}

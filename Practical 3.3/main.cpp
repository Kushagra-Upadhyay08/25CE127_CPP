#include "header.h"
int findAccount(BankAccount arr[], int n, long long accNo) {
    for (int i = 0; i < n; i++) {
        if (arr[i].getAccNo() == accNo)
            return i;
    }
    return -1;
}

int main() {
    BankAccount acc[100]; 
    int choice;
    int total = 0;

    while (true) {
        cout << "\n1.Create\n2.Deposit\n3.Withdraw\n4.Check\n5.Transfer\n6.Exit\nChoice: ";
        cin >> choice;

        long long accNo, accNo2;
        int idx, idx2;

        switch (choice) {
        case 1:
            acc[total].createAccount();
            total++;
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accNo;
            idx = findAccount(acc, total, accNo);

            if (idx != -1)
                acc[idx].deposit();
            else
                cout << "Account not found\n";
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> accNo;
            idx = findAccount(acc, total, accNo);

            if (idx != -1)
                acc[idx].withdraw();
            else
                cout << "Account not found\n";
            break;

        case 4:
            cout << "Enter account number: ";
            cin >> accNo;
            idx = findAccount(acc, total, accNo);

            if (idx != -1)
                acc[idx].display();
            else
                cout << "Account not found\n";
            break;

        case 5:
            cout << "From Account: ";
            cin >> accNo;
            cout << "To Account: ";
            cin >> accNo2;

            idx = findAccount(acc, total, accNo);
            idx2 = findAccount(acc, total, accNo2);

            if (idx != -1 && idx2 != -1) {
                long double amt;
                cout << "Enter amount: ";
                cin >> amt;
                acc[idx].transfer(acc[idx2], amt);
            } else {
                cout << "Invalid accounts\n";
            }
            break;

        case 6:
            cout << "Total Accounts Created: " << BankAccount::count;
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
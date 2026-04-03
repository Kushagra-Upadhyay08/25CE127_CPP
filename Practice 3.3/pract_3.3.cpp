#include <iostream>
using namespace std;

class BankAccount {
    char name[100];
    long long accountNumber;
    long double balance;

public:
    static int count;

    void createAccount() {
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 100);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0) balance = 0;

        count++;
    }

    void deposit() {
        long double amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;

        if (amt <= 0) {
            cout << "Invalid amount\n";
            return;
        }

        balance += amt;
        cout << "Deposit successful\n";
    }

    void withdraw() {
        long double amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if (amt <= 0 || amt > balance) {
            cout << "Invalid or insufficient balance\n";
            return;
        }

        balance -= amt;
        cout << "Withdrawal successful\n";
    }

    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    long long getAccNo() {
        return accountNumber;
    }

    long double getBalance() {
        return balance;
    }

    void transfer(BankAccount &to, long double amt) {
        if (amt <= 0 || amt > balance) {
            cout << "Transfer failed\n";
            return;
        }

        balance -= amt;
        to.balance += amt;

        cout << "Transfer successful\n";
    }
};

int BankAccount::count = 0;

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
#include "header.h"


    void BankAccount:: createAccount() {
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

    void BankAccount:: deposit() {
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

    void BankAccount::withdraw() {
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

    void BankAccount::display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    long long BankAccount::getAccNo() {
        return accountNumber;
    }

    long double BankAccount:: getBalance() {
        return balance;
    }

    void BankAccount:: transfer(BankAccount &to, long double amt) {
        if (amt <= 0 || amt > balance) {
            cout << "Transfer failed\n";
            return;
        }

        balance -= amt;
        to.balance += amt;

        cout << "Transfer successful\n";
    }


int BankAccount::count = 0;


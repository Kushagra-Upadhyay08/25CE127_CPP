#include <iostream>
using namespace std;

class BankAccount {
    char name[100];
    long long accountNumber;
    long double balance;

public:
    static int count;

    void createAccount() ;

    void deposit();

    void withdraw(); 

    void display() ;
    long long getAccNo(); 

    long double getBalance();

    void transfer(BankAccount &to, long double amt);
};




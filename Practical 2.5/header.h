#include <iostream>
#include <string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan();
    Loan(int id, string name, double amount, double rate, int tenure);

    double calculateEMI();
    void displayDetails();
};

#include "header.h"
#include <cmath>

Loan::Loan() {
    loanID = 0;
    applicantName = "Anamika";
    loanAmount = 0;
    annualInterestRate = 0.0;
    tenureMonths = 0;
}

Loan::Loan(int id, string name, double amount, double rate, int tenure) {
    loanID = id;
    applicantName = name;
    loanAmount = amount;
    annualInterestRate = rate;
    tenureMonths = tenure;
}

double Loan::calculateEMI() {
    double R = annualInterestRate / (12 * 100);

    if (R == 0) return loanAmount / tenureMonths;

    double EMI = (loanAmount * R * pow(1 + R, tenureMonths)) /
                 (pow(1 + R, tenureMonths) - 1);
    return EMI;
}

void Loan::displayDetails() {
    cout << "\n--- Loan Details ---\n";
    cout << "Loan ID: " << loanID << endl;
    cout << "Applicant Name: " << applicantName << endl;
    cout << "Loan Amount: " << loanAmount << endl;
    cout << "Interest Rate: " << annualInterestRate << "%" << endl;
    cout << "Tenure (in Months): " << tenureMonths << endl;
    cout << "Monthly EMI: " << calculateEMI() << endl;
}

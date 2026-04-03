// A growing organization wants to automate its payroll system to efficiently compute employee
// salaries. Each employee's record must store the name, basic salary, and bonus amount.
// While most employees receive a default bonus, exceptional performers may receive a
// customized bonus.
// To enable instant computation of the salary, an inline function will calculate total salary =
// basic salary + bonus.
// Employee details must be initialized through a constructor, using either default or customized
// bonus amounts.
// As the organization expands, dynamic storage of employee records is required to support
// scalability.
// The system must display complete employee details along with their total salary.

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n, double basic, double b = 1000) {
        name = n;
        basicSalary = basic;
        bonus = b;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << totalSalary() << endl;
    }
};

#endif
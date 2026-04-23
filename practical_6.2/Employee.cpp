#include <iostream>
#include "header.h"
using namespace std;

void Employee::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Role: Employee" << endl;
    cout << "Employee ID: " << EmployeeID << endl;
}
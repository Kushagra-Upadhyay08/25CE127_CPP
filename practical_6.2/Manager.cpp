#include <iostream>
#include "header.h"
using namespace std;

void Manager::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Role: Person" << endl;
    cout << "Employee ID: " << EmployeeID << endl;
    cout << "Department Overseen: " << departmentOverseen << endl;
}
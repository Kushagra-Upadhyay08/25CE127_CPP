#include <iostream>
#include "header.h"
using namespace std;

void Person::display()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Role: Person" << endl;
}

string Person::getName()
{
    return name;
}
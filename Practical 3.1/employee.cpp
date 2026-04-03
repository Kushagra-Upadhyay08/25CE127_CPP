#include "header.h"
#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee *emp = new Employee[n];  

    string name;
    double basic, bonus;
    int choice;

    for(int i = 0; i < n; i++) {

        cout << "\nEmployee " << i+1 << endl;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter basic salary: ";
        cin >> basic;

        cout << "1. Default Bonus\n";
        cout << "2. Custom Bonus\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                emp[i] = Employee(name, basic);
                break;

            case 2:
                cout << "Enter bonus: ";
                cin >> bonus;
                emp[i] = Employee(name, basic, bonus);
                break;

            default:
                cout << "Invalid choice! Default bonus applied.\n";
                emp[i] = Employee(name, basic);
        }
    }

    cout << "\nEmployee Details\n";

    for(int i = 0; i < n; i++) {
        emp[i].display();
    }

    delete[] emp;

    return 0;
}
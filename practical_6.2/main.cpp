#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    int choice,no_person=0,no_employee=0,no_manager=0,age,id_choice,des_choice;
    string name,departmentOverseen;
    Person p[10];
    Employee e[10];
    Manager m[5];
    start:
    cout << "Please enter your choice" << endl;
    cout << "1. Add New Person" << endl
         << "2. Add New Employee" << endl
         << "3. Add new Manager" << endl
         << "4. Display Names" << endl
         << "5. Display Details" << endl
         << "6. Exit" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "Enter Name" << endl;
            cin >> name;
            cout << "Enter Age" << endl;
            cin >> age;
            p[no_person++]=Person(name,age);
            goto start;
        }
        case 2:
        {
            cout << "Enter Name" << endl;
            cin >> name;
            cout << "Enter Age" << endl;
            cin >> age;
            e[no_employee++]=Employee(no_employee,name,age);            
            goto start;
        }
        case 3:
        {
            cout << "Enter Name" << endl;
            cin >> name;
            cout << "Enter Age" << endl;
            cin >> age;
            cout << "Enter Department Overseen" << endl;
            cin >> departmentOverseen;
            m[no_manager++]=Manager(departmentOverseen,no_employee,name,age);
            goto start;
        }
        case 4:
        {
            for(int i=0;i<no_person;i++)
            {
                cout << "Person " << i+1 << " Name: " << p[i].getName() << endl;
            }
            for(int i=0;i<no_employee;i++)
            {
                cout << "Employee " << i+1 << "Name: " << e[i].getName() << endl;
            }
            for(int i=0;i<no_manager;i++)
            {
                cout << "Manager " << i+1 << "Name: " << m[i].getName() << endl;
            }                        
            goto start;
        }
        case 5:
        {
            cout << "Enter ID of person for Required Details" << endl;
            cin >> id_choice;
            cout << "Select their Designation" << endl;
            cout << "1. Person" << endl << 
                    "2. Employee" << endl <<
                    "3. Manager" << endl;
            cin >> des_choice;
            switch(des_choice)
            {
                case 1:
                {
                    p[--id_choice].display();
                    break;
                }
                case 2:
                {
                    e[--id_choice].display();
                    break;
                }
                case 3:
                {
                    m[--id_choice].display();
                    break;
                }
            }
            goto start;
        }
        case 6:
        {
            break;
        }
    }

    return 0;
}
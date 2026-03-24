#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float m1, m2, m3, avg;

public:
    
    void set_default() {
        rollNo = 0;
        name = "Anamika";
        m1 = m2 = m3 = 0;
        calcAverage();
    }

    
    void setData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        calcAverage();
    }

    void calcAverage() {
        avg = (m1 + m2 + m3) / 3;
    }

    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nAverage: " << avg << endl;
    }
};
// Here using switch cases you can add students , 
// it depends on you whether you want to add students with default values or based on yiur input. 
int main() {
    Student std[50];
    int t= 0;
    int choice;

    do {
        cout << "\n\n*** MENU ***";
        cout << "\n1. Add student (with default values)";
        cout << "\n2. Add student (based on user input)";
        cout << "\n3. Display all students";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                std[t].set_default();
                t++;
                cout << "Default student added.";
                break;

            case 2:
                std[t].setData();
                t++;
                cout << "Student added successfully.";
                break;

            case 3:
                if (t == 0) {
                    cout << "No student records available.";
                } else {
                    for (int i = 0; i < t; i++) {
                        std[i].display();
                    }
                }
                break;

            case 4:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}

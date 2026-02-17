//Inventory management system   


#include<iostream>
#include "header.h"
using namespace std;

int main(){
int t=0,i,id,qyt,choice,price;
string name;

Inventory inven[100];

while(1){
    cout << "1. Add Inventory" << endl;
    cout << "2. Display Inventory" << endl;
    cout << "3. Increase Stock" << endl;

    cout << "4. Sale" << endl;

    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> qyt;
            cout << "Enter Price: ";
            cin >> price;
            inven[t++] = Inventory(id, name, qyt, price);
            break;
        case 2:
            for(i=0;i<t;i++){
                inven[i].display();
                cout << "------------------" << endl;
            }
            break;
        case 3:
            cout << "Enter ID to increase stock: ";
            cin >> id;
            cout << "Enter quantity to increase: ";
            cin >> qyt;
            for(i=0;i<t;i++){
                if(inven[i].search(id)){
                    inven[i].increase_stock(qyt);
                    cout << "Stock increased successfully." << endl;
                    break;
                }
            }
            if(i==t){
                cout << "Inventory not found." << endl;
            }
            break;
        case 4:
             cout << "Enter ID for sale: ";
             cin >> id;
             cout << "Enter quantity for sale: ";
             cin >> qyt;
             for(i=0;i<t;i++){
                 if(inven[i].search(id)){
                     inven[i].sale(qyt);
                     break;
                 }
             }
             if(i==t){
                 cout << "Inventory not found." << endl;
             }
             break;
        case 5:
            exit(0);
         default:
             cout << "Invalid choice. Please try again." << endl;
    }
    
}

return 0;
}
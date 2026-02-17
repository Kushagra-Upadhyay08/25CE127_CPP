#include<iostream>
using namespace std;


class Inventory{
    int ID;
    string name;
    int quantity;
    double price;
public:
    Inventory(){
        ID = 0;
        name = "";
        quantity = 0;
        price = 0.0;
    }
 Inventory(int id, string n, int q, double p){
     ID = id;
     name = n;
     quantity = q;
     price = p;
 }

 
    void display(){
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
    }

    void increase_stock(int qty){
        quantity += qty;
    }

   

     void sale(double qty){
        if(qty<=quantity){
            quantity -= qty;
            double total_price = qty * price;
            cout << "Total price: Rs" << total_price << endl;
        }
        else {
            cout << "Not enough stock for sale." << endl;
        }
     }

     bool search(int id){
        return ID == id;
     }

};
// Develop a file-based inventory management system that allows users to add items, view all
// items, and search for an item by its name. Each inventory record must store the item’s name,
// quantity, and price, and these records will be stored sequentially inside a text file.
// The program must support three operations:
// 1. Add Item: Take item details from the user and append the record to the inventory
// file.
// 2. View All Items: Read the inventory file sequentially and display every stored item.
// 3. Search Item by Name: Read each record, compare item names, and display the
// matching item’s details.


#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
class InventoryItem {
private:
    string name;
    int quantity;
    float price;
public:
    
    void display() {
        //to display all items in the inventory
        ifstream file("data.txt");
        string line;
        while(getline(file,line)){
            stringstream s(line);
            string name;
            int quantity;
            float price;
            getline(s,name,',');
            s>>quantity;
            s.ignore();
            s>>price;
            cout<<"Name: "<<name<<", Quantity: "<<quantity<<", Price: "<<price<<endl;
        }
        file.close();
    }
    void add_item(){
        ofstream file("data.txt",ios::app);
       cout<<"Enter item name : ";
       cin >> name;
       cout<<"Enter item quantity : ";
       cin >> quantity;
       cout<<"Enter item price : ";
       cin >> price;
       file << name << "," << quantity << "," << price << endl;
       file.close();
    }

   

int search(string name) {
    ifstream fin("data.txt");
    string line;
    string cust_name=" ";
    while(getline(fin,line)){
        
        stringstream s(line);

        getline(s,cust_name,',');
        if(cust_name==name){
            return 1;
            fin.close();
        }

    }
    fin.close();
    return 0;
}

   };


int main(){
int choice;
string cname;
while(1){
    cout<<"1.Add item\n2.View all items\n3.Search item by name\n4.Exit\nEnter your choice : ";
cin>>choice;
switch(choice){
    case 1:{
        InventoryItem item;
        item.add_item();
        break;
    }
    case 2:{
        InventoryItem item;
        item.display();
        break;
    }
    case 3:{
        cout<<"Enter item name to search : ";
        cin>>cname;
        InventoryItem item;
        if(item.search(cname)){
            cout<<"Item found in inventory."<<endl;
        }else{
            cout<<"Item not found in inventory."<<endl;
        }
        break;
    }
    case 4:{
        exit(0);
    }
    default:{
        cout<<"Invalid choice. Please try again."<<endl;
    }
}


}
return 0;
}

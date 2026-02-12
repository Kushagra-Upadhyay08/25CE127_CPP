//Making an digital savings account system 
#include <iostream>
#include <string>
using namespace std;
class Save_acc{
    string name;
    int acc_no;
    float balance;
        public:
            void get_details();
            void deposite();
            void withdraw();
            void display();
            bool search(int);
        
};

void Save_acc::withdraw(){
    float amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if(amount>balance){
        cout << "Insufficient balance!" << endl;
    }
    else{
        balance -= amount;
        cout << "Amount withdrawn: " << amount << endl;
        cout << "New balance: " << balance << endl;
    }
}

void Save_acc::deposite(){
    float amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    balance += amount;
    cout << "Amount deposited: " << amount << endl;
    cout << " balance: " << balance << endl;
}

void Save_acc::get_details(){
    cout << "Enter account holder's name: ";
    cin.ignore(); // To ignore the newline character left in the input buffer
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> acc_no;
    cout << "Enter initial balance: ";
    cin >> balance;
}

void Save_acc::display(){
    cout << "Account Holder's Name: " << name << endl;
    cout << "Account Number: " << acc_no << endl;
    cout << "Balance: " << balance << endl;
}

bool Save_acc::search(int a){
    return acc_no == a;
}



int main(){

    cout << "Welcome to the Digital Savings Account System!" << endl;
    Save_acc accounts[100];
    int t=0,i;

    while(true){
        
    cout<<"Menu: "<<endl;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Display Account Details"<<endl;
    cout<<"5. Exit"<<endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                accounts[t].get_details();
                    t++;
                
                break;
            case 2:
                int acc_no;
                cout << "Enter account number to deposit money: ";
                cin >> acc_no;
                for(i=0; i<t; i++){
                    if(accounts[i].search(acc_no)){
                        accounts[i].deposite();
                        break;
                    }
                }
                if(i==t){ cout << "Account not found!" << endl; }
                break;
            case 3:
                int acc_no_withdraw;
                cout << "Enter account number to withdraw money: ";
                cin >> acc_no_withdraw;
                for(i=0; i<t; i++){
                    if(accounts[i].search(acc_no_withdraw)){
                        accounts[i].withdraw();
                        break;
                    }
                }
                if(i==t){ cout << "Account not found!" << endl; }
                break;
            case 4:
                int acc_no_display;
                cout << "Enter account number to display details: ";
                cin >> acc_no_display;
                for(i=0; i<t; i++){
                    if(accounts[i].search(acc_no_display)){
                        accounts[i].display();
                        break;
                    }
                }
                if(i==t){ cout << "Account not found!" << endl; }
                break;
            case 5:
                cout << "Thank you for using the Digital Savings Account System!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}

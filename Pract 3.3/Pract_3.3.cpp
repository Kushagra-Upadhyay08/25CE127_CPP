#include<iostream>
#include<string>
using namespace std;

class bank{
    int acc_no;
    string name;
    int balance;

public:
    static int count;

    void creat_acc(){
        cin.ignore(); // fix getline issue
        cout<<"Enter Account Holder's name : ";
        getline(cin,name);

        cout<<"Enter account number : ";
        cin>>acc_no;

        cout<<"Enter current balance : ";
        cin>>balance;
    }

    void display(){
        cout<<"Account Holder's name : "<<name<<endl;
        cout<<"Account number : "<<acc_no<<endl;
        cout<<"Current balance : "<<balance<<endl;
    }

    void transfer(bank &to,int amount){
        if(balance < amount || amount <= 0){
            cout<<"Transaction failed (Insufficient amount)\n";
            return;
        }
        balance -= amount;
        to.balance += amount;
        cout<<"Transaction successful\n";
    }

    bool search(int num){
        return num == acc_no;
    }
};

int bank::count = 0;

int main(){
    bank *ptr = new bank[100];

    int choice, num, amount, i;

    while(1){
        cout<<"\n1.Create account\n2.Display\n3.Transfer\n4.Exit\n";
        cout<<"Enter Choice : ";
        cin>>choice;

        switch(choice){

        case 1:
            if(bank::count >= 100){
                cout<<"Bank storage full\n";
                break;
            }
            ptr[bank::count].creat_acc();
            bank::count++;
            break;

        case 2: {
            cout<<"Enter account number : ";
            cin>>num;

            bool found = false;

            for(i = 0; i < bank::count; i++){
                if(ptr[i].search(num)){
                    ptr[i].display();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout<<"Account does not exist\n";

            break;
        }

        case 3: {
            int sender, receiver;
            cout<<"Enter your account number : ";
            cin>>sender;

            cout<<"Enter receiver's account number : ";
            cin>>receiver;

            bank *from = NULL;
            bank *to = NULL;

            // ✅ single loop instead of nested loop
            for(i = 0; i < bank::count; i++){
                if(ptr[i].search(sender))
                    from = &ptr[i];

                if(ptr[i].search(receiver))
                    to = &ptr[i];
            }

            if(from == NULL){
                cout<<"Sender account does not exist\n";
                break;
            }

            if(to == NULL){
                cout<<"Receiver account does not exist\n";
                break;
            }

            cout<<"Enter amount : ";
            cin>>amount;

            from->transfer(*to, amount);
            break;
        }

        case 4:
            delete[] ptr;
            return 0;
        }
    }
}
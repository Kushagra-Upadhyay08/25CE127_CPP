#include<iostream>

using namespace std;

class bank_account
{
    char account_holder_name[100];
    double account_number;
    long double balance;
public:
    void creat_account();
    void withdraw();
    void deposit();
    void check_balance();
    int search_acc_no(double);
};

int bank_account::search_acc_no(double account_no_input){


    if(account_number==account_no_input){
        return 1;
    }
    else return 0;
}

void bank_account::deposit(){
long double Depo_Amount=0;
cout<<"Enter Amount :";
cin>>Depo_Amount;
cout<<endl;
balance-=Depo_Amount;
}

void bank_account::withdraw(){
long double With_Amount=0;
cout<<"Enter Amount :";
cin>>With_Amount;
cout<<endl;
balance+=With_Amount;
}

void bank_account::check_balance(){

cout<<"Your Current balance is :"<<balance;

}

void bank_account::creat_account(){
cout<<"Enter Account Holder name:";
cin>>account_holder_name;
cout<<"Enter Account Number:";
cin>>account_number;
cout<<"Enter Balance:";
cin>>balance;




}


int main()
{
    bank_account acc[50];
    int choice,t=0,i;
    long double Acc_NO;
menu:
    cout<< "\nEnter 1 for creat account \n Enter 2 for Withdraw money \n Enter 3 for Deposite money \n Enter 4 for Check Balance \n Enter 5 for Exit.\n";
    cout<<"Enter choice";
    cin>>choice;
    switch(choice)
    {

    case 1 :
        acc[t].creat_account();
        t++;
        goto menu;
    case 2:
        cout<<"Enter Account Number :";
        cin>>Acc_NO;

        for(i=0;i<t;i++){
            if(acc[i].search_acc_no(Acc_NO))
            {
                acc[i].deposit();
                break; }
                 }

            if(i==t){
                cout<<"Account not found";
            }
            goto menu;


        case 3:
            cout<<"Enter Account Number :";
            cin>>Acc_NO;
            for(i=0;i<t;i++){
            if(acc[i].search_acc_no(Acc_NO))
            {
                acc[i].deposit();
                break; }
                 if(i==t){
                cout<<"Account not found";
            }
            goto menu;


            case 4 :
                cout<<"Enter Account Number :";
                cin>>Acc_NO;
                for(i=0;i<t;i++){
            if(acc[i].search_acc_no(Acc_NO))
            {
                acc[i].deposit();
                break; }
                 if(i==t){
                cout<<"Account not found";
            }
            goto menu;

                case 5:
                    cout<<"Thank for Comming";
                    return 0;

                default:
                    cout<<"Invalid choice , Try again";

                    goto menu;


                }

            }

        }
        return 0; }


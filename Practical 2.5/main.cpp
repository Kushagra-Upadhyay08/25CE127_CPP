#include "header.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    // Generateing an switch case based system for the user to interact with the program
    int t=0,i,choice;
    double id;
    string name;
    double amount;
    float intrest;
    int tenure;
    loan l[100];

    while(1){
        cout<<"1.Add a new loan application"<<endl;
        cout<<"2.Display all loan applications"<<endl;
        cout<<"3.Calculate EMI for a loan application"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Loan ID: ";
                cin>>id;
                cout<<"Enter Applicant Name: ";
                cin>>name;
                cout<<"Enter Loan Amount: ";
                cin>>amount;
                cout<<"Enter Annual Intrest: ";
                cin>>intrest;
                cout<<"Enter Loan Tenure: ";
                cin>>tenure;
                l[t++]=loan(id,name,amount,intrest,tenure);
                break;
                
            case 2:
            if(t==0){
                cout<<"Not a single Loan is not applied yet"<<endl;
                break;
            }
                for(i=0;i<t;i++){
                    l[i].display();
                }
                break;
            
            case 3:
                cout<<"Enter Loan ID: ";
                cin>>id;
                for(i=0;i<t;i++){
                    if(l[i].search(id)){
                        
                        cout<<"EMI: "<<l[i].calc_emi()<<endl;    
                    }
                }
                if(i==t){
                    cout<<"Loan ID not found"<<endl;
                }
                break;
            case 4:
                
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
            
    }
    
}

return 0;
}
#include<iostream>
#include<string>

using namespace std;

class loan {
    double loan_id;
    string applicant_name;
    double loan_amount;
    float annual_intrest;
    int loan_tenure;
    public:
    float calc_emi();
    bool search(double id){
        return loan_id==id;
    }
    void display();
    loan(){
        loan_id=0;
        applicant_name="Anamika";
        loan_amount=0;
        annual_intrest=0;
        loan_tenure=0;

    }
    loan(double id,string name,double amount,float intrest,int tenure){
        loan_id=id;
        applicant_name=name;
        loan_amount=amount;
        loan_tenure=tenure;
        annual_intrest=intrest;
    }
    
};
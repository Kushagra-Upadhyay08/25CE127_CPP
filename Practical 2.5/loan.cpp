#include "header.h"
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

float loan::calc_emi(){
    float R=annual_intrest/(12*100);
    int T=loan_tenure*12;
    float emi= loan_amount*R / (1 - pow(1+R,-T));
    return emi;
}

void loan::display(){
        cout<<"Loan ID: "<<loan_id<<endl;
        cout<<"Applicant Name: "<<applicant_name<<endl;
        cout<<"Loan Amount: "<<loan_amount<<endl;
        cout<<"Annual Intrest: "<<annual_intrest<<endl;
        cout<<"Loan Tenure: "<<loan_tenure<<endl;
    }
   
#include<iostream>
#include<string>
using namespace std;

string repeat(const string& str,int num){
    string concat;
    for(int i=0;i<num;i++){
        concat+=str;
    }
    cout<<"concatinated number : "<<concat;
    return concat;
}
long long summation(long long numb){
    long long sum=0;
    while(numb!=0){
        sum+=numb%10;
        numb/=10;
    }
    return sum;
}

int main(){
    string str;
    int num;
    cout<<"Enter the Number : ";
    cin>>str;
    cout<<"Enter number of concatination : ";
    cin>>num;

    string ans =repeat(str,num);
    long long number = stoll(ans);


    while(number>=10){

           number= summation(number);


    }

    cout<<"\nSum is : "<<number;
    return 0;

}

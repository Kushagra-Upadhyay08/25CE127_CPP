#include<iostream>
#include<memory>
using namespace std;

int main(){
    shared_ptr<int>p1=make_unique<int>(10);
    cout<<p1.use_count();

}
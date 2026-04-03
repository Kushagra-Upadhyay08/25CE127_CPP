#include<iostream>
#include<chrono>
using namespace std;

long long rec(int* sum,long long n){
    if(n==0){
        return 0;
    }
    return sum[n-1] + rec(sum,n-1);
}

long long iter(int* sum,long long n){
    long long ans=0;
    for(int i=0;i<n;i++){
        ans += sum[i];
    }
    return ans;
}

int main(){

    chrono::high_resolution_clock::time_point l1,l2,l3,l4;
    chrono::duration<double, micro> rec_time,iter_time;

    long long n;

    cout<<"Enter total numbers in array : ";
    cin>>n;

    int* sum = new int[n];

    for(int i=0;i<n;i++){
        sum[i]=i+10;
    }

    l1 = chrono::high_resolution_clock::now();
    long long recursiveSum = rec(sum,n);
    l2 = chrono::high_resolution_clock::now();
    rec_time = l2 - l1;

    l3 = chrono::high_resolution_clock::now();
    long long iterative_sum = iter(sum,n);
    l4 = chrono::high_resolution_clock::now();
    iter_time = l4 - l3;

    cout<<"Iterative sum : "<<iterative_sum<<endl;
    cout<<"Recursive sum : "<<recursiveSum<<endl;

    cout<<"n : "<<n<<endl;
    cout<<"Time for Recursion : "<<rec_time.count()<<" microseconds"<<endl;
    cout<<"Time for Iteration : "<<iter_time.count()<<" microseconds"<<endl;

    delete[] sum;

    return 0;
}
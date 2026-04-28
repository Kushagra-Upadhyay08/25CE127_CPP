#include <iostream>
#include "header.h"
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    int n;
    Sum sum;
    chrono::system_clock::time_point l1, l2, l3, l4;
    chrono::duration<double> rec, ite;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    // int* arr=new int[n]
    for(int i = 0; i < n; i++) {
        arr[i]=50+i;
    }
    l1 = chrono::system_clock::now();
    long long recursive = sum.recursiveSum(arr, n);
    l2 = chrono::system_clock::now();
    rec = l2 - l1;

    l3 = chrono::system_clock::now();
    long long iterative = sum.iterativeSum(arr);
    l4 = chrono::system_clock::now();
    ite = l4 - l3;
    ite=l4-l3;

    cout << "Iterative Sum: " << iterative << endl;
    cout << "Recursive Sum: " << recursive << endl;
    cout << "value of n: " << n << endl;
    cout << "Time for Recursive: " << rec.count() << " seconds" << endl;
    cout << "Time for Iterative: " << ite.count() << " seconds" << endl;
    
    return 0;

}
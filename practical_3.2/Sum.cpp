#include <iostream>
#include <vector>
#include "header.h"
long long Sum::iterativeSum(const vector<int>& arr) {
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
    }

long long Sum::recursiveSum(const vector<int>& arr, int n) {
    if(n == 0)
        return 0;

    return arr[n-1] + recursiveSum(arr, n-1);
    }
#include<iostream>
using namespace std;


int main(){
    int n,m;
    cout<<"ENter the size of array 1 : ";
    cin>>n;
    int* arr1=new int[n];
    cout<<"ENter the size of array 2 : ";
    cin>>m;
    int* arr2=new int[m];
    cout<<"Enter the elemnts of array 1 :: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>arr1[i];
        
    }
    cout<<"Enter the elemnts of array 2 :: "<<endl;
    for(int i=0;i<m;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>arr2[i];
    }

    int i=0;
    int j=0;
    int k=0;
    int* merge=new int[m+n];
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            merge[k++]=arr1[i++];
            
        }
        else{
            merge[k++]=arr2[j++];
            
        }
        
    }

    while(i<n){
        merge[k++]=arr1[i++];
        
    }

    while(j<m){
        merge[k++]=arr2[j++];
        
    }
cout<<"Soretd array : [";
   for(int l=0;l<(m+n);l++){
    cout<<merge[l];
    if(l+1==(m+n)){
        cout<<"]";
    }
    else{
        cout<<",";
    }
   }

   return 0;


    

}
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter paragraph: ";
    getline(cin, str);

    string words[100];   // store words
    int freq[100] = {0}; // store frequency
    int count = 0;

    string temp = "";


    for(int i = 0; i <= str.length(); i++){
        char ch = str[i];

        if(ch != ' ' && ch != '\0'){
            
            if(ch >= 'A' && ch <= 'Z'){
                ch = ch + 32;
            }
            temp += ch;
        }
        else{
            if(temp != ""){
                words[count++] = temp;
                temp = "";
            }
        }
    }

    for(int i = 0; i < count; i++){
        if(freq[i] != 0) continue; 

        freq[i] = 1;
        for(int j = i + 1; j < count; j++){
            if(words[i] == words[j]){
                freq[i]++;
                freq[j] = -1; 
            }
        }
    }

    
    cout<<"\nWord Frequency:\n";
    for(int i = 0; i < count; i++){
        if(freq[i] > 0){
            cout<<words[i]<<" : "<<freq[i]<<endl;
        }
    }

    return 0;
}
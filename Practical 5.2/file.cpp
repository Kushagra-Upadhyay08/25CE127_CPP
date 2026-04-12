#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream fin("data.txt");

    
    if(!fin){
        cout<<"Error: File could not be opened.\n";
        return 1;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    
    while(getline(fin, line)){
        lineCount++;

        
        for(int i = 0; i < line.length(); i++){
            if(line[i]==' ') continue;
            charCount++;
        }

        
        for(int i = 0; i < line.length(); i++){
            if(line[i] != ' ' && (i == 0 || line[i-1] == ' ')){
                wordCount++;
            }
        }
    }

    fin.close();

    cout<<"Total Lines: "<<lineCount<<endl;
    cout<<"Total Words: "<<wordCount<<endl;
    cout<<"Total Characters: "<<charCount<<endl;

    return 0;
}
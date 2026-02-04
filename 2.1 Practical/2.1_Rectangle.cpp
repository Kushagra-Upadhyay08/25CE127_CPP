#include<iostream>
using namespace std;

class Rectangle{
    int id;
    int length;
    int width;
    public :
        void add_rect();
        
        int Area(){

            return length*width;
        }
            
        int Para(){
            return 2*(length + width);
        }
        bool search(int match_id){
            return match_id == id;
        }
        void display();
        void update();
        
};
void Rectangle::add_rect(){
    
        
    cout<<"Enter then ID of the Rectangle : ";
    cin>>id;
    cout<<"Enter the Length of the Rectangle : ";
    cin>>length;
    cout<<"Enter the Breadth of the Rectangle: ";
    cin>>width;
}


void Rectangle::display(){

    cout<<"ID of the Rectangle : "<<id;
    
    cout<<"||Length of the Rectangle : "<<length;
    
    cout<<"||Breadth of the Rectangle: "<<width<<endl;
    

}

void Rectangle::update(){
    cout<<"Enter the New Length of the Rectangle : ";
    cin>>length;
    cout<<"Enter the New Breadth of the Rectangle: ";
    cin>>width;
}
int main(){

    int choice,t=0,i,match_id;
    Rectangle rect[10];
    

    menu:
    
    cout<<"\nEnter 1 for add Rectangle"<<endl;
    cout<<"Enter 2 for find the parameter of Rectangle"<<endl;
    cout<<"Enter 3 for find Area of  Rectangle"<<endl;
    cout<<"Enter 4 for update  Rectangle's measures"<<endl;
    cout<<"Enter 5 for display all rectangles"<<endl;
    cout<<"Enter 6 for exit"<<endl;

    cout<<endl<<"Enter your choice"<<endl;
    cin>>choice;

    switch(choice){
        
            case 1: 
                    int num;
                    cout<<"Number of Rectangle details to be added : ";
                    cin>>num;

                    for(int i = 0; i < num && t < 10; i++){
                        cout<<"Enter details for Rectangle "<<(t + 1)<<":"<<endl;
                        rect[t].add_rect();
                        t++;
                    }
                    goto menu;


        
            case 2:
                    cout<<"Enter the id of the rectangle : ";
                    cin>>match_id;
                    for(i=0;i<t;i++){
                        if(rect[i].search(match_id)){
                            cout<<"Perimeter of Rectangle with ID "<<match_id<<" is : "<<rect[i].Para()<<endl;
                            
                            goto menu;
                        }
                    }
                    cout<<"ID is not found";
                    

                    goto menu;
                    

                case 3:
                
                    cout<<"Enter the id of the rectangle : ";
                    cin>>match_id;
                    for(i=0;i<t;i++){
                        if(rect[i].search(match_id)){
                            cout<<"Area of Rectangle with ID "<<match_id<<" is : "<<rect[i].Area()<<endl;
                            goto menu;
                        }
                    }
                    cout<<"ID is not found";
                    goto menu;

                    
                
                case 4:
                        cout<<"Enter the id of the rectangle : ";
                        cin>>match_id;
                        for(i=0;i<t;i++){
                        if(rect[i].search(match_id)){
                            rect[i].update();
                            goto menu;
                        }
                    }
                        cout<<"ID is not found";
                    goto menu;
                    
                    
                case 5:
                    if(t==0){
                        cout<<"No rectangles to display!"<<endl;
                        goto menu;
                    }
                    for(i=0;i<t;i++){
                        rect[i].display();
                    }
                    goto menu;
                case 6:
                    cout<<"Thanks for using the program!";
                    exit(0);
                default :
                cout<<"Invalid Choice! Please enter again";
                goto menu;

                }
            

    









    return 0;

} 

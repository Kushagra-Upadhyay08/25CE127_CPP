
#include "header.h"


    Point* Point::move(int dx,int dy){
        x+=dx;
        y+=dy;
        return this;

    }
    void Point::display(){
        
        cout<<"x-coordinates : "<<x<<endl;
        cout<<"y-coordinates : "<<y<<endl;
        cout<<"Point is ("<<x<<","<<y<<")"<<endl;


    }

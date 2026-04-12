#include<iostream>
using namespace std;

class Point{
    int x;
    int y;
    public:
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
    Point* move(int dx,int dy);
    void display();
};


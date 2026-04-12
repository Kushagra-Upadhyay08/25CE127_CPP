#include "header.h"

int main(){
    Point p(12,13);
    p.move(1,2)->move(1,2);
    p.display();
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
    protected:
        float radius;
};

class Circle:public Shape
{
    public:

        Circle()
        {

        }
        Circle(float radius)
        {
            this->radius=radius;
        }

        float calculateArea()
        {
            return M_PI*radius*radius;
        }

        float getRadius()
        {
            return radius;
        }
};
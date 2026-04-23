#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846
class Shape
{
public:
    virtual double Area() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    vector<Shape*> shapes; // Dynamic storage for shapes

    // Adding shapes to the collection
    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(4.0));

    // Calculating and displaying areas
    for (const auto& shape : shapes)
    {
        cout << "Area: " << shape->Area() << endl;
    }

    // Clean up memory
    for (auto& shape : shapes)
    {
        delete shape;
    }
    shapes.clear();

    return 0;
}
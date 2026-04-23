#include <iostream>
using namespace std;


class Celsius;

class Fahrenheit
{
private:
    float temperature;

public:
    Fahrenheit(float temp) : temperature(temp) {}

    float toCelsius() const
    {
        return (temperature - 32) * 5 / 9;
    }

    // Overload == operator
    bool operator==(const Fahrenheit &other) const
    {
        return temperature == other.temperature;
    }
};

class Celsius
{
private:
    float temperature;

public:
    Celsius(float temp) : temperature(temp) {}

    float toFahrenheit() const
    {
        return (temperature * 9 / 5) + 32;
    }

    // Overload == operator
    bool operator==(const Celsius &other) const
    {
        return temperature == other.temperature;
    }
};

int main()
{
    Fahrenheit f(100);
    Celsius c(37.78);

    cout << "Fahrenheit: " << f.toCelsius() << " °C" << endl;
    cout << "Celsius: " << c.toFahrenheit() << " °F" << endl;

    // Compare temperatures
    if (f == Fahrenheit(c.toFahrenheit()))
    {
        cout << "The temperatures are equal." << endl;
    }
    else
    {
        cout << "The temperatures are not equal." << endl;
    }

    return 0;
}
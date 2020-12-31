/**
  *@brief assignment 1 problem 2
  *@author Gauge Hartwell
  */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double temp;
    cout << "Please enter the temperature in fahrenheit: ";
    cin >> temp;
    double windchill;
    cout << "Please enter windchill in MPH: ";
    cin >> windchill;
    double wcIndex;
    wcIndex = 35.74 + 0.6215 * temp - 35.75 * pow(windchill, 0.16) + 0.4275 * temp * pow(windchill, 0.16);
    cout << "The wind chill index is: ";
    cout << wcIndex << endl;
}

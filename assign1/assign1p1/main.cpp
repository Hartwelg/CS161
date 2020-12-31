/**
 * @brief assignment 1 problem 1
 * @author Gauge Hartwell
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int inches;
    cout << "Please input a number of inches: ";
    cin >> inches;

    int currentDistance = 0;
    int miles = inches / 63360;//(inches / 12) / 5280;
    currentDistance = currentDistance + miles * 63360;
    int yards = (inches - currentDistance) / 36;
    currentDistance = currentDistance + yards * 36;
    int feet = (inches - currentDistance) / 12;
    currentDistance = currentDistance + feet * 12;
    int inchesLeft = inches - currentDistance;

    cout << "miles: ";
    cout << miles << endl;
    cout << "yards: ";
    cout << yards << endl;
    cout << "feet: ";
    cout << feet << endl;
    cout << "inches: ";
    cout << inchesLeft << endl;
}

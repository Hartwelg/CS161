/**
  * @brief assignment 2
  * @author Gauge Hartwell
  **/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int method; // 1 for same-day drone, 2 for two-day, 3 for standard
    double cost;
    double shipping;

    cout << "Enter cost: " << endl;
    cin >> cost;
    cout << "Enter Shipping Method: " << endl;
    cin >> method;

    if (method == 1)
    {
        if (cost < 100)
        {
            cout << "Not available" << endl;
        }
        else if (cost > 100 && cost < 500)
        {
            shipping = 50;
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
        else
        {
            shipping = cost * 0.1;
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
    }
    else if (method == 2)
    {
        if (cost < 300)
        {
            shipping = 10 + (cost * 0.02);
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
        else
        {
            shipping = 0;
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
    }
    else if (method == 3)
    {
        if (cost < 35)
        {
            shipping = 5;
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
        else if (cost > 35 && cost < 100)
        {
            shipping = 8;
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
        else
        {
            shipping = 0;
            cout << "Total: ";
            cout << cost + shipping << endl;
        }
    }
    else
    {
        cout << "Bad Input" << endl;
    }
}

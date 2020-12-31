/**
  * @brief assignment 3
  * @author Gauge Hartwell
  **/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double firstSide;
    double secondSide;
    double thirdSide;
    const double PI = 3.1415927;
    const double Epsilon = pow(1, -14);

    cout << "Enter first side: " << endl;
    cin >> firstSide;
    cout << "Enter the second side: " << endl;
    cin >> secondSide;
    cout << "Enter the third side: " << endl;
    cin >> thirdSide;

    double firstAngle ;
    double secondAngle;
    double thirdAngle;

    firstAngle = acos((secondSide * secondSide + thirdSide * thirdSide - firstSide * firstSide) / (2 * secondSide * thirdSide));
    secondAngle = acos((thirdSide * thirdSide + firstSide * firstSide - secondSide * secondSide) / (2 * thirdSide * firstSide));
    thirdAngle = acos((firstSide * firstSide + secondSide * secondSide - thirdSide * thirdSide) / (2 * firstSide * secondSide));

    firstAngle = firstAngle * 180 / PI;
    secondAngle = secondAngle * 180 / PI;
    thirdAngle = thirdAngle * 180 / PI;

    cout << "Angle 1: ";
    cout << firstAngle << endl;
    cout << "Angle 2: ";
    cout << secondAngle << endl;
    cout << "Angle 3: ";
    cout << thirdAngle << endl;

    if (abs(firstAngle - 90) < Epsilon || abs(secondAngle - 90) < Epsilon || abs(thirdAngle - 90) < Epsilon)
    {
        cout << "right" << endl;
    }
    else if (firstAngle > 90 || secondAngle > 90 || thirdAngle > 90)
    {
        cout << "obtuse" << endl;
    }
    else if (abs(firstAngle - 90) > Epsilon && abs(secondAngle - 90) > Epsilon && abs(thirdAngle - 90) > Epsilon)
    {
        cout << "acute" << endl;
    }
    else
    {
        if (firstSide > secondSide)
        {
            if (firstSide > thirdSide)
            {
                if (secondSide + thirdSide < firstSide)
                {
                    cout << "impossible triangle" << endl;
                }
            }
        }
        else if (secondSide > firstSide)
        {
            if (secondSide > thirdSide)
            {
                if (firstSide + thirdSide < secondSide)
                {
                    cout << "impossible triangle" << endl;
                }
            }
        }
        else if (thirdSide > firstSide)
        {
            if (thirdSide > secondSide)
            {
                if (firstSide + secondSide < thirdSide)
                {
                    cout << "impossible triangle" << endl;
                }
            }
        }
    }
}

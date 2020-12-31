#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int weight;
    int age;
    int height;

    cout << "weight: " << endl;
    cin >> weight;
    cout << "age: " << endl;
    cin >> age;
    cout << "height: " << endl;
    cin >> height;

    double bmrWomen = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    double bmrMen = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);

    int MorW;
    cout << "1 for men, 2 for women" << endl;
    cin >> MorW;

    if (MorW == 1)
    {
        cout << "BMR = " << bmrMen << endl;
    }
    else if (MorW == 2)
    {
        cout << "BMR = " << bmrWomen << endl;
    }
}

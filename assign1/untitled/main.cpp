#include <iostream>

using namespace std;

void foo(int p1 = 5)
{
    cout << p1 << endl;
}
int main()
{
    foo(10);
    foo();
}

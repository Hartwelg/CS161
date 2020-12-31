/**
  * @brief Assignment 4
  * @author Gauge Hartwell
  **/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int years;
    int months = 1;
    double APR;
    double monthlyInvestment;
    double total;

    cout << "Monthly Investment: " << endl;
    cin >> monthlyInvestment;
    cout << "APR: " << endl;
    cin >> APR;
    cout << "Years: " << endl;
    cin >> years;

    double monthlyInterest = pow(APR / 100 + 1, 0.0833333333);
    //double monthlyInterest = APR / 100 + 1;

    cout << "year:\t " << "Month:\t " << "Balance:\t " << endl;
    for (int i = 1; i <= years; i++)
    {
        int currentYear = i;
        for (int j = 1; j <= 12; j++)
        {
            total = (total * monthlyInterest) + monthlyInvestment;
            cout << currentYear << "\t" << months << "\t";
                    std::cout << std::fixed << std::setprecision(2) << total << endl;
            months++;
            if (months > 12)
            {
                months = 1;
            }
        }
        currentYear++;
    }
}

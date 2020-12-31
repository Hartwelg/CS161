/**
  * @author Gauge Hartwell
  * @brief assignment 9
  **/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int STATROWS = 10;
const int STATCOLS = 5;
struct qb
{
    string firstName, lastName;
    int completions[STATROWS], attempts[STATROWS], yards[STATROWS], touchdowns[STATROWS], interceptions[STATROWS];
};
void getInfo(qb* player, ifstream &file)
{
    int number;

    file >> number;

    if (file.is_open())
    {
        for (int j = 0; j < number; j++)
        {
            file >> player[j].firstName >> player[j].lastName;

            for (int i = 0; i < STATROWS; i++)
            {

                file >> player[j].completions[i] >> player[j].attempts[i] >> player[j].yards[i] >> player[j].touchdowns[i] >> player[j].interceptions[i];
            }
        }
    }
    else
    {
        cout << "Can't open file" << endl;
    }

}
void printPlayer(qb* player, ifstream &file)
{
    int choice;
    cout << "Choose a player number: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << player[0].firstName << " " << player[0].lastName << endl;
        for (int j = 0; j < STATROWS; j++)
        {
            cout << left << setw(5) <<  player[0].completions[j] << left << setw(5) << player[0].attempts[j] << left << setw(5) << player[0].yards[j] << left << setw(5) << player[0].touchdowns[j] << left << setw(5) << player[0].interceptions[j] << endl;
        }
    }
    else if (choice == 2)
    {
        cout << player[1].firstName << " " << player[1].lastName << endl;
        for (int j = 0; j < STATROWS; j++)
        {
            cout << left << setw(5) <<  player[1].completions[j] << left << setw(5) << player[1].attempts[j] << left << setw(5) << player[1].yards[j] << left << setw(5) << player[1].touchdowns[j] << left << setw(5) << player[1].interceptions[j] << endl;
        }
    }
    else if (choice == 3)
    {
        cout << player[2].firstName << " " << player[2].lastName << endl;
        for (int j = 0; j < STATROWS; j++)
        {
            cout << left << setw(5) <<  player[2].completions[j] << left << setw(5) << player[2].attempts[j] << left << setw(5) << player[2].yards[j] << left << setw(5) << player[2].touchdowns[j] << left << setw(5) << player[2].interceptions[j] << endl;
        }
    }
    else
    {
        printPlayer(player, file);
    }
   cout << endl;
}
void printPlayerStats(qb* player, ifstream &file)
{
    int completionTotal = 0, attemptTotal = 0, yardTotal = 0, touchdownTotal = 0, interceptionTotal = 0;

    int choice;
    cout << "Choose a player number: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << player[0].firstName << " " << player[0].lastName << endl;
        for (int i = 0; i < STATROWS; i++)
        {
            completionTotal += player[0].completions[i];
            attemptTotal += player[0].attempts[i];
            yardTotal += player[0].yards[i];
            touchdownTotal += player[0].touchdowns[i];
            interceptionTotal += player[0].interceptions[i];
        }
        cout << left << setw(12) << "completions " << left << setw(9) << "attempts " << left << setw(6) << "yards " << left << setw(11) << "touchdowns " << left << setw(14) << "interceptions " << endl;
        cout << left << setw(12) <<  completionTotal << left << setw(9) << attemptTotal << left << setw(6) << yardTotal << left << setw(11) << touchdownTotal << left << setw(14) << interceptionTotal << endl;
    }
    else if (choice == 2)
    {
        cout << player[1].firstName << " " << player[1].lastName << endl;
        for (int i = 0; i < STATROWS; i++)
        {
            completionTotal += player[1].completions[i];
            attemptTotal += player[1].attempts[i];
            yardTotal += player[1].yards[i];
            touchdownTotal += player[1].touchdowns[i];
            interceptionTotal += player[1].interceptions[i];
        }
        cout << left << setw(12) << "completions " << left << setw(9) << "attempts " << left << setw(6) << "yards " << left << setw(11) << "touchdowns " << left << setw(14) << "interceptions " << endl;
        cout << left << setw(12) <<  completionTotal << left << setw(9) << attemptTotal << left << setw(6) << yardTotal << left << setw(11) << touchdownTotal << left << setw(14) << interceptionTotal << endl;
    }
    else if (choice == 3)
    {
        cout << player[2].firstName << " " << player[2].lastName << endl;
        for (int i = 0; i < STATROWS; i++)
        {
            completionTotal += player[2].completions[i];
            attemptTotal += player[2].attempts[i];
            yardTotal += player[2].yards[i];
            touchdownTotal += player[2].touchdowns[i];
            interceptionTotal += player[2].interceptions[i];
        }
        cout << left << setw(12) << "completions " << left << setw(9) << "attempts " << left << setw(6) << "yards " << left << setw(11) << "touchdowns " << left << setw(14) << "interceptions " << endl;
        cout << left << setw(12) <<  completionTotal << left << setw(9) << attemptTotal << left << setw(6) << yardTotal << left << setw(11) << touchdownTotal << left << setw(14) << interceptionTotal << endl;
    }
    else
    {
        printPlayerStats(player, file);
    }
}
void printPasserRating(qb* player)
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0, passerRating = 0.0, completionTotal = 0.0, attemptTotal = 0.0, yardTotal = 0.0, touchdownTotal = 0.0, interceptionTotal = 0.0;

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < STATROWS; i++)
        {
            completionTotal += player[j].completions[i];
            attemptTotal += player[j].attempts[i];
            yardTotal += player[j].yards[i];
            touchdownTotal += player[j].touchdowns[i];
            interceptionTotal += player[j].interceptions[i];
        }
        for (int i = 0; i < STATROWS; i++)
        {
            a = ((completionTotal / attemptTotal) - 0.3) * 5;
            b = ((yardTotal / attemptTotal) - 3) * 0.25;
            c = (touchdownTotal / attemptTotal) * 20;
            d = 2.375 - ((interceptionTotal / attemptTotal) * 25);
        }
        if (a < 0.0)
        {
            a = 0.0;
        }
        else if (a > 2.375)
        {
            a = 2.375;
        }
        if (b < 0.0)
        {
            b = 0.0;
        }
        else if (b > 2.375)
        {
            b = 2.375;
        }
        if (c < 0.0)
        {
            c = 0.0;
        }
        else if (c > 2.375)
        {
            c = 2.375;
        }
        if (d < 0.0)
        {
            d = 0.0;
        }
        else if (d > 2.375)
        {
            d = 2.375;
        }
        passerRating = (a + b + c + d) / 0.06;
        cout << player[j].firstName << " " << player[j].lastName << endl;
        cout << passerRating << " passer Rating" << endl;
    }
}
void menu(qb* player, ifstream &file)
{
    int choice;
    cout << "1: Print player\n2: Print player stats\n3: Print passer ratings\n4: Exit" << endl;
    cin >> choice;
    if (choice == 1)
    {
        printPlayer(player, file);
       // getInfo(player);
        menu(player, file);
    }
    else if (choice == 2)
    {
        printPlayerStats(player, file);
        menu(player, file);
    }
    else if (choice == 3)
    {
        printPasserRating(player);
        menu(player, file);
    }
    else if (choice == 4)
    {
        exit(0);
    }
    else
    {
        menu(player, file);
    }
}
int main()
{
    qb *player = new qb[4];
    ifstream file;
    file.open("QBInfo.txt");
    getInfo(player, file);

    menu(player, file);

    return 0;
}

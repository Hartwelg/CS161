/**
  * @author Gauge Hartwell
  * @brief Assignment 8
  **/

#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 12;
const int SEATS = 6;
/**
 * @brief makeArray
 * @param array
 */
void makeArray(char array[][SEATS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < SEATS; j++)
        {
            array[i][j] = '*';
        }
    }
}
/**
 * @brief printChart
 * @param array - seating chart for an airplane
 */
void printChart(char array[][SEATS])
{
    cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;

    for (int i = 0; i < ROWS; i++)
    {
        cout << left << setw(3) << "row " << setw(2) << i + 1;
        for (int j = 0; j < SEATS; j++)
        {
            cout << right << setw(6) << array[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
/**
 * @brief emptyCount
 * @param array - array of seats on the airplane. used to keep track of empty seats
 * @return number of empty seats
 */
int emptyCount(char array[][SEATS])
{
int empty = 0;
int window = 0;
int aisle = 0;

for (int i = 0; i < ROWS; i++)
{
    for (int j = 0; j < SEATS; j++)
    {
        if (array[i][j] == '*')
        {
            empty++;

            if (j == 0 || j == 5)
            {
                window++;
            }
            else if (j == 2 || j == 3)
            {
                aisle++;
            }
        }

    }
}
cout << "There are " << empty << " seats available." << window << " window seats, and " << aisle << " aisle seats." << endl;
return 0;
}
/**
 * @brief fillSeat
 * @param array - the seating chart for the airplane. used to keep track of seats already taken
 */
void fillSeat(char array[ROWS][SEATS])
{
    int row, column;
    char seat;
    cout << "Enter seat location: ";
    cin >> row >> seat;

    if (seat == 'A')
    {
        column = 0;
    }
    if (seat == 'B')
    {
        column = 1;
    }
    if (seat == 'C')
    {
        column = 2;
    }
    if (seat == 'D')
    {
        column = 3;
    }
    if (seat == 'E')
    {
        column = 4;
    }
    if (seat == 'F')
    {
        column = 5;
    }
    if (array[row - 1][column] == 'X')
    {
        cout << "This seat is already taken" << endl;
        fillSeat(array);
    }
    else
    {
        array[row - 1][column] = 'X';
        cout << "Thank you. Your seat has been reserved." << endl;
    }
}

/**
 * @brief menu
 * @param array - the seating chart for the airplane
 */
void menu(char array[ROWS][SEATS])
{
    int choice = 0;
    cout << "1: Print Chart\n2: Fill Seat\n3: Empty Count\n4: exit\n";
    cin >> choice;
    if (choice == 1)
    {
        printChart(array);
        menu(array);
    }
    else if (choice == 2)
    {
        fillSeat(array);
        menu(array);
    }
    else if (choice == 3)
    {
        emptyCount(array);
        menu(array);
    }
    else if (choice == 4)
    {
        exit;
    }
    else
    {
        menu(array);
    }
}

int main()
{
    //makeArray(array);
    char seats[ROWS][SEATS];
    makeArray(seats);
    menu(seats);
}

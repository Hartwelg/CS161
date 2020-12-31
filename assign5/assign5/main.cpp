/**
 * @brief assignment 5
 * @author Gauge Hartwell
 **/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ifstream inFile;

    inFile.open("images.txt");

    cout  << left << setw(30) << "Name" <<  left << setw(10) << "Type" << left << setw(10) << "Width" << left << setw(10) << "Height" << left << setw(10) << "Size" << endl;

    double size, totalSize;

    while(!inFile.eof())
    {
        string line, extra;

        inFile >> line >> extra >> size;

        if (inFile.fail())
        {
            break;
        }

        string name, type, width, height;

        int endOfAddress, spaceLocation, namePos, questionMark, xLocation;

        endOfAddress = line.find_last_of('/');

        spaceLocation = line.find_first_of(' ');

        namePos = line.find_last_of('.');

        questionMark = line.find('?');

        name = line.substr(endOfAddress + 1, questionMark - endOfAddress - 1);

        type = line.substr(namePos + 1, questionMark - namePos - 1);

        xLocation = line.find('x');

        width = line.substr(questionMark + 1, xLocation - questionMark - 1);

        height = line.substr(xLocation + 1, spaceLocation - xLocation - 1);

        size = size / 1024;

        cout << left << setw(30) << name << left << setw(10) << type << left << setw(10) << width << left << setw(10) << height << left << setw(10) << fixed << setprecision(1) << size << endl;
        totalSize = totalSize + size;
    }
    cout << right << setw(60) << "Total size is: " << setprecision(1) << ceil(totalSize * 100) / 100 << endl;
}

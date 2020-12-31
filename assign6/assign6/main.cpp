/**
  * @brief assignment 6
  * @author Gauge Hartwell
  * collaberated with Abby Presley on this assignment
  **/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief getInteger
 * @param prompt - prompts the user for a number to be used in the calculation
 * @return - the number entered
 */
int getInteger(const string& prompt)
{
    int number;

    cout << prompt;
    cin >> number;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << prompt;
        cin >> number;
    }
    return number;
}
/**
 * @brief getArea - gets the overall surface area of the sheet to be cut
 * @param width - width of the box
 * @param length - length of the box
 * @return surface area of the sheet to be cut for the box, using width and height
 */
int getArea(int width, int length)
{
    int area;
    area = width * length;
    return area;
}
/**
 * @brief getVolume - gets the overall volume of the box
 * @param width - width of the box
 * @param length - length of the box
 * @param height - height of the box
 * @return - volume of the box, using width, height, and length
 */
int getVolume(int width, int length, int height)
{
    int volume;
    volume = getArea(width, length) * height;
    return volume;
}
/**
 * @brief getMaxHeight - gets the maximum height of the walls of the box
 * @param width - width of the cardboard to be cut
 * @param length - length of the cardboard to be cut
 * @return - maximum height of the walls of the box
 */
int getMaxHeight(int width, int length)
{
    int height, volume;
    volume = getVolume(width, length, height);

    height = volume / width / length;
    return height;
}
/**
 * @brief getWaste - gets the material wasted per box created
 * @param cutoutSize - the size of the corners of the sheet to be cut
 * @return - waste material
 */
int getWaste(int cutoutSize)
{
    int waste;
    waste = cutoutSize * cutoutSize * 4;
    return waste;
}
/**
 * @brief getBoxStats - gets all of the information about the box
 * @param width - width of the box
 * @param length - length of the box
 * @param height - height of the box
 * @param volume - volume of the box
 * @param waste - overall waste produced when box is made
 */
void getBoxStats(int width, int length, int height, int& volume, int& waste)
{
    volume = getVolume(width, length, height);
    waste = getWaste(height);
}
/**
 * @brief findShortestMeasure - finds the shortest measure between length and width
 * @param width - given width of cardboard
 * @param length - given length of cardboard
 * @return - shortest length
 */
int findShortestMeasure(int width, int length)
{
    if (width < length)
    {
        return width;
    }
    else
    {
        return length;
    }
}
int main()
{
    int width, length, height, volume, waste, newWidth, newLength, shortestMeasure;

    width = getInteger("Enter width: ");
    length = getInteger("Enter length: ");

    height = getMaxHeight(width, length);

    cout << height << endl;

    getBoxStats(width, length, height, volume, waste);

    shortestMeasure = findShortestMeasure(width, length);

    cout << left << setw(10) << "Height" << left << setw(10) << "Width" << left << setw(10) << "Length" << left << setw(10) << "Volume" << left << setw(10) << "Waste Area" << endl;
   // cout << left << setw(10) << height << left << setw(10) << width << left << setw(10) << length << left << setw(10) << volume << left << setw(10) << waste << endl;

    for (int i = 0; i < height; i++)
    {

        if (height == 0)
        {
            break;
        }
        else if (height > shortestMeasure / 2 - 1)
        {
            break;
        }
        newWidth = width - (height * 2);
        newLength = length - (height * 2);
        getBoxStats(newWidth, newLength, height, volume, waste);

        cout << left << setw(10) << height << left << setw(10) << newWidth << left << setw(10) << newLength << left << setw(10) << volume << left << setw(10) << waste << endl;

        height++;

    }

}

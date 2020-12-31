/**
  * @author Gauge Hartwell
  * @brief assignment 7
  **/
#include <iostream>
#include <Cmath>

using namespace std;

/**
 * @brief getData
 * @param heights - array of elevations used for the program
 * @param size - size of the array
 */
void getData(int heights[], int size)
{
    cout << "Enter " << size << " elevations: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> heights[i];
    }
}
/**
 * @brief getHighestPointBetween
 * @param heights - array of elevations along the hike route
 * @param startMile - starting point for measurement
 * @param endMile - ending point for measurement
 * @return highest point between two points along the hike
 */
int getHighestPointBetween(const int heights[], int startMile, int endMile)
{
    int highestPoint = 0;
    for (int i = startMile; i < endMile; i++)
    {
        if (heights[i] > highestPoint)
        {
            highestPoint = heights[i];
        }
    }
    return highestPoint;
}
/**
 * @brief getAverage
 * @param heights - array of the heights at each elevation
 * @param size - size of the array
 * @return teh average of all of the heights on the hike
 */
double getAverage(const int heights[], int size)
{
    double average = 0;
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += heights[i];
    }
    average = total / size;
    return average;
}
/**
 * @brief getNumPeaks
 * @param heights - array of all of the elevations
 * @param size - size of the array
 * @return the number of peaks in the hike
 */
int getNumPeaks(const int heights[], int size)
{
   int numPeaks = 0;
   for (int i = 0; i < size - 1; i++)
   {
       if (heights[i] > heights[i - 1])
       {
           if (heights[i + 1] < heights[i])
           {
               numPeaks += 1;
           }

       }
       else
       {
           continue;
       }
   }
   return numPeaks;
}
/**
 * @brief getNumSteepSegments
 * @param heights - elevation points on the hike
 * @param size - size of the array of elevation points
 * @return number of steep segments on the hike
 */
int getNumSteepSegments(const int heights[], int size)
{
    int steepSegmentNum = 0;
    for (int i = 0; i < size; i++)
    {
        if (heights[i] <= heights[i + 1] - 1000 || heights[i] >= heights[i - 1] + 1000)
        {
            steepSegmentNum += 1;
        }
    }
    return steepSegmentNum;
}
/**
 * @brief getTotalChange
 * @param heights - array of elevations on the hike
 * @param startMile - starting point of measurement of elevation change
 * @param endMile - ending point of measurement of elevation change
 * @return total change in elevation along the route
 */
int getTotalChange(const int heights[], int startMile, int endMile)
{
    int totalChange = 0;
    int change = 0;
  for (int i = startMile; i < endMile - 1; i++)
    {
        if (heights[i] < heights[i + 1])
        {
            change = heights[i + 1] - heights[i];
        }
        else if (heights[i] > heights[i + 1])
        {
            change = heights[i] -  heights[i + 1];
        }
        totalChange += change;
    }
    return totalChange;
}
int main()
{
    const int HIKE_LENGTH = 9;
    int heights[HIKE_LENGTH];
    getData(heights, HIKE_LENGTH);
    cout << "Highest Points: " << endl;
    cout << "\tFirst half: " << getHighestPointBetween(heights, 0, HIKE_LENGTH / 2) << endl;
    cout << "\tSecond half: " << getHighestPointBetween(heights, HIKE_LENGTH % 2 + HIKE_LENGTH / 2, heights[HIKE_LENGTH]) <<  endl;
    cout << "\tOverall: " << getHighestPointBetween(heights, 0, HIKE_LENGTH) << endl;
    cout << "Average elevation: " << getAverage(heights, HIKE_LENGTH) << endl;
    cout << "Peaks: " << getNumPeaks(heights, HIKE_LENGTH) << endl;
    cout << "Difficult segments: " << getNumSteepSegments(heights, HIKE_LENGTH) << endl;
    cout << "Elevation change: " << getTotalChange(heights, 0, HIKE_LENGTH) << endl;
}

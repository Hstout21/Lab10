/**
 *   @file: Lab10.cc
 * @author: Hunter Stout
 *   @date: 10/29/2021
 *  @brief: Ifstream & array practice assignment.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

/**
 * findMin - finds the minimum price inside data1.txt, also adjusts the name accordingly.
 * @param prices - Array for prices inside data1.txt
 * @param names - Array for names inside data2.txt
 * @param min - Minimum price found inside data1.txt
 * @param minName - Name aligned with minimum price found from the prices array.
 * @param void - Void used so we can return min & minName to the main function.
 */
void findMin(double prices[], string names[], double &min, string &minName);

/**
 * findMax - finds the maximum price inside data1.txt, also adjusts the name accordingly.
 * @param prices - Array for prices inside data1.txt
 * @param names - Array for names inside data2.txt
 * @param max - Maximum price found inside data1.txt
 * @param maxName - Name aligned with maximum price found from the prices array.
 * @param void - Void used so we can return max & maxName to the main function.
 */
void findMax(double prices[], string names[], double &max, string &maxName);

//Main function, used for streams, loading arrays, calling functions, & informing the terminal our results.
int main(int argc, char const *argv[]) {

    //Prices stream (instream1), Names stream (instream2).
    ifstream inStream1, inStream2;
    //Prices array and placeholder for first input.
    double prices[6];
    double input1;
    //Array counter.
    int i = 0;
    //Names array and placeholder for second input.
    string names[6];
    string input2;
    //Min and max values.
    double min, max;
    //Min and max names.
    string minName, maxName;

    //First instream (grabs prices from data1.txt).
    inStream1.open("data1.txt");
        //First instream fail check.
        if (inStream1.fail()) {
            cout << " " << endl;
            cout << "Error we could not locate data1.txt. Try again" << endl;
            exit (0);
        }

        //Input and loop to load prices into first array.
        inStream1 >> input1;
        while (i != 6) {
            prices[i] = input1;
            i++;
            inStream1 >> input1;
        }
        //Reset array counter.
        i = 0;

    //Second instream (grabs names from data2.txt).
    inStream2.open("data2.txt");
        //Second instream fail check.
        if (inStream2.fail()) {
            cout << " " << endl;
            cout << "Error we could not locate data2.txt. Try again" << endl;
            exit (0);
        }
    
        //Input and loop to load names into second array.
        inStream2 >> input2;
        while (i != 6) {
            names[i] = input2;
            i++;
            inStream2 >> input2;
        }
        //Reset array counter.
        i = 0;

        //Calls functions to find min & max prices/names.
        findMin(prices, names, min, minName);
        findMax(prices, names, max, maxName);

        //Main program terminal output.
        cout << fixed << setprecision(2) << endl;
        cout << "Least expensive part: " << minName << " ($" << min << ")." << endl;
        cout << "Most expensive part: " << maxName << " ($" << max << ")." << endl;

        //Close both streams.
        inStream1.close();
        inStream2.close();

    return 0;
}
//Function used to find minimum price/name.
void findMin (double prices[], string names[], double &min, string &minName) {

    //Initially declares minimum value to check entire array.
    min = prices[0];
    //Loop to check each price in array, then correctly adjust both price and name.
    for (size_t i = 0; i < 6; i++){
        if (prices[i] < min){
            min = prices[i];
            minName = names[i];
        }
    }
    //If statement used to adjust the name of minimum price if the min never changes inside the loop.
    if (min == prices[0]) {
        minName = names[0];
    }
}
//Function used to find maximum price/name.
void findMax (double prices[], string names[], double &max, string &maxName) {

    //Initially declares maximum value to check entire array.
    max = prices[0];
        //Loop to check each price in array, then correctly adjust both price and name.
    for (size_t i = 0; i < 6; i++){
        if (prices[i] > max){
            max = prices[i];
            maxName = names[i];
        }
    }
}
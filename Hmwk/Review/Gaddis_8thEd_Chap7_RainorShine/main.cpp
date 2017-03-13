/*
 * File:   Rain or Shine
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 7:18 PM
 * Purpose: 7.6
    An amateur meteorologist wants to keep track of weather conditions during the
    past year’s three-month summer season and has designated each day as either rainy
    (‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this information in a
    3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July,
    2 = August) and the column indicates the day of the month. Note that data are not
    being collected for the 31st of any month. The program should begin by reading the
    weather data in from a file. Then it should create a report that displays, for each
    month and for the whole three-month period, how many days were rainy, how many
    were cloudy, and how many were sunny. It should also report which of the three
    months had the largest number of rainy days. Data for the program can be found in
    the RainOrShine.txt file.
 */

#include <iostream>   //Input/Output objects
#include <iomanip>
#include <fstream>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned short MNTH = 3;
const unsigned short DAYS = 30;
const unsigned short COND = 3;

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    ifstream weather("RainOrShine.txt");
    char data[MNTH][DAYS];
    unsigned short count[MNTH][COND] = {};
    unsigned short tot[COND] = {};

    //Input values
    if (weather){
        for (int i = 0; i < MNTH; i++) weather >> data[i];
    } else cout << "File opened unsuccessfully.\n";

    //Process values -> Map inputs to Outputs
    for (int i = 0; i < MNTH; i++){
        for (int j = 0; j < DAYS; j++){
            if (data[i][j] == 'C'){
                count[i][0]++; 
                tot[0]++;
            }

            if (data[i][j] == 'R'){
                count[i][1]++;
                tot[1]++;
            }

            if (data[i][j] == 'S'){
                count[i][2]++;
                tot[2]++;
            }
        }
    }

    //Display Output
    for (int i = 0; i < MNTH; i++){
        cout << i << ": ";

        for (int j = 0; j < DAYS; j++) cout << data[i][j];
        cout << endl;
    }

    //Display weather table
    cout << "\n         C  R  S" << endl;
    for (int i = 0; i < 3; i++){
        switch(i){
            case 0: cout << "June:   "; break;
            case 1: cout << "July:   "; break;
            case 2: cout << "August: "; break;
        }

        for (int j = 0; j < 3; j++) cout << fixed << setw(2) << count[i][j] << " ";

        cout << endl;
    }
    
    cout << "T:      ";
    for (int i = 0; i < COND; i++) cout << fixed << setw(2) << tot[i] << " ";
    cout << "\n\n";
    
    if (count[0][1] > count[1][1] && count[0][1] > count[2][1]) cout << "June had most rain.\n";
    if (count[1][1] > count[0][1] && count[1][1] > count[2][1]) cout << "July had most rain.\n";
    if (count[2][1] > count[0][1] && count[2][1] > count[1][1]) cout << "August had most rain.\n";

    //Exit Program
    return 0;
}
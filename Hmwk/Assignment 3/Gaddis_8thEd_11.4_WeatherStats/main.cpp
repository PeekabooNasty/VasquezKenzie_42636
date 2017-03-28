/* 
 * File:   Weather Statistics
 * Author: Kenzie Vasquez
 * Created on March 22, 2017, 11:42 AM
 * Purpose: 
    Write a program that uses a structure to store the following weather data 
    for a particular month. The program should have an array of 12 structures to 
    hold weather data for an entire year.
        Total Rainfall
        High Temperature
        Low Temperature
        Average Temperature 

    Once the data are entered for all the months, the program should calculate 
    and display the average monthly rainfall, the total rainfall for the year, 
    the highest and lowest temperatures for the year (and the months they 
    occurred in), and the average of all the monthly average temperatures.

    Input Validation: Only accept temperatures within the range between –100 and +140
    degrees Fahrenheit.
 */

#include <iostream>
using namespace std;

#include "Weather.h"

Weather *data(const int);

int main(int argc, char** argv) {
    const int MNTHS = 12;
    Weather *months = data(MNTHS);
    
    delete [] months;

    return 0;
}

Weather *data(const int M){
    Weather *ptr = new Weather[M];
    short low = 0, 
          high;
    ptr->SIZE = M;
    
    //Enter Total Rainfall, High Temp, Low Temp and Avg Temp for each month
    for(int i = 0; i < ptr->SIZE; i++){
        do {
            cout << "Enter the highest temp for Month #" << i + 1 << ": ";
            cin >> ptr[i].hiTemp; cin.ignore();
        } while(ptr[i].hiTemp < -100 || ptr[i].hiTemp > 140);
        
        do {
            cout << "Enter the lowest temp for Month #" << i + 1 << ": ";
            cin >> ptr[i].lowTemp; cin.ignore();
            
            if (ptr[i].lowTemp > ptr[i].hiTemp){
                cout << "The lowest temp needs to be lower than the highest!\n";
            }
        } while(ptr[i].lowTemp < -100 || ptr[i].lowTemp > 140 && ptr[i].lowTemp > ptr[i].hiTemp);
        
        //Calculate total and average temperature
        ptr[i].avgTemp = (ptr[i].hiTemp + ptr[i].lowTemp) / 2;
        ptr->totRain += (ptr[i].hiTemp + ptr[i].lowTemp);
    }
    
    cout << endl;
    for(int i = 0; i < ptr->SIZE; i++){
        cout << "Avg temp for Month #" << i + 1 << ": " << ptr[i].avgTemp << endl;
    }
    
    return ptr;
}
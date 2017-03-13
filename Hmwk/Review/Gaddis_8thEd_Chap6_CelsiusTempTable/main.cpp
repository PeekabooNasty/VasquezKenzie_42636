/* 
 * File:   Celsius Temperature Table
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 6:40 PM
 * Purpose: 
    Write a function named celsius that accepts a Fahrenheit temperature as an 
 *  argument. The function should return the temperature, converted to Celsius. 
 *  Demonstrate the function by calling it in a loop that displays a table of 
 *  the Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
 */

#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
float celsius(const float);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    float fahrenheit, c;
    
    //Input values
    
    //Process values -> Map inputs to Outputs
    
    //Display Output
    for (int i = 0; i < 20; i++){
        fahrenheit = i + 1;
        
        cout << fixed << setprecision(2);
        cout << fahrenheit << "F = " << celsius(fahrenheit) << "C\n";
    }

    //Exit Program
    return 0;
}

float celsius(const float f){
    return 5/9.0 * (f - 32);
}
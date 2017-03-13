/* 
 * File:   main.cpp
 * Author: Kenzie
 *
 * Created on February 22, 2017, 7:21 AM
 */

#include <iostream>   //Input/Output objects

using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!

int main(int argc, char** argv){
    //Declaration of Variables
    float c; //Celsius

    //Input values
    cout << "Enter a degree in Celcius and I will convert it to Fahrenheit.\n";
    cin >> c; cin.ignore();

    //Process values -> Map inputs to Outputs

    //Display Output
    cout << c << "C = " << c * 1.8 + 32 << "F";

    //Exit Program
    return 0;
}
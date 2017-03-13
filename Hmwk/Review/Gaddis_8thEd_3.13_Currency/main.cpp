/* 
 * File:   Currency 
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 9:57 AM
 * Purpose: Convert US dollar to Yen and Euros. 
   Format your currency amounts in fixed-point notation, with two decimal places of
   precision, and be sure the decimal point is always displayed.
 */

#include <iostream>  //I/O objects
#include <iomanip>   //I/O manipulation
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!

int main(int argc, char** argv){
    //Declaration of Variables
    const float DOLTOYEN = 113.521; // $1 USD = 113.521 Yen (xe.com)
    const float DOLTOEUR = 0.94889; // $1 USD = 0.94889 Euros (xe.com)
    float dollar, yen, euro;        // User's dollar, converted yen and euro

    //Input values
    cout << "Enter an amount of US Dollars and I will convert it to Yen and Euros.\n";
    cin >> dollar; cin.ignore();
    
    //Process values -> Map inputs to Outputs
    yen = dollar * DOLTOYEN;
    euro = dollar * DOLTOEUR;
    
    //Display Output
    cout << fixed << setprecision(2) << showpoint;
    cout << "$" << dollar << " USD = ‎¥" << yen << endl;
    cout << "$" << dollar << " USD = ‎€" << euro << endl;
    
    //Exit Program
    return 0;
}
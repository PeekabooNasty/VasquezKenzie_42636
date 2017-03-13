/* 
 * File:   4.10 Days in a Month
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 10:33 AM
 * Purpose: Write a program that asks the user to enter the month (letting the 
 * user enter an integer in the range of 1 through 12) and the year. The program 
 * should then display the number of days in that month.
 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!

int main(int argc, char** argv){
    //Declaration of Variables
    int mnth, yr;
    
    //Input values
    do {
        cout << "Enter a month (1-12): ";
        cin >> mnth; cin.ignore();
    } while(mnth < 0 || mnth > 12);
    
    do {
        cout << "Enter a year: ";
        cin >> mnth; cin.ignore();
    } while(yr < 0);

    //Process values -> Map inputs to Outputs
    if (mnth==1 || mnth==3 || mnth==5 || mnth==7 || mnth==8 || mnth==10 || mnth==12){
        cout << "There are 31 days in the month.\n";
    }
    else if (mnth==4 || mnth==6 || mnth==9 || mnth==11){
        cout << "There are 30 days in the month.\n";
    }
    else {
        if (yr % 100 == 0){
            if ((yr % 400) == 0) cout << "There are 29 days in the month.\n";
            else cout << "There are 28 days in the month.\n";
        }
        else cout << ((yr % 4 == 0) ? "There are 29 days in the month.\n" : "There are 28 days in the month.\n");
    }
    
    //Display Output

    //Exit Program
    return 0;
}
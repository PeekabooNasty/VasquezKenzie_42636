/* 
 * File:   Population
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 1:01 PM
 * Purpose: 
    Write a program that will predict the size of a population of organisms. The program
    should ask the user for the starting number of organisms, their average daily population
    increase (as a percentage), and the number of days they will multiply. A loop
    should display the size of the population for each day.
 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    int days;
    float perc, pop;
    
    //Input values
    cout << "Enter a starting population: ";
    cin >> pop; cin.ignore();
    
    cout << "Enter the average daily increase as a percentage: ";
    cin >> perc; cin.ignore();
    
    perc /= 100;
    
    cout << "How many days would you like the population to multiply? ";
    cin >> days; cin.ignore();
    
    //Process values -> Map inputs to Outputs
    for (int i = 0; i < days; i++){
        pop += pop * perc;
        cout << "Day " << i + 1 << " population: " << pop << endl;
    }
    
    //Display Output

    //Exit Program
    return 0;
}
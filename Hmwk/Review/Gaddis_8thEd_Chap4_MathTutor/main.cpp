/* 
 * File:   Math Tutor
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 11:14 AM
 * Purpose: The program should display two random numbers that are to be added &
 * should wait for the student to enter the answer. If the answer is correct, a 
 * message of congratulations should be printed. If the answer is incorrect, a 
 * message should be printed showing the correct answer.
 */

#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number seed
#include <ctime>      //Seed the random number generator
#include <cctype>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!

int main(int argc, char** argv){
    //Declaration of Variables
    srand(static_cast<unsigned int>(time(0)));
    unsigned short op1,
                   op2,
                   answer,
                   sum;
    char choice;
    
    //Input values
    do {
        op1 = rand() % 900 + 100;
        op2 = rand() % 900 + 100;
        sum = op1 + op2;

        //Process values -> Map inputs to Outputs
        cout << "Solve.\n";
        cout << op1 << " + " << op2 << " = ";
        cin >> answer; cin.ignore();

        //Display Output
        if (answer == sum) cout << "Correct!\n";
        else cout << "Sorry, the answer was " << sum << "." << endl;

        do {
            cout << "Would you like to try another problem? (y/n)\n";
            cin >> choice; cin.ignore();
            choice = static_cast<char>(tolower(choice));
        } while(choice != 'y' && choice != 'n');
    } while(choice == 'y');

    //Exit Program
    return 0;
}
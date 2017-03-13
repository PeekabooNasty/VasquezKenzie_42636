/* 
 * File:   Odd and Even Numbers of a Random Array
 * Author: Kenzie Vasquez
 * Created on March 11, 2017, 10:34 PM
 */

#include <iostream> //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int *randArr(const int);
void oddEven(int *, const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    int size;
    int *ptr = nullptr;
    
    //Input values
    cout << "Enter a size for the dynamically allocated array: ";
    cin >> size; cin.ignore();

    //Process values -> Map inputs to Outputs
    ptr = randArr(size);
    
    //Display Output
    oddEven(ptr, size);
            
    delete [] ptr;
    
    //Exit Program
    return 0;
}

int *randArr(const int SIZE){
    srand(static_cast<unsigned>(time(0)));
    int *dynArr = new int [SIZE];
    
    for (int i = 0; i < SIZE; i++) *(dynArr + i) = rand() % 100 + 100;
    
    return dynArr;
}

void oddEven(int *ptr, const int SIZE){
    cout << "Evens: \n";
    for (int i = 0; i < SIZE; i++){
        if (!(*(ptr + i) % 2)) cout << *(ptr + i) << endl;
    }
    
    cout << "\nOdds: \n";
    for (int i = 0; i < SIZE; i++){
        if (*(ptr + i) % 2) cout << *(ptr + i) << endl;
    }
}
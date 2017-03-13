/* 
 * File:   Array Allocator
 * Author: Kenzie Vasquez
 * Created on March 6, 2017, 7:01 PM
 * Purpose: 
    Write a function that dynamically allocates an array of integers. The function should
    accept an integer argument indicating the number of elements to allocate. The function
    should return a pointer to the array.
 */

#include <iostream> //Input/Output objects
#include <cstdlib>  //C Standard Library
#include <ctime>    //C Time
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int *dynaMem(const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    int size = 0;
    int *ptr = nullptr;
    
    //Input values
    do {
        cout << "Enter a size for dynamic array (1-10): ";
        cin >> size; cin.ignore();
    } while(size < 1 || size > 10);

    //Process values -> Map inputs to Outputs
    ptr = dynaMem(size);
    
    //Display Output
    for (int i = 0; i < size; i++) cout << (ptr + i) << ": " << *(ptr + i) << endl;
    
    delete [] ptr;
    
    //Exit Program
    return 0;
}

int *dynaMem(const int SIZE){
    srand(static_cast<unsigned int>(time(0)));
    int *ptr = new int [SIZE];
    
    for (int i = 0; i < SIZE; i++) *(ptr + i) = rand() % 9;
    
    cout << "Startic address in function: " << ptr << endl;
    
    return ptr;
}
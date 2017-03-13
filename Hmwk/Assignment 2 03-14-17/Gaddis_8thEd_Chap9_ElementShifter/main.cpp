/* 
 * File:   Element Shifter
 * Author: Kenzie Vasquez
 * Created on March 11, 2017, 11:14 PM
 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int *shifter(int [], const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    const int SIZE = 100;
    int numbers[SIZE];
    int *ptr = nullptr;
    
    //Input values
    for (int i = 0; i < SIZE; i++) numbers[i] = i + 1;

    //Process values -> Map inputs to Outputs
    ptr = shifter(numbers, SIZE);
    
    //Display Output
    for (int i = 0; i < SIZE; i++) cout << *(ptr + i) << endl;
    
    delete [] ptr;
    
    //Exit Program
    return 0;
}

int *shifter(int arr[], const int SIZE){
    int *dynArr = new int [SIZE + 1];
    
    *dynArr = 0;
    
    for (int i = 0; i < SIZE; i++) *(dynArr + i + 1) = arr[i];
    
    return dynArr;
}
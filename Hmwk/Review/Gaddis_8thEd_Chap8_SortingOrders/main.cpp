/* 
 * File:   Sorting Orders
 * Author: Kenzie Vasquez
 * Created on February 28, 2017, 1:25 PM
 * Purpose: 8.10
    Write a program that uses two identical arrays of just eight integers. It should display
    the contents of the first array, then call a function to sort the array using an ascending
    order bubble sort modified to print out the array contents after each pass of the sort.
    Next, the program should display the contents of the second array, then call a function
    to sort the array using an ascending order selection sort modified to print out the array
    contents after each pass of the sort.
 */

#include <iostream>   //Input/Output objects
#include <cstdlib>
#include <ctime>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void bubSort(unsigned short [], const unsigned short);
void selSort(unsigned short [], const unsigned short);

//Execution Begins Here!
int main(int argc, char** argv){
    //Seed the random number generator
    srand(static_cast<unsigned>(time(0)));
    
    //Declaration of Variables
    const unsigned short SIZE = 8;
    unsigned short arr1[SIZE] = {};
    unsigned short arr2[SIZE] = {};

    //Input values
    for (int i = 0; i < SIZE; i++) arr2[i] = arr1[i] = rand() % 9;

    //Process values -> Map inputs to Outputs
    cout << "Original array:\n";
    for (int i = 0; i < SIZE; i++) cout << arr1[i] << " ";
    cout << "\n\nBubble sort:\n";
    bubSort(arr1, SIZE);
    
    cout << "\nSelection sort:\n";
    selSort(arr2, SIZE);

    //Display Output
    for (int i = 0; i < SIZE; i++) cout << arr1[i] << " ";

    //Exit Program
    return 0;
}

void bubSort(unsigned short arr[], const unsigned short SIZE){
    for (int i = 0; i < SIZE - 1; i++){
        for (int j = i + 1; j < SIZE; j++){
            if (arr[i] > arr[j]){
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
            
            //Display contents of array after each pass of the bubble sort
            for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
}

void selSort(unsigned short arr[], const unsigned short SIZE){
    int minInd, minVal;
    
    for (int i = 0; i < SIZE - 1; i++){
        minInd = i;
        minVal = arr[i];
        
        for (int j = i + 1; j < SIZE; j++){
            if (arr[i] < 0){
                minVal = arr[i];
                minInd = j;
            }
        }
        
        arr[minInd] = arr[i];
        arr[i] = minVal;
        
        //Display contents of array after each pass of the bubble sort
        for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
        cout << endl;
    }
}
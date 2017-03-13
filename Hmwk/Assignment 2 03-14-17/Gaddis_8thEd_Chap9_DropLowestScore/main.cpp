/* 
 * File:   Drop Lowest Score
 * Author: Kenzie Vasquez
 * Created on March 7, 2017, 6:44 PM
 * Purpose:
    Modify Problem 2 above so the lowest test score is dropped. This score 
    should not be included in the calculation of the average.
 */

#include <iostream>  //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void selSort(int *, const int);
float avg(int [], const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    unsigned size;
    float average;
    
    //Input values
    do {
        cout << "How many test scores would you like to enter (1-6)? ";
        cin >> size; cin.ignore();
    } while(size < 1 || size > 6);
    
    int *scores = new int[size];

    //Process values -> Map inputs to Outputs
    cout << "Enter your test scores as integers only (1-100):\n";
    for (int i = 0; i < size; i++){
        do {
            cout << "Test score #" << i + 1 << ": ";
            cin >> *(scores + i); cin.ignore();
        } while(*(scores + i) < 1 || *(scores + i) > 100);
    }
    
    selSort(scores, size);
    average = avg(scores, size);
    
    //Display Output
    cout << "\nNew test score order:\n";
    for (int i = 0; i < size; i++){
        cout << *(scores + i) << " ";
    }
    
    cout << "\nAverage of dynamic array: " << average << endl;
    
    delete [] scores;
    
    //Exit Program
    return 0;
}

void selSort(int *arr, const int SIZE){
    unsigned int minInd, minVal;
    
    for (int i = 0; i < SIZE - 1; i++){
        minInd = i;
        minVal = *(arr + i);
        
        for (int j = i + 1; j < SIZE; j++){
            if (*(arr + j) < minVal){
                minVal = *(arr + j);
                minInd = j;
            }
        }
        arr[minInd] = *(arr + i);
        *(arr + i) = minVal;
    }
}

float avg(int arr[], const int SIZE){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    
    return (sum - arr[0]) / ((SIZE - 1) * 1.0f);
}
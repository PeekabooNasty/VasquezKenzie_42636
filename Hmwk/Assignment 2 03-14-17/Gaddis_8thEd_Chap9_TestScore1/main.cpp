/* 
 * File:   Test Scores #1
 * Author: Kenzie Vasquez
 * Created on March 6, 2017, 8:19 PM
 * Purpose:
    Write a program that dynamically allocates an array large enough to hold a user defined
    number of test scores. Once all the scores are entered, the array should be
    passed to a function that sorts them in ascending order. Another function should be
    called that calculates the average score. The program should display the sorted list of
    scores and averages with appropriate headings. Use pointer notation rather than array
    notation whenever possible.
 */

#include <iostream>  //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void selSort(int [], const int);
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
    cout << "Enter your test scores (1-100):\n";
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

void selSort(int arr[], const int SIZE){
    unsigned int minInd, minVal;
    
    for (int i = 0; i < SIZE - 1; i++){
        minInd = i;
        minVal = arr[i];
        
        for (int j = i + 1; j < SIZE; j++){
            if (arr[i] < minVal){
                minVal = arr[j];
                minInd = j;
            }
        }
        arr[minInd] = arr[i];
        arr[i] = minVal;
    }
}

float avg(int arr[], const int SIZE){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    
    return sum / (SIZE * 1.0f);
}
/* 
 * File:   Average/Median/Mode
 * Author: Kenzie Vasquez
 * Created on March 8, 2017, 1:40 PM
 * Purpose: Utilize functions that determine avg, median and mode of array
 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void selSort(int [], const int);
float avg(int [], const int);
void median(int [], const int);
void mode(int *arr, const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    const int SIZE = 10;
    int numbers[SIZE] = {4, 4, 6, 2, 42, 67, 10, 11, 14, 90};
    int *freq = nullptr;
    
    //Input values
    cout << "Original array\n";
    for (int i = 0; i < SIZE; i++) cout << numbers[i] << " ";

    //Process values -> Map inputs to Outputs
    selSort(numbers, SIZE);
    
    //Display Output
    cout << "\n\nSorted array\n";
    for (int i = 0; i < SIZE; i++) cout << numbers[i] << " ";
    
    cout << "\n\nAverage: " << avg(numbers, SIZE) << endl;
    
    median(numbers, SIZE);
    mode(numbers, SIZE);
    
    //Exit Program
    return 0;
}

void selSort(int arr[], const int SIZE){
    int minInd, minVal;
    
    for (int i = 0; i < SIZE - 1; i++){
        minInd = i;
        minVal = arr[i];
        
        for (int j = i + 1; j < SIZE; j++){
            if (arr[j] < minVal){
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

void median(int arr[], const int SIZE){
    if (SIZE % 2) cout << "Median is: " << arr[(SIZE / 2) + 1] << endl;
    else cout << "Median is: " << (arr[SIZE / 2 - 1] * 1.0f + arr[SIZE / 2]) / 2 << endl;
}

void mode(int *arr, const int SIZE){
    int *freq = new int [SIZE];
    int large = 1;
    
    //Set all elements equal to 1 (each number already has an occurrence of 1)
    for (int i = 0; i < SIZE; i++) *(freq + i) = 1;
    
    //Count how many times the same number occurred more than once
    for (int i = 0; i < SIZE - 1; i++){
        for (int j = i + 1; j < SIZE; j++){
            if(*(arr + i) == *(arr + j)) freq[i]++;
        }
        
        //Keep track and save new highest occurrence of a number
        if (freq[i] > large) large = *(freq + i);
    }
    
    //Display mode if any
    if (large > 1){
        cout << "Mode numbers: ";
        for (int i = 0; i < SIZE; i++){
            if (*(freq + i) == large) cout << *(arr + i) << " ";
        }
        cout << "\nFrequency: " << large << endl;
    } else cout << "There was no mode.\n";
    
    delete [] freq;
}
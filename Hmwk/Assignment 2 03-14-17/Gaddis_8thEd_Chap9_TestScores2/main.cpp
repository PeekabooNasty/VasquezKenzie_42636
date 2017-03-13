/* 
 * File:   Test Scores #2
 * Author: Kenzie Vasquez
 * Created on March 7, 2017, 7:52 PM
 * Purpose:
    Modify the program of Programming Challenge 2 to allow the user to enter name-score
    pairs. For each student taking a test, the user types the student’s name followed by the
    student’s integer test score. Modify the sorting function so it takes an array holding
    the student names and an array holding the student test scores. When the sorted list
    of scores is displayed, each student’s name should be displayed along with his or her
    score. In stepping through the arrays, use pointers rather than array subscripts.
 */

#include <iostream>  //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void selSort(int *arr, const int);
void selSort(string *arr, const int);
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
    
    string *names = new string[size];
    int *scores = new int[size];

    //Process values -> Map inputs to Outputs
    cout << "Enter your test scores (1-100):\n";
    for (int i = 0; i < size; i++){
        cout << "Student #" << i + 1 << "'s name: ";
        getline(cin, *(names + i));
        
        do {
            cout << "Test score #" << i + 1 << ": ";
            cin >> *(scores + i); cin.ignore();
        } while(*(scores + i) < 1 || *(scores + i) > 100);
    }
    
    selSort(names, size);
    selSort(scores, size);
    average = avg(scores, size);
    
    //Display Output
    cout << "\nNew test score order:\n";
    for (int i = 0; i < size; i++){
        cout << *(names + i) << ": " << *(scores + i) << endl;
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
            if (*(arr + i) < minVal){
                minVal = *(arr + j);
                minInd = j;
            }
        }
        *(arr + minInd) = *(arr + i);
        *(arr + i) = minVal;
    }
}

void selSort(string *arr, const int SIZE){
    unsigned int minInd;
    string minVal;
    
    for (int i = 0; i < SIZE - 1; i++){
        minInd = i;
        minVal = *(arr + i);
        
        for (int j = i + 1; j < SIZE; j++){
            if (*(arr + i) < minVal){
                minVal = *(arr + j);
                minInd = j;
            }
        }
            *(arr + minInd) = *(arr + i);
        *(arr + i) = minVal;
    }
}

float avg(int arr[], const int SIZE){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    
    return sum / (SIZE * 1.0f);
}
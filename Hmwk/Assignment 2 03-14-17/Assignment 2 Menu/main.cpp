/* 
 * File:   Assignment 2 Menu
 * Author: Kenzie Vasquez
 * Created on March 11, 2017, 11:45 PM
 */

#include <iostream>  //Input/Output objects
#include <cstdlib>  //C Standard Library
#include <ctime>    //C Time
#include <cctype>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void problem1();
int *dynaMem(const int);

void problem2();
void selSort2(int *, const int);
float avg2(int [], const int);

void problem3();
int *shifter(int [], const int);

void problem4();
int *randArr(const int);
void oddEven(int *, const int);

void problem5();
int doSomething(int *, int *);

void problem6();
void selSort6(int [], const int);
float avg6(int [], const int);

void problem7();
void selSort7(int *arr, const int);
void selSort7(string *arr, const int);
float avg7(int [], const int);

void problem8();
void selSort(int [], const int);
float avg(int [], const int);
void median(int [], const int);
void mode(int *arr, const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    int menuItm;    //Choice from menu

    //Loop until users exits
    do{
        system("clear");

        do {
            //Prompt for problem for user input
            cout<<"1.  Type 1  for Array Allocator\n";
            cout<<"2.  Type 2  for Drop Lowest Score\n";
            cout<<"3.  Type 3  for Element Shifter\n";
            cout<<"4.  Type 4  for Odd and Even Numbers of a Random Array\n";
            cout<<"5.  Type 5  for Pointer Rewrite\n";
            cout<<"6.  Type 6  for Test Scores #1\n";
            cout<<"7.  Type 7  for Test Scores #2\n";
            cout<<"8.  Type 8  for Mean, Median, Mode\n";
            cin>>menuItm;
        } while(menuItm < 1 || menuItm > 10);

        system("clear");

        //Go to the Problem
        switch(menuItm){
            case 1:  problem1(); break;
            case 2:  problem2(); break;
            case 3:  problem3(); break;
            case 4:  problem4(); break;
            case 5:  problem5(); break;
            case 6:  problem6(); break;
            case 7:  problem7(); break;
            case 8:  problem8(); break;
        }//End the Switch/Case
    } while(menuItm > 0 && menuItm <= 10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

void problem1(){
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
    
    cin.ignore(); cin.get();
}

int *dynaMem(const int SIZE){
    srand(static_cast<unsigned int>(time(0)));
    int *ptr = new int [SIZE];
    
    for (int i = 0; i < SIZE; i++) *(ptr + i) = rand() % 9;
    
    cout << "Startic address in function: " << ptr << endl;
    
    return ptr;
}

void problem2(){
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
    
    selSort2(scores, size);
    average = avg2(scores, size);
    
    //Display Output
    cout << "\nNew test score order:\n";
    for (int i = 0; i < size; i++){
        cout << *(scores + i) << " ";
    }
    
    cout << "\nAverage of dynamic array: " << average << endl;
    
    delete [] scores;
    
    cin.ignore(); cin.get();
}

void selSort2(int *arr, const int SIZE){
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

float avg2(int arr[], const int SIZE){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    
    cout << "\nDropped lowest test score: " << arr[0] << endl;
    
    return (sum - arr[0]) / ((SIZE - 1) * 1.0f);
}

void problem3(){
    //Declaration
    const int SIZE = 100;
    int numbers[SIZE];
    int *ptr = nullptr;
    
    //Input values
    for (int i = 0; i < SIZE; i++) numbers[i] = i + 1;

    //Process values -> Map inputs to Outputs
    ptr = shifter(numbers, SIZE);
    
    //Display Output
    cout << "Shifted all the elements in the array by 1.\n\n";
    for (int i = 0; i < SIZE; i++) cout << *(ptr + i) << endl;
    
    delete [] ptr;
    
    cin.ignore(); cin.get();
    
}

int *shifter(int arr[], const int SIZE){
    int *dynArr = new int [SIZE + 1];
    
    *dynArr = 0;
    
    for (int i = 0; i < SIZE; i++) *(dynArr + i + 1) = arr[i];
    
    return dynArr;
}

void problem4(){
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
    
    cin.ignore(); cin.get();
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

void problem5(){
    //Declaration
    int var1 = 5, var2 = 20;
    
    //Input values

    //Process values -> Map inputs to Outputs
    cout << "doSomething returned: " << doSomething(&var1, &var2) << endl;
    
    cin.ignore(); cin.get();
}

int doSomething(int *x, int *y){
    int temp = *x;  //temp = 5
    *x = *y * 10;   //*x = 200
    *y = temp * 10; //*y = 50
    return *x + *y; //return 250
}

void problem6(){
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
    
    selSort6(scores, size);
    average = avg6(scores, size);
    
    //Display Output
    cout << "\nNew test score order:\n";
    for (int i = 0; i < size; i++){
        cout << *(scores + i) << " ";
    }
    
    cout << "\nAverage of dynamic array: " << average << endl;
    
    delete [] scores;
    
    cin.ignore(); cin.get();
}

void selSort6(int arr[], const int SIZE){
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

float avg6(int arr[], const int SIZE){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    
    return sum / (SIZE * 1.0f);
}

void problem7(){
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
    
    selSort7(names, size);
    selSort7(scores, size);
    average = avg7(scores, size);
    
    //Display Output
    cout << "\nNew test score order:\n";
    for (int i = 0; i < size; i++){
        cout << *(names + i) << ": " << *(scores + i) << endl;
    }
    
    cout << "\nAverage of dynamic array: " << average << endl;
    
    delete [] scores;
    
    cin.ignore(); cin.get();
}

void selSort7(int *arr, const int SIZE){
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

void selSort7(string *arr, const int SIZE){
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

float avg7(int arr[], const int SIZE){
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++){
        sum += arr[i];
    }
    
    return sum / (SIZE * 1.0f);
}

void problem8(){
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
    
    cin.ignore(); cin.get();
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
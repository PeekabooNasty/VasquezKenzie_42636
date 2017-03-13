/*
 * File:   Review
 * Author: Kenzie Vasquez
 * Created on March 1, 2017, 9:49 AM
 * Purpose: Review 03/06/17 (Menu of all programming problems/challenges)
 */

#include <iostream>  //Input/Output objects
#include <iomanip>   //I/O manipulation
#include <cctype>    //Character handling functions
#include <cstdlib>   //Random number seed
#include <ctime>     //Seed the random number generator
#include <fstream>   //File stream objects
#include <string>    //String objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants
const float PI = 3.14159;

const unsigned short MNTH = 3;
const unsigned short DAYS = 30;
const unsigned short COND = 3;

//Function prototypes
//Temperature Conversion
void problem1();

//Currency
void problem2();

//Days in a Month
void problem3();

//Geometry Calculator
void problem4();
void areaCir();
void areaRec();
void areaTri();

//Math Tutor
void problem5();

//Population
void problem6();

//Celsius Temperature Table
void problem7();
float celsius(const float);

//Rain or Shine
void problem8();
void selSort(string [], const int);
int binSrch(string [], const int, string);

//Binary Search
void problem9();

//Sorting Orders
void problem10();
void bubSort(unsigned short [], const unsigned short);
void selSort(unsigned short [], const unsigned short);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    int menuItm;    //Choice from menu

    //Loop until users exits
    do{
        system("clear");

        do {
            //Prompt for problem for user input
            cout<<"1.  Type 1  for Temperature Conversion"<<endl;
            cout<<"2.  Type 2  for Currency"<<endl;
            cout<<"3.  Type 3  for Days in a Month"<<endl;
            cout<<"4.  Type 4  for Geometry Calculator"<<endl;
            cout<<"5.  Type 5  for Math Tutor"<<endl;
            cout<<"6.  Type 6  for Population"<<endl;
            cout<<"7.  Type 7  for Celsius Temperature Table"<<endl;
            cout<<"8.  Type 8  for Rain or Shine"<<endl;
            cout<<"9.  Type 9  for Binary Search"<<endl;
            cout<<"10. Type 10 for Sorting Orders"<<endl;
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
            case 9:  problem9(); break;
            case 10: problem10();
        }//End the Switch/Case
    } while(menuItm > 0 && menuItm <= 10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

void problem1(){
    //Declaration of Variables
    float c; //Celsius

    //Input values
    cout << "Enter a degree in Celcius and I will convert it to Fahrenheit.\n";
    cin >> c; cin.ignore();
    //Process values -> Map inputs to Outputs

    //Display Output
    cout << c << "C = " << c * 1.8 + 32 << "F";

    cout << "\n\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void problem2(){
    //Declaration of Variables
    const float DOLTOYEN = 113.521; // $1 USD = 113.521 Yen (xe.com)
    const float DOLTOEUR = 0.94889; // $1 USD = 0.94889 Euros (xe.com)
    float dollar, yen, euro;        // User's dollar, converted yen and euro

    //Input values
    cout << "Enter an amount of US Dollars\n"
            "and I will convert it to Yen and Euros.\n";
    cin >> dollar; cin.ignore();

    //Process values -> Map inputs to Outputs
    yen = dollar * DOLTOYEN;
    euro = dollar * DOLTOEUR;

    //Display Output
    cout << fixed << setprecision(2) << showpoint;
    cout << "$" << dollar << " USD = ‎¥" << yen << endl;
    cout << "$" << dollar << " USD = ‎€" << euro;

    cout << "\n\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void problem3(){
    //Declaration of Variables
    int mnth, yr;

    //Input values
    do {
        cout << "Enter a month (1-12): ";
        cin >> mnth; cin.ignore();
    } while(mnth < 0 || mnth > 12);

    do {
        cout << "Enter a year: ";
        cin >> mnth; cin.ignore();
    } while(yr < 0);

    //Process values -> Map inputs to Outputs
    if (mnth==1 || mnth==3 || mnth==5 || mnth==7 || mnth==8 || mnth==10 || mnth==12){
        cout << "There are 31 days in the month.\n";
    }
    else if (mnth==4 || mnth==6 || mnth==9 || mnth==11){
        cout << "There are 30 days in the month.\n";
    }
    else {
        if (yr % 100 == 0){
            if ((yr % 400) == 0) cout << "There are 29 days in the month.\n";
            else cout << "There are 28 days in the month.\n";
        }
        else cout << ((yr % 4 == 0) ? "There are 29 days in the month.\n" : "There are 28 days in the month.\n");
    }

    cout << "\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void problem4(){
    //Declaration of Variables
    signed short choice;
    char ch;

    //Input values
    do {
        system("clear");

        cout << "1. Calculate the Area of a Circle\n"
                "2. Calculate the Area of a Rectangle\n"
                "3. Calculate the Area of a Triangle\n"
                "4. Quit\n";
        do {
            cin >> choice; cin.ignore();
        } while(choice < 0 || choice > 5);

        system("clear");

        //Process values -> Map inputs to Outputs
        switch (choice){
            case 1: areaCir(); break;
            case 2: areaRec(); break;
            case 3: areaTri(); break;
            case 4: exit(0);
        }

        do {
            cout << "Would you like to do another calculation? (y/n)\n";
            cin >> ch; cin.ignore();
            ch = static_cast<char>(tolower(ch));
        } while(ch != 'y' && ch != 'n');
    } while(ch == 'y');

    cout << "\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void areaCir(){
    float r,
          area;

    do {
        cout << "Enter the radius of a circle (inch.)\n"
                "and I will display its area (inch.).\n";
        cin >> r; cin.ignore();
    } while(r < 0);

    area = PI * r * r;

    cout << "The area of the circle is " << area << ".\n";
}

void areaRec(){
    float length,
          width,
          area;

    cout << "Enter the length and width of a rectangle (inch.)\n"
            "and I will display its area.\n";
    cout << "Length: ";
    cin >> length; cin.ignore();
    cout << "Width: ";
    cin >> width; cin.ignore();

    area = length * width;

    cout << "The area of the rectangle is " << area << ".\n";
}

void areaTri(){
    float base,
          height,
          area;

    cout << "Enter the length of the triangle's base and its height (inch.),\n"
            "and I will display its area.\n";
    cout << "Length of base: ";
    cin >> base; cin.ignore();
    cout << "Height: ";
    cout << height; cin.ignore();

    area = base * height * 0.5;

    cout << "The area of the triangle is " << area << ".\n";
}

void problem5(){
    //Declaration of Variables
    srand(static_cast<unsigned int>(time(0)));
    unsigned short op1,
                   op2,
                   answer,
                   sum;
    char choice;

    //Input values
    do {
        system("clear");

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

    cout << "\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void problem6(){
    //Declaration of Variables
    int days;
    float perc, pop;

    //Input values
    cout << "Enter a starting population: ";
    cin >> pop; cin.ignore();

    cout << "Enter the average daily increase as a percentage: ";
    cin >> perc; cin.ignore();

    perc /= 100;

    cout << "How many days would you like the population to multiply? ";
    cin >> days; cin.ignore();

    //Process values -> Map inputs to Outputs
    for (int i = 0; i < days; i++){
        pop += pop * perc;
        cout << "Day " << i + 1 << " population: " << pop << endl;
    }

    cout << "\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void problem7(){
    //Declaration of Variables
    float fahrenheit, c;

    //Display Output
    for (int i = 0; i < 20; i++){
        fahrenheit = i + 1;

        cout << fixed << setprecision(2);
        cout << fahrenheit << "F = " << celsius(fahrenheit) << "C\n";
    }

    cout << "\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

float celsius(const float f){
    return 5/9.0 * (f - 32);
}

void problem8(){
    //Declaration of Variables
    ifstream weather("RainOrShine.txt");
    char data[MNTH][DAYS];
    unsigned short count[MNTH][COND] = {};
    unsigned short tot[COND] = {};

    //Input values
    if (weather){
        for (int i = 0; i < MNTH; i++) weather >> data[i];
    } else cout << "File opened unsuccessfully.\n";

    //Process values -> Map inputs to Outputs
    for (int i = 0; i < MNTH; i++){
        for (int j = 0; j < DAYS; j++){
            if (data[i][j] == 'C'){
                count[i][0]++;
                tot[0]++;
            }

            if (data[i][j] == 'R'){
                count[i][1]++;
                tot[1]++;
            }

            if (data[i][j] == 'S'){
                count[i][2]++;
                tot[2]++;
            }
        }
    }

    //Display Output
    for (int i = 0; i < MNTH; i++){
        cout << i << ": ";

        for (int j = 0; j < DAYS; j++) cout << data[i][j];
        cout << endl;
    }

    //Display weather table
    cout << "\n         C  R  S" << endl;
    for (int i = 0; i < 3; i++){
        switch(i){
            case 0: cout << "June:   "; break;
            case 1: cout << "July:   "; break;
            case 2: cout << "August: "; break;
        }

        for (int j = 0; j < 3; j++) cout << fixed << setw(2) << count[i][j] << " ";

        cout << endl;
    }

    cout << "T:      ";
    for (int i = 0; i < COND; i++) cout << fixed << setw(2) << tot[i] << " ";
    cout << "\n\n";

    if (count[0][1] > count[1][1] && count[0][1] > count[2][1]) cout << "June had most rain.\n";
    if (count[1][1] > count[0][1] && count[1][1] > count[2][1]) cout << "July had most rain.\n";
    if (count[2][1] > count[0][1] && count[2][1] > count[1][1]) cout << "August had most rain.\n";

    cout << "\nPress Enter to continue...";
    cin.get(); cin.ignore();
}

void problem9(){
    //Declaration of Variables
    const int size = 20;
    ifstream inFile("words.txt");
    string words[size];
    string find;
    int pos;

    //Input values
    if (inFile){
        string read;

        for (int i = 0; i < size; i++){
            inFile >> words[i];
            cout << words[i] << endl;
        }

        cout << "\nWhich word would you like to find? ";
        cin >> find; cin.ignore();

        for (int i = 0; i < size; i++) find[i] = tolower(find[i]);
        cout << endl;

        selSort(words, size);
        pos = binSrch(words, size, find);
        pos++;
        if (pos != -1) cout << "The word you're looking for was found in position\n"
                << pos << " of the sorted word list.\n";
        else cout << "The word wasn't found.\n";
    } else cout << "File couldn't open.\n";

    //Process values -> Map inputs to Outputs
    for (int i = 0; i < size; i++) cout << i + 1 << ") " << words[i] << endl;
    cout << endl;

    //Display Output
    inFile.close(); inFile.clear();

    cout << "Press Enter to continue...";
    cin.get(); cin.ignore();
}

void selSort(string arr[], const int SIZE){
    int minInd;
    string minVal;

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

int binSrch(string arr[], const int SIZE, string str){
    int first = 0,
        last = SIZE - 1,
        mid,
        pos = -1;
    bool found = false;

    do {
        mid = (first + last) / 2;

        if(arr[mid] == str){
            found = true;
            pos = mid;
        }

        else if (arr[mid] > str) last = mid - 1;
        else first = mid + 1;
    } while(!found && first <= last);

    return pos;
}

void problem10(){
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

    cout << "\n\nPress Enter to continue...";
    cin.get(); cin.ignore();
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
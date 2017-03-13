/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Geometry Calculator
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 11:42 AM
 * Purpose: Create a menu driven program that calculates the areas of a circle,
 *          rectangle and triangle.
 */

#include <iostream>   //Input/Output objects
#include <cctype>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants
const float PI = 3.14159;

//Function prototypes
void areaCir();
void areaRec();
void areaTri(); 

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    signed short choice;
    char ch;
    
    //Input values
    do {
        cout << "1. Calculate the Area of a Circle\n"
                "2. Calculate the Area of a Rectangle\n"
                "3. Calculate the Area of a Triangle\n"
                "4. Quit\n";
        do {
            cin >> choice; cin.ignore();
        } while(choice < 0 || choice > 5);

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
    
    //Display Output

    //Exit Program
    return 0;
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
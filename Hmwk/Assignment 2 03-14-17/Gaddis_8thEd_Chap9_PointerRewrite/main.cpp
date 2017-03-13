/*
 * File:   Pointer Rewrite
 * Author: Kenzie Vasquez
 * Created on March 8, 2017, 11:58 AM
 * Purpose:

 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int doSomething(int *, int *);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    int var1 = 5, var2 = 20;

    //Input values

    //Process values -> Map inputs to Outputs
    cout << "doSomething returned: " << doSomething(&var1, &var2) << endl;

    //Display Output

    //Exit Program
    return 0;
}

int doSomething(int *x, int *y){
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}
/*
 * File:   Review
 * Author: YOUR NAME
 * Created on DATE
 * Purpose: Review 03/06/17 (Menu of all programming problems/challenges)
 */

#include <iostream>  //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    int menuItm;    //Choice from menu

    //Loop until users exits
    do{
        system("clear");

        do {
            //Prompt for problem for user input
            cout<<"1.  Type 1  for Prob1"<<endl;
            cout<<"2.  Type 2  for Prob2"<<endl;
            cout<<"3.  Type 3  for Prob3"<<endl;
            cout<<"4.  Type 4  for Prob4"<<endl;
            cout<<"5.  Type 5  for Prob5"<<endl;
            cout<<"6.  Type 6  for Prob6"<<endl;
            cout<<"7.  Type 7  for Prob7"<<endl;
            cout<<"8.  Type 8  for Prob8"<<endl;
            cout<<"9.  Type 9  for Prob9"<<endl;
            cout<<"10. Type 10 for Prob10"<<endl;
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

}

void problem2(){

}

void problem3(){

}

void problem4(){

}

void problem5(){

}

void problem6(){

}

void problem7(){

}

void problem8(){

}

void problem9(){

}

void problem10(){

}


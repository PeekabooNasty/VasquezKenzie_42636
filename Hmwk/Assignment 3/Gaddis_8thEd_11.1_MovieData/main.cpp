/* 
 * File:   Movie Data
 * Author: Kenzie Vasquez
 * Created on March 18, 2017, 8:39 PM
 * Purpose: Write a program that uses a structure named MovieData to store the 
   following information about a movie:
        Title
        Director
        Year Released
        Running Time (in minutes)
    
    The program should create two MovieData variables, store values in their 
    members, and pass each one, in turn, to a function that displays the 
    information about the movie in a clearly formatted manner.
 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries
#include "MovieData1.h"

//Global Constants

//Function prototypes
void showDat1(MovieData1 &);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    MovieData1 movie1, movie2;
    
    //Input values
    movie1.title = "Top 10 Worst Movies Ever";
    movie1.direct = "WatchMojo";
    movie1.yr = 1996;
    movie1.runTime = 90;
    
    movie2.title = "Top 10 Best Movies Ever";
    movie2.direct = "WatchMojo";
    movie2.yr = 1997;
    movie2.runTime = 120;

    //Process values -> Map inputs to Outputs
    showDat1(movie1);
    cout << endl;
    showDat1(movie2);
    
    //Display Output
    
    //Exit Program
    return 0;
}

void showDat1(MovieData1 &movie){
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.direct << endl;
    cout << "Year: " << movie.yr << endl;
    cout << "Runtime (in min.): " << movie.runTime << endl;
}
/* 
 * File:   Movie Profit
 * Author: Kenzie Vasquez
 * Created on March 18, 2017, 9:31 PM
 * Purpose: Modify the Movie Data program written for Programming Challenge 1 to 
 * include two additional members that hold the movie’s production costs and 
 * first-year revenues. Modify the function that displays the movie data to 
 * display the title, director, release year, running time, and first year’s 
 * profit or loss.
 */

#include <iostream>   //Input/Output objects
using namespace std; //Name-space used in the System Library

//User Libraries
#include "MovieData2.h"

//Global Constants

//Function prototypes
void showDat2(MovieData2 &);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration
    MovieData2 movie1, movie2;
    
    //Input values
    movie1.title = "Top 10 Worst Movies Ever";
    movie1.direct = "WatchMojo";
    movie1.yr = 1996;
    movie1.runTime = 90;
    movie1.cost = 5;
    movie1.rev = 2;
    
    movie2.title = "Top 10 Best Movies Ever";
    movie2.direct = "WatchMojo";
    movie2.yr = 1997;
    movie2.runTime = 120;
    movie2.cost = 2;
    movie2.rev = 4;

    //Process values -> Map inputs to Outputs
    showDat2(movie1);
    cout << endl;
    showDat2(movie2);
    
    //Display Output
    
    //Exit Program
    return 0;
}

void showDat2(MovieData2 &movie){
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.direct << endl;
    cout << "Year: " << movie.yr << endl;
    cout << "Runtime (in min.): " << movie.runTime << endl;
    
    if (movie.cost < movie.rev){
        cout << movie.title << " made a profit of $" << movie.rev - movie.cost << endl;
    } else cout << movie.title << " had a loss of $" << movie.cost - movie.rev << endl;
}
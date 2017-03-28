/* 
 * File:   Corporate Sales Data
 * Author: Kenzie Vasquez
 * Created on March 20, 2017, 1:07 PM
 * Purpose: Write a program that uses a structure to store data on a company 
   division. The program should use four variables of this structure. Each 
   variable should represent one of the following corporate divisions: 
   East, West, North, and South. The user should be asked for the four quarters’ 
   sales figures for each division. Each division’s total and average sales 
   should be calculated and stored in the appropriate member of each structure 
   variable. These figures should then be displayed on the screen.

   Input Validation: Do not accept negative numbers for any sales figures.
 */

#include <iostream> //Input/Output objects
using namespace std; //Name-space used in the System Library

#include "Div.h"

void qSales(Div ); //Enter quarter sales for each division

int main(int argc, char** argv){
    Div north, west, east, south;
    
    north.name = "North";
    west.name  = "West";
    east.name  = "East";
    south.name = "South";
    
    qSales(north);
    qSales(west);
    qSales(east);
    qSales(south);
    
    return 0;
}

void qSales(Div div){
    cout << "Enter the quarterly sales for " << div.name << "ern division.\n";
    
    do {
        cout << "Enter First-Quarter sales figure: $";
        cin >> div.frstQ; cin.ignore();
    } while(div.frstQ < 0);
    
    do {
        cout << "Enter Second-Quarter sales figure: $";
        cin >> div.scndQ; cin.ignore();
    } while(div.scndQ < 0);
    
    do {
        cout << "Enter Third-Quarter sales figure: $";
        cin >> div.thrdQ; cin.ignore();
    } while(div.thrdQ < 0);
    
    do {
        cout << "Enter Fourth-Quarter sales figure: $";
        cin >> div.frthQ; cin.ignore();
    } while(div.frthQ < 0);
    
    div.tot = 0;
    div.avg = 0;
    div.tot += div.frstQ + div.scndQ + div.thrdQ + div.frthQ;
    div.avg = div.tot / 4;
    
    cout << endl << div.name << "'s annual total: $" << div.tot << "\n"
         << div.name << "average quarterly sales: $" << div.avg << "\n\n";
}
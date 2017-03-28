/* 
 * File:   Drink Machine Simulator
 * Author: Kenzie Vasquez
 * Created on March 25, 2017, 1:09 PM
 * Purpose: Write a program that simulates a soft drink machine.
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Machine.h"

Machine *init(const int); //Initializes structure data

int main(int argc, char** argv) {
    const int SIZE = 5;
    Machine *drinks = init(SIZE);
    unsigned short ch;
    float profit = 0;
    
    do { //Display drinks and input choice
        system("clear");
        cout << "Choose an option.\n";
        cout << "  Drink         Price    Quantity\n";
        for (int i = 0; i < SIZE; i++){
            cout << i + 1 << ". " << drinks[i].name << "   "
                 << fixed << setprecision(2) << drinks[i].cost << "¢       "
                 << drinks[i].quant << endl;
        }
        cout << "6. Quit\n";
        
        do {
            cout << "> ";
            cin >> ch; cin.ignore();
            ch--;
        } while(ch < 0 || ch > 5);
        
        //If user chooses drink, calculate any change, profit, and loop back
        if (ch != 5){
            float money;
            
            do {
                cout << "\nEnter amount of money: ";
                cin >> money; cin.ignore();
            } while(money < 0 || money > 1);

            if (drinks[ch].quant != 0){
                if (money > drinks[ch].cost) cout << "Your change is $" << money - drinks[ch].cost << endl;
                profit += drinks[ch].cost;
                drinks[ch].quant--;
                cout << "\n[Press Enter to Continue...]\n";
                cin.get();
            } else cout << drinks[ch].quant << " is sold out! Choose another drink.\n";
        }
    } while(ch != 5);
    
    cout << "\nProfit: $" << profit << endl;

    delete [] drinks;
    
    return 0;
}

Machine *init(const int SIZE) {
    Machine *arr = new Machine[SIZE];

    //Cola
    arr[0].name = "Cola      ";
    arr[0].cost = .75;
    arr[0].quant = 20;

    //Root Beer
    arr[1].name = "Root Beer ";
    arr[1].cost = .75;
    arr[1].quant = 20;

    //Lemon-Lime
    arr[2].name = "Lemon-Lime";
    arr[2].cost = .75;
    arr[2].quant = 20;

    //Grape Soda
    arr[3].name = "Grape Soda";
    arr[3].cost = .80;
    arr[3].quant = 20;

    //Cream Soda
    arr[4].name = "Cream Soda";
    arr[4].cost = .80;
    arr[4].quant = 20;

    return arr;
}
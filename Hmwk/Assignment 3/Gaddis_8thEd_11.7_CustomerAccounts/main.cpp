/* 
 * File:   Customer Accounts
 * Author: Kenzie Vasquez
 * Created on March 23, 2017, 1:16 PM
 * Purpose: 
    Write a program that uses a struct to store data about a customer account.

    The program should use an array of at least 10 structures. It should let the 
    user enter data into the array, change the contents of any element, and 
    display all the data stored in the array. The program should have a 
    menu-driven user interface.

    Input Validation: When the data for a new account is entered, be sure the 
    user enters data for all the fields. No negative account balances should be 
    entered.
 */

#include <iostream>
#include <string>
using namespace std;

#include "Accounts.h"

Accounts *data(const int); //Enter account details for each customer
void edit(Accounts *, const int);
void display(Accounts *, const int);

int main(int argc, char** argv){
    const int SIZE = 1;
    Accounts *cstmrs = nullptr;
    unsigned short ch;
    
    do {
        system("clear");
        
        cout << "Customer Accounts\n";
        cout << "1. Create Accounts\n";
        cout << "2. Edit Accounts\n";
        cout << "3. Display Accounts\n";
        cout << "4. Quit\n";
        
        do {
            cin >> ch; cin.ignore();
        } while(ch < 1 || ch > 4);
        
        system("clear");
        
        switch(ch){
            case 1: cstmrs = data(SIZE); break;
            case 2: edit(cstmrs, SIZE); break;
            case 3: display(cstmrs, SIZE);
        }
    } while(ch != 4);
    
    delete [] cstmrs;
    
    return 0;
}

Accounts *data(const int SIZE){
    Accounts *acc = new Accounts[SIZE];
    
    for(int i = 0; i < SIZE; i++){
        string nth = "";
        
        switch(i){ //1st 2nd 3rd 4th 5th 6th 7th 8th 9th 10th
            case 1:  nth = "1st";  break; case 2:  nth = "2nd";  break;
            case 3:  nth = "3rd";  break; case 4:  nth = "4th";  break;
            case 5:  nth = "5th";  break; case 6:  nth = "6th";  break;
            case 7:  nth = "7th";  break; case 8:  nth = "8th";  break;
            case 9:  nth = "9th";  break; case 10: nth = "10th"; break;
        }
        
        do {
            cout << "Enter " << nth << " customer's name:\n";
            getline(cin, acc[i].name);
        } while(acc[i].name.empty());
        
        do {
            cout << endl << acc[i].name << "'s address:\n";
            getline(cin, acc[i].address);
        } while(acc[i].address.empty());
        
        do {
            cout << endl << acc[i].name << "'s City, State, and ZIP:\n";
            getline(cin, acc[i].resdnce);
        } while(acc[i].resdnce.empty());
        
        do {
            cout << endl << acc[i].name << "'s Telephone number:\n";
            getline(cin, acc[i].tele);
        } while(acc[i].tele.empty());
        
        do {
            cout << endl << acc[i].name << "'s Account Balance:\n$";
            cin >> acc[i].balance; cin.ignore();
        } while(acc[i].balance < 0);
        
        do {
            cout << endl << acc[i].name << "'s Date of Last Payment (MM/DD/YYYY):\n";
            getline(cin, acc[i].lastPay);
        } while(acc[i].lastPay.empty());
        
        cout << endl;
    }
    
    return acc;
}

void edit(Accounts *acc, const int SIZE){
    unsigned short ch, ch2;
    
    do {
        system("clear");
        
        cout << "Which account would you like to edit?\n";
        for(int i = 0; i < SIZE; i++) cout << i + 1 << ". " << acc[i].name << endl;
        
        do {
            cin >> ch; cin.ignore();
        } while(ch < 1 || ch > SIZE + 1);
        
        ch--;
        
        do {
            cout << "\nWhat would you like to edit?\n";
            cout << "1. Name\n"
                 << "2. Address\n"
                 << "3. City, State, and ZIP\n"
                 << "4. Telephone number\n"
                 << "5. Account Balance\n"
                 << "6. Date of Last Payment\n"
                 << "7. Edit Another Account\n"
                 << "8. Exit to Main Menu\n";
            
            do {
                cin >> ch2; cin.ignore();
            } while(ch2 < 1 || ch2 > 8);
            
            switch(ch2){
                case 1: 
                do {
                    cout << "Enter customer's name:\n";
                    getline(cin, acc[ch].name);
                } while(acc[ch].name.empty());
                break;
                
                case 2:
                do {
                    cout << endl << "Enter address:\n";
                    getline(cin, acc[ch].address);
                } while(acc[ch].address.empty());
                break;
    
                case 3:
                do {
                    cout << endl << "Enter City, State, and ZIP:\n";
                    getline(cin, acc[ch].resdnce);
                } while(acc[ch].resdnce.empty());
                break;
    
                case 4:
                do {
                    cout << endl << "Enter Telephone number:\n";
                    getline(cin, acc[ch].tele);
                } while(acc[ch].tele.empty());
                break;
    
                case 5:
                do {
                    cout << endl << "Enter Account Balance:\n$";
                    cin >> acc[ch].balance; cin.ignore();
                } while(acc[ch].balance < 0);
                break;
    
                case 6:
                do {
                    cout << endl << "Enter Date of Last Payment (MM/DD/YYYY):\n";
                    getline(cin, acc[ch].lastPay);
                } while(acc[ch].lastPay.empty());
            }
        } while(ch2 != 7 && ch2 != 8);
    } while(ch2 != 8);
}

void display(Accounts *acc, const int SIZE){
    for(int i = 0; i < SIZE; i++){
        cout << i + 1 << "." << acc[i].name << "\n  " << acc[i].address
             << "\n  " << acc[i].resdnce << "\n  " << acc[i].tele
             << acc[i].balance << "\n  " << acc[i].lastPay << "\n\n";
    }
    
    cin.get(); cin.ignore();
}
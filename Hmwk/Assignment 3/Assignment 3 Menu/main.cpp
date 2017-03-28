/* 
 * File:   Assignment 3 - Chapter 11 Menu
 * Author: Kenzie Vasquez
 * Created on March 26, 2017, 2:49 PM
 */

#include <iostream>  //Input/Output objects
#include <string>
#include <iomanip>
using namespace std; //Name-space used in the System Library

//User Libraries
#include "MovieData1.h"
#include "MovieData2.h"
#include "Div.h"
#include "Weather.h"
#include "Player.h"
#include "Accounts.h"
#include "Machine.h"
#include "Grades.h"

//Global Constants

//Function prototypes
void problem1();
void showDat1(MovieData1 &);

void problem2();
void showDat2(MovieData2 &);

void problem3();
void qSales(Div );

void problem4();
Weather *data1(const int);

void problem5();
Player *data2(const int);

void problem6();
Accounts *data3(const int); //Enter account details for each customer
void edit(Accounts *, const int);
void display(Accounts *, const int);

void problem7();
Machine *init(const int);

void problem8();
Grades *data4(const int, const int);
void destroy(Grades *, const int);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    int menuItm;    //Choice from menu

    //Loop until users exits
    do{
        system("clear");

        do {
            //Prompt for problem for user input
            cout<<"1.  Type 1  for Movie Data"<<endl;
            cout<<"2.  Type 2  for Movie Profit"<<endl;
            cout<<"3.  Type 3  for Corporate Sales Data"<<endl;
            cout<<"4.  Type 4  for Weather Statistics"<<endl;
            cout<<"5.  Type 5  for Soccer Scores"<<endl;
            cout<<"6.  Type 6  for Customer Accounts"<<endl;
            cout<<"7.  Type 7  for Drink Machine Simulator"<<endl;
            cout<<"8.  Type 8  for Course Grade"<<endl;
            cin>>menuItm;
            
            system("clear");
        } while(menuItm < 1 || menuItm > 8);

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
            case 8:  problem8();
        }//End the Switch/Case
    } while(menuItm > 0 && menuItm <= 10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}

void problem1(){
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

    cout << "\n[Press Enter to Continue]";
    cin.get(); cin.get(); cin.ignore();
}

void showDat1(MovieData1 &movie){
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.direct << endl;
    cout << "Year: " << movie.yr << endl;
    cout << "Runtime (in min.): " << movie.runTime << endl;
}

void problem2(){
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
    
    cout << "\n[Press Enter to Continue]";
    cin.get(); cin.get(); cin.ignore();
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

void problem3(){
    Div north, west, east, south;
    
    north.name = "North";
    west.name  = "West";
    east.name  = "East";
    south.name = "South";
    
    qSales(north);
    qSales(west);
    qSales(east);
    qSales(south);
    
    cout << "[Press Enter to Continue]";
    cin.get(); cin.ignore();
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

void problem4(){
    const int MNTHS = 12;
    Weather *months = data1(MNTHS);
    
    delete [] months;
    
    cout << "\n[Press Enter to Continue]";
    cin.get(); cin.ignore();
}

Weather *data1(const int M){
    Weather *ptr = new Weather[M];
    short low = 0, 
          high;
    ptr->SIZE = M;
    
    //Enter Total Rainfall, High Temp, Low Temp and Avg Temp for each month
    for(int i = 0; i < ptr->SIZE; i++){
        do {
            cout << "Enter the highest temp for Month #" << i + 1 << ": ";
            cin >> ptr[i].hiTemp; cin.ignore();
        } while(ptr[i].hiTemp < -100 || ptr[i].hiTemp > 140);
        
        do {
            cout << "Enter the lowest temp for Month #" << i + 1 << ": ";
            cin >> ptr[i].lowTemp; cin.ignore();
            
            if (ptr[i].lowTemp > ptr[i].hiTemp){
                cout << "The lowest temp needs to be lower than the highest!\n";
            }
        } while(ptr[i].lowTemp < -100 || ptr[i].lowTemp > 140 && ptr[i].lowTemp > ptr[i].hiTemp);
        
        //Calculate total and average temperature
        ptr[i].avgTemp = (ptr[i].hiTemp + ptr[i].lowTemp) / 2;
        ptr->totRain += (ptr[i].hiTemp + ptr[i].lowTemp);
    }
    
    cout << endl;
    for(int i = 0; i < ptr->SIZE; i++){
        cout << "Avg temp for Month #" << i + 1 << ": " << ptr[i].avgTemp << endl;
    }
    
    return ptr;
}

void problem5(){
    Player *plyr = data2(12);
    
    delete [] plyr;
    
    cout << "\n[Press Enter to Continue]";
    cin.get(); cin.get(); cin.ignore();
}

Player *data2(const int SIZE){
    Player *ptr = new Player[SIZE];
    int sum = 0,
        high = 0,
        index = 0;
    
    cin.ignore();
    
    for(int i = 0; i < SIZE; i++){
        cout << "PLAYER " << i + 1 << endl;
        cout << "Name: ";
        getline(cin, ptr[i].name);
        
        do {
           cout << "Number: ";
           cin >> ptr[i].num; cin.ignore();
        } while(ptr[i].num < 0 || ptr[i].num > 4294967295);
        
        do {
            cout << "Score: ";
            cin >> ptr[i].score; cin.ignore();
        } while(ptr[i].score < 0 || ptr[i].num > 4294967295);
        
        sum += ptr[i].score;
        
        if(ptr[i].score > high){ //If a new higher score is found
            high = ptr[i].score;
            index = i;
        }
        
        cout << endl;
    }
    
    cout << "Total team score: " << sum << endl << endl;
    cout << "HI-SCORE\n" << "#" << ptr[index].num << " " << ptr[index].name << endl;
    
    return ptr;
}

void problem6(){
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
            case 1: cstmrs = data3(SIZE); break;
            case 2: edit(cstmrs, SIZE); break;
            case 3: display(cstmrs, SIZE);
        }
    } while(ch != 4);
    
    delete [] cstmrs;
    
    cout << "[Press Enter to Continue]";
    cin.ignore();
}

Accounts *data3(const int SIZE){
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

void problem7(){
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
                cin.ignore();
            } else{
                cout << drinks[ch].quant << " is sold out! Choose another drink.\n";
                cin.ignore();
            }
        }
    } while(ch != 5);
    
    cout << "\nProfit: $" << profit << endl;

    delete [] drinks;
    
    cout << "\n[Press Enter to Continue]";
    cin.ignore();
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

void problem8(){
    int stdnts, tests;
    
    cout << "How many tests and students will there be?\n";
    do {
        cout << "Tests: ";
        cin >> tests; cin.ignore();
    } while(tests < 0);
    
    do {
        cout << "Students: ";
        cin >> stdnts; cin.ignore();
    } while(stdnts < 1);
    
    Grades *student = data4(stdnts, tests);
    destroy(student, stdnts);
}

Grades *data4(const int STDNTS, const int TESTS){
    Grades *arr = new Grades[STDNTS];
    for(int i = 0; i < STDNTS; i++){
        arr[i].tests = new unsigned short[TESTS];
        arr[i].avg = new float[STDNTS];
    }
    
    for(int i = 0; i < STDNTS; i++){
        arr[i].avg[i] = 0;
        
        cout << "\nEnter the name, ID and " << TESTS << " test scores for student #" 
             << i + 1 << ":\n";
        
        //Name
        do {
            cout << "Name of student #" << i + 1 << ": ";
            getline(cin, arr[i].name);
        } while(arr[i].name.empty());
        
        //Student ID #
        do {
            cout << "ID for " << arr[i].name << " (12345): ";
            getline(cin, arr[i].idNum);
        } while(arr[i].idNum.empty() && arr[i].idNum.length() != 5);
        
        //Test scores
        for(int j = 0; j < TESTS; j++){
            do {
                cout << "Test #" << j + 1 << ": ";
                cin >> arr[i].tests[j]; cin.ignore();
            } while(arr[i].tests[j] < 0 || arr[i].tests[j] > 100);
            
            //Total test scores
            arr[i].avg[i] += arr[i].tests[j];
        }
        
        //Calculate avg scores per student
        arr[i].avg[i] = arr[i].avg[i] / TESTS;
    }
    
    //Display average test scores
    cout << "\nAverage scores and letter grade\n";
    for(int i = 0; i < STDNTS; i++){
        cout << "ID#" << arr[i].idNum << "   " << arr[i].name << ": " 
             << fixed << setprecision(2) << arr[i].avg[i] << "%   ";
        
       (arr[i].avg[i] >= 90 ? arr[i].grade = 'A' :
        arr[i].avg[i] >= 80 ? arr[i].grade = 'B' :
        arr[i].avg[i] >= 70 ? arr[i].grade = 'C' :
        arr[i].avg[i] >= 60 ? arr[i].grade = 'D' : arr[i].grade = 'F');

        cout << arr[i].grade << endl;
    }
    
    cout << "\n[Press Enter to Continue]";
    cin.ignore();
    
    return arr;
}

void destroy(Grades *arr, const int STDNTS){
    for(int i = 0; i < STDNTS; i++){
        delete [] arr[i].tests;
        delete [] arr[i].avg;
    }
    
    delete [] arr;
}
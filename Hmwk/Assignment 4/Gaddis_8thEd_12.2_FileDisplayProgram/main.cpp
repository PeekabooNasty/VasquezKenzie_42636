/* 
 * File:   File Display Program
 * Author: Kenzie Vasquez
 * Created on April 3, 2017, 6:30 PM
 * Purpose: Write a program that asks the user for the name of a file. The 
   program should display the contents of the file on the screen. If the file’s 
   contents won’t fit on a single screen, the program should display 24 lines of 
   output at a time, and then pause. Each time the program pauses, it should 
   wait for the user to strike a key before the next 24 lines are displayed.
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    string fileNm = "",
           data = "";
    
    do {
        cout << "Enter the name of the file (\"text.txt\"): ";
        cin >> fileNm; cin.ignore();
    } while(fileNm.empty());
    
    cout << endl;
    
    fstream inFile(fileNm, ios::in);
    
    if(inFile){ //if file is found
        do {
            for(int i = 0; i < 24; i++) {
                if(getline(inFile, data)) cout << data << endl;
            }
            cout << "\n[Press Enter to Continue...]\n"; cin.get();
        } while(inFile >> data);
        cout << "All of the file has been read.";
    } else cout << "File couldn't be found.";
    
    inFile.close(); inFile.clear();
    
    return 0;
}
/* 
 * File:   Tail Program
 * Author: Kenzie Vasquez
 * Created on April 4, 2017, 7:34 PM
 * Purpose: Write a program that asks the user for the name of a file. The 
   program should display the last 10 lines of the file on the screen 
   (the "tail" of the file). If the file has fewer than 10 lines, the entire 
   file should be displayed, with a message indicating the entire file has been 
   displayed.
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    string fileNm = "";
    fstream inFile;
    
    do {
        cout << "Enter the name of the text file you want to open (\"tail.txt\"): ";
        cin >> fileNm; cin.ignore();
    } while(fileNm.empty());
    
    inFile.open(fileNm, ios::in);
    
    if(!inFile.fail()) {
        cout << fileNm << " was opened.\n\n";
        int newLines = 0;
        string data = "";
        char ch;
        bool ten = true;
        
        inFile.seekg(0L, ios::end); //Set cursor at end of file
        do {
            inFile.seekg(-2L, ios::cur);
            if(inFile.tellg() == 0){
                cout << "File has fewer than 10 lines.\n";
                ten = false;
                inFile.seekg(0L, ios::cur); //Set cursor at end of file
            }
            inFile.get(ch);
            if (ch == '\n') newLines++;
        } while(newLines != 10 && ten);
        inFile.seekg(-1L, ios::cur);
        while(getline(inFile, data)) cout << data << endl;
        
    } else cout << "No file was found and opened.";
    
    inFile.close(); inFile.clear();
    
    return 0;
}


/* 
 * File:   File Head Program
 * Author: Kenzie Vasquez
 * Created on April 3, 2017, 6:37 PM
 * Purpose: Write a program that asks the user for the name of a file. The 
   program should display the first 10 lines of the file on the screen 
   (the "head" of the file). If the file has fewer than 10 lines, the entire 
   file should be displayed, with a message indicating the entire file has been 
   displayed.
 */

#include <iostream> //I/O stream
#include <string>   //String objects
#include <fstream>  //File stream objects
using namespace std;

int main(int argc, char** argv) {
    string fileNm = "", data = "";

    do {
        cout << "Enter the filename to open (\"fileDisplay.txt\"): ";
        cin >> fileNm; cin.ignore();
    } while (fileNm.empty());

    fstream inFile(fileNm, ios::in);

    if (inFile) {
        for (int i = 0; i < 10; i++) {
            if (getline(inFile, data)) cout << data << endl;
            else {
                cout << "The entire file has been displayed.\n";
                break;
            }
        }
    } else cout << "Error opening file.\n";

    inFile.close(); inFile.clear();

    return 0;
}
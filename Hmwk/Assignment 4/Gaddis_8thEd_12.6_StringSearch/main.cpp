/* 
 * File:   String Search
 * Author: Kenzie Vasquez
 * Created on April 4, 2017, 9:45 PM
 * Purpose: Write a program that asks the user for a file name and a string to 
   search for. The program should search the file for every occurrence of a 
   specified string. When the string is found, the line that contains it should 
   be displayed. After all the occurrences have been located, the program should 
   report the number of times the string appeared in the file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

void strSrch(fstream &); //searches string in file

int main(int argc, char** argv) {
    fstream inFile;
    string fileNm = "";
    
    do { //Enter file name
        cout << "Enter the name of the file you want to search a string in\n"
                "(\"strSrch.txt\"):\n>";
        cin >> fileNm; cin.ignore();
    } while(fileNm.empty());
    
    inFile.open(fileNm, ios::in);
    if(!inFile.fail()){ //If file was opened
        strSrch(inFile);
        inFile.close(); inFile.clear();
    } else cout << "The file could not be found.\n";
    
    return 0;
}

void strSrch(fstream &file){
    string data = "", str = "";
    unsigned short line = 0, count = 0;;
    
    do { //enter substring
        cout << "Enter the string you would like to search for: ";
        getline(cin, str);
    } while(str.empty());

    while(getline(file, data)){ //if you can read more from the file
        line++;
        if(data.find(str) != string::npos){ //if string is found in line
            //scan line for more substr occurrences
            while(data.find(str) != string::npos){
                data.replace(data.find(str), str.length(), "x");
                count++;
            }
            cout << "\"" << str << "\"" << " was found in the file at line "
                 << line << endl;
        }
    }
    
    cout << "The string you entered was found " << count << " times in the file.\n";
}
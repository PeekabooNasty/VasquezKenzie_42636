/* 
 * File:   Punch Line
 * Author: Kenzie Vasquez
 * Created on April 3, 2017, 10:07 PM
 * Purpose:
Write a program that reads and prints a joke and its punch line from two different files.
The first file contains a joke, but not its punch line. The second file has the punch line as
its last line, preceded by “garbage.” The main function of your program should open the
two files and then call two functions, passing each one the file it needs. The first function
should read and display each line in the file it is passed (the joke file). The second function
should display only the last line of the file it is passed (the punch line file). It should find
this line by seeking to the end of the file and then backing up to the beginning of the last
line. Data to test your program can be found in the joke.txt and punchline.txt files.
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void prntJ(fstream &);
void prntPL(fstream &);

int main(int argc, char** argv) {
    fstream joke("joke.txt", ios::in), 
            punch("punchline.txt", ios::in);
    
    if(!joke.fail() && !punch.fail()){
        prntJ(joke);
        prntPL(punch);

        joke.close(); joke.clear();
        punch.close(); punch.clear();
    } else cout << "The files could not be found.";
    
    return 0;
}

void prntJ(fstream &inFile){
    string data = "";
    while(getline(inFile, data)) cout << data << endl;
}

void prntPL(fstream &inFile){
    string data = "";
    char ch;
    
    inFile.seekg(0L, ios::end);
    do {
        inFile.seekg(-2L, ios::cur);
        inFile.get(ch);
    } while(ch != '\n');
    
    getline(inFile, data);
    cout << data;
}
/* 
 * File:   Binary Search
 * Author: Kenzie Vasquez
 * Created on February 22, 2017, 7:55 PM
 * Purpose: Modify binary search so it searches through a string.
 */

#include <iostream>   //Input/Output objects
#include <string>
#include <fstream>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void selSort(string [], const int);
int binSrch(string [], const int, string);

//Execution Begins Here!
int main(int argc, char** argv){
    //Declaration of Variables
    const int size = 20;
    ifstream inFile("words.txt");
    string words[size];
    string find;
    int pos;
    
    //Input values
    if (inFile){
        string read;
        
        for (int i = 0; i < size; i++){
            inFile >> words[i];
            cout << words[i] << endl;
        }
        
        cout << "Which word would you like to find? ";
        cin >> find; cin.ignore();
        
        for (int i = 0; i < size; i++) find[i] = tolower(find[i]);
        cout << endl;
        
        selSort(words, size);
        pos = binSrch(words, size, find);
        pos++;
        if (pos != -1) cout << "The word you're looking for was found in position\n"
                << pos << " of the sorted word list.\n";
        else cout << "The word wasn't found.\n";
    } else cout << "File couldn't open.\n";

    //Process values -> Map inputs to Outputs
    for (int i = 0; i < size; i++) cout << i + 1 << ") " << words[i] << endl;
    cout << endl;
    
    //Display Output
    inFile.close(); inFile.clear();

    //Exit Program
    return 0;
}

void selSort(string arr[], const int SIZE){
    int minInd;
    string minVal;
    
    for (int i = 0; i < SIZE - 1; i++){
        minInd = i;
        minVal = arr[i];
        
        for (int j = i + 1; j < SIZE; j++){
            if (arr[j] < minVal){
                minVal = arr[j];
                minInd = j;
            }
        }
        
        arr[minInd] = arr[i];
        arr[i] = minVal;
    }
}

int binSrch(string arr[], const int SIZE, string str){
    int first = 0,
        last = SIZE - 1,
        mid,
        pos = -1;
    bool found = false;
    
    do {
        mid = (first + last) / 2;
        
        if(arr[mid] == str){
            found = true;
            pos = mid;
        }
        
        else if (arr[mid] > str) last = mid - 1;
        else first = mid + 1;
    } while(!found && first <= last);
    
    return pos;
}
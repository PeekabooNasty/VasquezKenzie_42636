/* File:   Morse Code Converter
 * Author: Kenzie Vasquez
 * Created on April 1, 2017, 1:59 PM
 * Purpose: Write a program that asks the user to enter a string, and then 
            converts that string to Morse code.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string morseCd(string);

int main(int argc, char** argv) {
    string str = "";
    bool invalid = false;
    
    do {
        cout << "Enter a valid string and I will convert it into morse code\n"
             << "(Can only enter letters, numbers, '.', ',', and '?'):\n";
        cin.ignore();
        getline(cin, str);
        for(int i = 0; i < str.length(); i++){
            if(!isalnum(str[i]) && !isspace(str[i]) && str[i] != ',' && str[i] != '.' && str[i] != '?') invalid = true;
        }
    } while(str.empty() || invalid);
    
    cout << morseCd(str);
    
    return 0;
}

string morseCd(string str){
    string morse = "";
    
    for(int i = 0; i < str.length(); i++){
        str[i] = toupper(str[i]);
        switch(str[i]){
            case ' ': morse.append("/ "); break;
            case ',': morse.append("--..-- "); break;
            case '.': morse.append(".-.-.- "); break;
            case '?': morse.append("..--.. "); break;
            case '0': morse.append("----- "); break;
            case '1': morse.append(".---- "); break;
            case '2': morse.append("..--- "); break;
            case '3': morse.append("...-- "); break;
            case '4': morse.append("....- "); break;
            case '5': morse.append("..... "); break;
            case '6': morse.append("-.... "); break;
            case '7': morse.append("--... "); break;
            case '8': morse.append("---.. "); break;
            case '9': morse.append("----. "); break;
            case 'A': morse.append(".- "); break;
            case 'B': morse.append("-... "); break;
            case 'C': morse.append("-.-. "); break;
            case 'D': morse.append("-.. "); break;
            case 'E': morse.append(". "); break;
            case 'F': morse.append("..-. "); break;
            case 'G': morse.append("--. "); break;
            case 'H': morse.append(".... "); break;
            case 'I': morse.append(".. "); break;
            case 'J': morse.append(".--- "); break;
            case 'K': morse.append("-.- "); break;
            case 'L': morse.append(".-.. "); break;
            case 'M': morse.append("-- "); break;
            case 'N': morse.append("-. "); break;
            case 'O': morse.append("--- "); break;
            case 'P': morse.append(".--. "); break;
            case 'Q': morse.append("--.- "); break;
            case 'R': morse.append(".-. "); break;
            case 'S': morse.append("... "); break;
            case 'T': morse.append("- "); break;
            case 'U': morse.append("..- "); break;
            case 'V': morse.append("...- "); break;
            case 'W': morse.append(".-- "); break;
            case 'X': morse.append("-..- "); break;
            case 'Y': morse.append("-.-- "); break;
            case 'Z': morse.append("--.. "); break;
        }
    }
    
    return morse;
}
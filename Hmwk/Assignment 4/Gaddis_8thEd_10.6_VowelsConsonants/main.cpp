/* 
 * File:   Vowels and Consonants
 * Author: Kenzie Vasquez
 * Created on March 31, 2017, 2:51 PM
 * Purpose: Counts # of vowels and consonants in a string.
 */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

short vowels(char *);
short consts(char *);

int main(int argc, char** argv) {
    char sntnce[50] = "",
         ch;
    
    do {
        cout << "Enter a string:\n> ";
        cin.getline(sntnce, 50);

        cout << "The c-string had " << vowels(sntnce) << " vowels and " 
             << consts(sntnce) << " consonants.\n\n";
        
        do {
            cout << "Would you like to input another word? ";
            cin >> ch; cin.ignore(); cin.clear();
            ch = tolower(ch);
        } while(ch != 'y' && ch != 'n');
    } while(ch == 'y');
    
    return 0;
}

short vowels(char *cstr){
    const char vow[] = "aeiou";
    short count = 0;

    for(int i = 0; i < strlen(cstr); i++){
        char ch[2] = { tolower(*(cstr + i)), '\0' };
        if (strstr(vow, ch)) count++;
    }
    return count;
}

short consts(char *cstr){
    const char con[] = "bcdfghjklmnpqrstvwxyz";
    short count = 0;

    for(int i = 0; i < strlen(cstr); i++){
        char ch[2] = { tolower(*(cstr + i)), '\0' };
        if (strstr(con, ch)) count++;
    }
    return count;
}
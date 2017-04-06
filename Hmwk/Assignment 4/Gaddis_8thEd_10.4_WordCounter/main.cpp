/* 
 * File:   Word Counter
 * Author: Kenzie Vasquez
 * Created on March 31, 2017, 9:21 AM
 * Purpose:
    Write a function that accepts a pointer to a C-string as an argument and 
    returns the number of words contained in the string. For instance, if the 
    string argument is "Four score and seven years ago" the function should 
    return the number 6. Demonstrate the function in a program that asks the 
    user to input a string and then passes it to the function. The number of 
    words in the string should be displayed on the screen. 
    Optional Exercise: Write an overloaded version of this function that accepts 
    a string class object as its argument.
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

short wrdCnt(char *); //counts # of words in c-string
short wrdCnt(string); //counts # of words in string

int main(int argc, char** argv) {
    char cstr[] = "Four score and seven years ago";
    string str = "Four score and seven years ago";
    
    //C-string
    cout << "\"" << cstr << "\"" << endl;
    cout << "Number of words in c-string: " << wrdCnt(cstr) << "\n\n";
    
    //String
    cout << "\"" << str << "\"" << endl;
    cout << "Number of words in string: " << wrdCnt(str);
    
    return 0;
}

short wrdCnt(char *arr){
    short count = 0;
    
    for(int i = 0; i < strlen(arr); i++){
        if(isalpha(*(arr + i)) && isspace(*(arr + i + 1))) count++;
    }
    
    return count + 1;
}

short wrdCnt(string str){
    short count = 0;
    
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i]) && isspace(str[i + 1])) count++;
    }
    
    return count + 1;
}
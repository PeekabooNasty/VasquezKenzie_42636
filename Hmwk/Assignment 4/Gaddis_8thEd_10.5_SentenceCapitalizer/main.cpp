/* 
 * File:   Sentence Capitalizer
 * Author: Kenzie Vasquez
 * Created on March 31, 2017, 2:23 PM
 * Purpose:
    Write a function that accepts a pointer to a C-string as an argument and capitalizes
    the first character of each sentence in the string. For instance, if the string argument
    is “ hello. my name is Joe. what is your name? ” the function should manipulate
    the string so it contains "Hello. My name is Joe. What is your name?"
    Demonstrate the function in a program that asks the user to input a string and then
    passes it to the function. The modified string should be displayed on the screen.
    Optional Exercise: Write an overloaded version of this function that accepts a string
    class object as its argument.
 */

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void capitalize(char *); //capitalize first letter of each sentence
void capitalize(string &); //capitalize first letter of each sentence

int main(int argc, char** argv) {
    //char str[] = "hello. my name is Joe. what is your name?";
    string str = "hello. my name is Joe. what is your name?";
    
    cout << "Before:\n" << str << "\n\n";
    capitalize(str);
    cout << "After:\n" << str << endl;
    
    return 0;
}

void capitalize(char *arr){
    bool frst = true;
    for(int i = 0; i < strlen(arr) - 2; i++){
        if(isalpha(*(arr + i + 1)) && frst){
            frst = false;
            *(arr + i) = toupper(*(arr + i));
        }
        if(*(arr + i) == '.' && *(arr + i + 1) == ' ' && isalpha(*(arr + i + 2))){
            *(arr + i + 2) = toupper(*(arr + i + 2));
        }
    }
}

void capitalize(string &str){
    bool frst = true;
    for(int i = 0; i < str.length() - 2; i++){
        if(isalpha(str[i + 1]) && frst){
            frst = false;
            str[i] = toupper(str[i]);
        }
        if(str[i] == '.' && str[i + 1] == ' ' && isalpha(str[i + 2])){
            str[i + 2] = toupper(str[i + 2]);
        }
    }
}
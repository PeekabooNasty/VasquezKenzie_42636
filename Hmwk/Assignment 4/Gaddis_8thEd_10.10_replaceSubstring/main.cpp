/* 
 * File:   replaceSubstring Function
 * Author: Kenzie Vasquez
 * Created on March 31, 2017, 5:10 PM
 * Purpose:
    Write a function named replaceSubstring that accept three C-string or string 
    object arguments. It should search string1 for all occurrences of string2. 
    When it finds an occurrence of string2, it should replace it with string3.
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string subStr(string, string, string);

int main(int argc, char** argv) {
    string str1 = "the dog jumped the over the fence",
           str2 = "the",
           str3 = "that";
    
    cout << subStr(str1, str2, str3);
    
    return 0;
}

string subStr(string str1, string str2, string str3){
    while(str1.find(str2) != string::npos){
        str1.replace(str1.find(str2), str2.length(), str3);
    } 
    
    return str1;
}
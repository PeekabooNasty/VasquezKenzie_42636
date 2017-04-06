/* 
 * File:   main.cpp
 * Author: Kenzie Vasquez
 * Created on April 4, 2017, 9:57 PM
 */

#include <iostream>  //Input/Output objects
#include <string>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std; //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void problem1();
short wrdCnt(char *); //counts # of words in c-string
short wrdCnt(string); //counts # of words in string

void problem2();
void capitalize(char *); //capitalize first letter of each sentence
void capitalize(string &); //capitalize first letter of each sentence

void problem3();
short vowels(char *);
short consts(char *);

void problem4();
string subStr(string, string, string);

void problem5();
string morseCd(string);

void problem6();

void problem7();

void problem8();
void prntJ(fstream &);
void prntPL(fstream &);

void problem9();

void problem10();
void strSrch(fstream &); //searches string in file

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm; //Choice from menu

    //Loop until users exits
    do {
        system("clear");

        do {
            //Prompt for problem for user input
            cout << "1.  Type 1  for Word Counter" << endl;
            cout << "2.  Type 2  for Sentence Capitalizer" << endl;
            cout << "3.  Type 3  for Vowels and Consonants" << endl;
            cout << "4.  Type 4  for replaceSubstring Function" << endl;
            cout << "5.  Type 5  for Morse Code Converter" << endl;
            cout << "6.  Type 6  for File Head Program" << endl;
            cout << "7.  Type 7  for File Display Program" << endl;
            cout << "8.  Type 8  for Punchline" << endl;
            cout << "9.  Type 9  for Tail Program" << endl;
            cout << "10. Type 10 for String Search" << endl;
            cin>>menuItm;
        } while (menuItm < 1 || menuItm > 10);

        system("clear");

        //Go to the Problem
        switch (menuItm) {
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 5: problem5(); break;
            case 6: problem6(); break;
            case 7: problem7(); break;
            case 8: problem8(); break;
            case 9: problem9(); break;
            case 10: problem10();
        }//End the Switch/Case
    } while (menuItm > 0 && menuItm <= 10); //Ends the Do-While Loop

    //Exit Program
    return 0;
}

void problem1() {
    char cstr[] = "Four score and seven years ago";
    string str = "Four score and seven years ago";
    
    //C-string
    cout << "\"" << cstr << "\"" << endl;
    cout << "Number of words in c-string: " << wrdCnt(cstr) << "\n\n";
    
    //String
    cout << "\"" << str << "\"" << endl;
    cout << "Number of words in string: " << wrdCnt(str) << endl;
    
    cout << "[Press Enter to Continue]";
    cin.get(); cin.get();
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

void problem2() {
    //char str[] = "hello. my name is Joe. what is your name?";
    string str = "hello. my name is Joe. what is your name?";
    
    cout << "Before:\n" << str << "\n\n";
    capitalize(str);
    cout << "After:\n" << str << endl;
    
    cout << "[Press Enter to Continue]";
    cin.get(); cin.get();
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

void problem3() {
    char sntnce[50] = "",
         ch;
    
    do {
        cout << "Enter a string:\n> ";
        cin.getline(sntnce, 50);

        cout << "The c-string had " << vowels(sntnce) << " vowels and " 
             << consts(sntnce) << " consonants.\n\n";
        
        do {
            cout << "Would you like to input another word? (y/n)";
            cin >> ch; cin.ignore(); cin.clear();
            ch = tolower(ch);
        } while(ch != 'y' && ch != 'n');
    } while(ch == 'y');
    
    cout << "[Press Enter to Continue]";
    cin.get();
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

void problem4() {
    string str1 = "the dog jumped the over the fence",
           str2 = "the",
           str3 = "that";
    
    cout << subStr(str1, str2, str3) << endl;
    
    cout << "[Press Enter to Continue]";
    cin.ignore(); cin.get();
}

string subStr(string str1, string str2, string str3){
    while(str1.find(str2) != string::npos){
        str1.replace(str1.find(str2), str2.length(), str3);
    }
    return str1;
}

void problem5() {
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
    
    cout << morseCd(str) << endl;
    
    cout << "[Press Enter to Continue]";
    cin.get();
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

void problem6() {
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
    
    cout << "[Press Enter to Continue]";
    cin.get();
}

void problem7() {
    string fileNm = "",
           data = "";
    
    do {
        cout << "Enter the name of the file (\"text.txt\"): ";
        cin >> fileNm; cin.ignore();
    } while(fileNm.empty());
    
    cout << endl;
    
    fstream inFile(fileNm, ios::in);
    
    if(inFile){ //if file is found
        do {
            for(int i = 0; i < 24; i++) {
                if(getline(inFile, data)) cout << data << endl;
            }
            cout << "\n[Press Enter to Continue...]\n"; cin.get();
        } while(inFile >> data);
        cout << "All of the file has been read.";
    } else cout << "File couldn't be found.";
    
    inFile.close(); inFile.clear();
    
    cout << "[Press Enter to Continue]";
    cin.get();
}

void problem8() {
    fstream joke("joke.txt", ios::in), 
            punch("punchline.txt", ios::in);
    
    if(!joke.fail() && !punch.fail()){
        prntJ(joke);
        prntPL(punch);

        joke.close(); joke.clear();
        punch.close(); punch.clear();
    } else cout << "The files could not be found.";
    
    cout << "[Press Enter to Continue]";
    cin.get(); cin.get();
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
    cout << data << endl;
}

void problem9() {
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
    
    cout << "[Press Enter to Continue]";
    cin.get(); cin.get();
}

void problem10() {
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
    
    cout << "[Press Enter to Continue]";
    cin.get();
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
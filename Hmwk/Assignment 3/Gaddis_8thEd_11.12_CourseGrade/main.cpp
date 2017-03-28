/* 
 * File:   Course Grade
 * Author: Kenzie Vasquez
 * Created on March 25, 2017, 11:22 AM
 * Purpose: The program should keep a list of test scores for a group of students. 
 * It should ask the user how many test scores there are to be and how many 
 * students there are. It should then dynamically allocate an array of structures. 
 * Each structure’s Tests member should point to a dynamically allocated array 
 * that will hold the test scores. After the arrays have been dynamically 
 * allocated, the program should ask for the ID number and all the test scores 
 * for each student. The average test score should be calculated and stored in 
 * the average member of each structure. The course grade should be computed.
 * The course grade should then be stored in the Grade member of each structure. 
 * Once all this data is calculated, a table should be displayed on the screen 
 * listing each student’s name, ID number, average test score, and course grade.+
 * Input Validation: Be sure all the data for each student is entered. Do not 
 * accept negative numbers for any test score.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Grades.h"

Grades *data(const int, const int);
void destroy(Grades *, const int);

int main(int argc, char** argv) {
    int stdnts, tests;
    
    cout << "How many tests and students will there be?\n";
    do {
        cout << "Tests: ";
        cin >> tests; cin.ignore();
    } while(tests < 0);
    
    do {
        cout << "Students: ";
        cin >> stdnts; cin.ignore();
    } while(stdnts < 1);
    
    Grades *student = data(stdnts, tests);
    destroy(student, stdnts);
    
    return 0;
}

Grades *data(const int STDNTS, const int TESTS){
    Grades *arr = new Grades[STDNTS];
    for(int i = 0; i < STDNTS; i++){
        arr[i].tests = new unsigned short[TESTS];
        arr[i].avg = new float[STDNTS];
    }
    
    for(int i = 0; i < STDNTS; i++){
        arr[i].avg[i] = 0;
        
        cout << "\nEnter the name, ID and " << TESTS << " test scores for student #" 
             << i + 1 << ":\n";
        
        //Name
        do {
            cout << "Name of student #" << i + 1 << ": ";
            getline(cin, arr[i].name);
        } while(arr[i].name.empty());
        
        //Student ID #
        do {
            cout << "ID for " << arr[i].name << " (12345): ";
            getline(cin, arr[i].idNum);
        } while(arr[i].idNum.empty() && arr[i].idNum.length() != 5);
        
        //Test scores
        for(int j = 0; j < TESTS; j++){
            do {
                cout << "Test #" << j + 1 << ": ";
                cin >> arr[i].tests[j]; cin.ignore();
            } while(arr[i].tests[j] < 0 || arr[i].tests[j] > 100);
            
            //Total test scores
            arr[i].avg[i] += arr[i].tests[j];
        }
        
        //Calculate avg scores per student
        arr[i].avg[i] = arr[i].avg[i] / TESTS;
    }
    
    //Display average test scores
    cout << "\nAverage scores and letter grade\n";
    for(int i = 0; i < STDNTS; i++){
        cout << "ID#" << arr[i].idNum << "   " << arr[i].name << ": " 
             << fixed << setprecision(2) << arr[i].avg[i] << "%   ";
        
       (arr[i].avg[i] >= 90 ? arr[i].grade = 'A' :
        arr[i].avg[i] >= 80 ? arr[i].grade = 'B' :
        arr[i].avg[i] >= 70 ? arr[i].grade = 'C' :
        arr[i].avg[i] >= 60 ? arr[i].grade = 'D' : arr[i].grade = 'F');

        cout << arr[i].grade << endl;
    }
    
    return arr;
}

void destroy(Grades *arr, const int STDNTS){
    for(int i = 0; i < STDNTS; i++){
        delete [] arr[i].tests;
        delete [] arr[i].avg;
    }
    
    delete [] arr;
}
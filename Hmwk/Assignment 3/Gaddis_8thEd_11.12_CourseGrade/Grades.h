/* 
 * Author: Kenzie Vasquez
 * Created on March 25, 2017, 11:23 AM
 * Purpose: Holds student data
 */

#ifndef GRADES_H
#define GRADES_H

struct Grades {
    string name;            //Student Name
    string idNum;           //Student ID #
    unsigned short *tests;  //Pointer to an array of test scores
    float *avg;             //Average test score
    char grade;             //Course grade
};

#endif /* GRADES_H */


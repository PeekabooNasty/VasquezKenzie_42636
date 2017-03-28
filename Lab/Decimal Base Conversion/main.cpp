#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int cnvrsn(int, string &, const int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 100;
    int input, num;
    string ans = "";
    
    //Input or initialize values Here
    do {
        cout << "What base would you like to convert decimal to?\n"
                "1. Binary\n"
                "2. Octal\n";
        cin >> input; cin.ignore();
    } while(input < 1 || input > 2);
    
    do {
        cout << "\nEnter a positive number to convert.\n";
        cin >> num; cin.ignore();
    } while(num < 0 || num > 2147483647);
    
    cout << endl;

    //Process/Calculations Here
    switch(input){
        case 1: cnvrsn(num, ans, 2); break;   
        case 2: cnvrsn(num, ans, 8); break;
        default: cout << "Something went wrong.\n";
    }

    //Output Located Here
    cout << "Answer: ";
    for (int i = ans.length() - 1; i >= 0; i--) cout << ans[i];

    //Exit
    return 0;
}

int cnvrsn(int x, string &ans, const int BASE){
    int temp;
    string digit = "0123456789ABCDEF";
    
    if (x == 0) return 0;
    
    ans += digit[x % BASE];
    
    temp = x / BASE;
    
    cnvrsn(temp, ans, BASE);
}
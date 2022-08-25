#include <iostream>
#include <string>
#include "RomanToInt.cpp"
#include "Palindrome.cpp"

using namespace std;


//To run functions in vscode use ctrl+alt+n uses code runner

int main() {
    
     cout << "RomanToInt sol: " << endl;
     Solution s1;
     s1.romanToInt("MMCCCXCIX");
   
    cout << "Palindrome Sol: " << endl; 
    Palindrome p1;
    string d = "abbapdfdf";

    
    cout << d.length() << " string size is <--- \n";
    cout <<"half point of string: " << d.length()/2 << " \n char at mid pt: " << d.at(d.length()/2)<< endl;
    
    p1.longestPalindrome(d);

    return 0;
    

    
    

}
// 


#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int value = 0;
        int counter[7] = { 0, 0, 0, 0, 0, 0, 0 };
        int lastVal = -1;

        for (int i = 0; i < len; i++) {
            switch (s.at(i)) {
            case 'I': 

                if (lastVal != 1) {}
                else {
                    counter[0] += 1;
                }

                value += 1;
                lastVal = 1;
                break;

            case 'V':

                if (lastVal != 5) {

                }
                else {
                    counter[1] += 1;
                }


                if (lastVal == 1) {
                    value += 3;
                }
                else {
                    value += 5;
                }

                lastVal = 5;
            break;

            case 'X':
                if (lastVal != 5) {

                }
                else {
                    counter[2] += 1;
                }

                if (lastVal == 1) {
                    value += 8;
                }
                else {
                    value += 10;
                }

                lastVal = 10;
                break;

            case 'L':
                if (lastVal != 5) {

                }
                else {
                    counter[3] += 1;
                }
                if (lastVal == 10) {
                    value += 30;
                }
                else {
                    value += 50;
                }

                lastVal = 50;
                break;

            case 'C':
                if (lastVal != 5) {

                }
                else {
                    counter[4] += 1;
                }
                if (lastVal == 10) {
                    value += 80;
                }
                else {
                    value += 100;
                }
                lastVal = 100;
                break;

            case 'D':
                if (lastVal != 5) {

                }
                else {
                    counter[5] += 1;
                }                if (lastVal == 100) {
                    value += 300;
                }
                else {
                    value += 500;
                }
                lastVal = 500;
                break;

            case 'M':
                if (lastVal != 5) {

                }
                else {
                    counter[6] += 1;
                }                if (lastVal == 100) {
                    value += 800;
                }
                else {
                    value += 1000;

                }
                lastVal = 1000;
                break;
            }
        } // eof_for

        int counterLen =
            sizeof(counter) /
            sizeof(counter[0]); // gets the length of the counter by starting one
                                // space away and then the second array starts from
                                // postion 0 and the two finds the differnece in
                                // units giving us the legnth
        bool isValid = true;
        for (int r = 0; r < counterLen; r++) {
            if (counter[r] > 2) {
                value = 0;
                cout << "Invalid Entry It is not a roman number. Err at counter[" << r << "]";
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cout << "The roman number " << s << " translates to " << value << endl;
        }

        return value;
    }//eof_fun


    
};




#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int option, number;
	short a = 1, b = 1;
	short counter = 0;
	int nValueHolder;
	do {
		cout << "HERES THE MENU" << endl << "1. Display in reverse order " << endl << "2. Display in order " << endl;
		cout << "3. Calculate n! " << endl << "4. EXIT" << endl;
		cout << "Enter an option: ";
		cin >> option;

		while (option < 1 || option > 4) {
			cout << "you have entered a value out of the options \n" << "please choose a number from 1 - 4 according to the menu \n";
			cin >> option;

		}

		switch (option) {
		case 1:
			int display;
			cout << "enter any number" << endl;
			cin >> number;
			while (number != 0) {
				display = number % 10;
				number /= 10;
				cout << display << endl;
			}
			break;
		
		case 2:
			
			int orderDisplay;

			cout << "enter any number" << endl;
			cin >> number;
			nValueHolder = number;
			while (nValueHolder != 0) {
				nValueHolder /= 10;
				counter++;
			}
			while (number != 0) {
				counter--;
				orderDisplay = number / (int)pow(10, counter);
				number %= (int)pow(10, counter);

				cout << orderDisplay << endl;
			}
			break;

		case 3:
			int n;
			int factorial, i;

			cout << "Enter a positive integer: ";
			cin >> n;

			for (i = 0; i <= n; i++)

				if (i == 0)
					factorial = 1;
				else
					factorial = factorial * i;

			cout << "The factorial of " << n << " is " << factorial << endl;
			break;
		case 4: 
			cout << "BYE!!!!";

		}
	} while (option != 4);


	system("pause");
	return 0;
}
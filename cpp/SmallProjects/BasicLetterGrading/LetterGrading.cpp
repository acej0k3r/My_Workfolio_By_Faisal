#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*int main() {
char character;
int sidesize = 0;
cout << "enter a sidesize ";
cin >> sidesize;
cout << "enter a character ";
cin >> character;
for (int c = 1; c <= sidesize; c++)

{
for (int i = 1; i <= sidesize; i++)
cout << character;
cout << endl;
}



system("pause");
return 0;
}*/

/*int main() {
	int  num, a, b = 2, c;
	

	cout << "Please enter a number you want prime factorizing of ";
	cin >> num;
	int primes = num;
	cout << "The prime factors of the number " << num << " is\are: " << endl;
	for (a = 0; a <= num; a++) {
		if (primes % b == 0) {
			c = b;
			primes /= b;
			cout << c << " ";
		}
		else {
			b++;
		}
	
		
	}
	

	system("pause");
	return 0;
}*/



/*int main() {

	long int decimalnumber, d;
	string binary = "";
	cout << "enter any decimal number";
	cin >> decimalnumber;
	do {

		d = decimalnumber % 2;

		decimalnumber /= 2;
		binary.insert(0, to_string(d));

	} while (decimalnumber != 0);
	cout << binary << endl;

	cout << endl;



	system("pause");
	return 0;
}*/

int main() {
	int dec, holder, i;
	int d, r, q, l, p;
	string psy = " ";
	cout << "enter a decimal number ";
	cin >> dec;
	i = dec;
	while(i != 0) {
		int x = i;
		i /= 16;
		holder = x % 16;
		r = 65; 
		d = (char)r;
		cout << r << endl << endl;




		switch (holder) {
			case 10:
				holder = (char)'A';
				break;
			case 11:
				holder = (char)'B';
				break;
			case 12:
				holder= (char)'C';
				break;
			case 13:
				holder= (char)'D';
				break;
			case 14:
				holder = (char)'E';
				break;
			case 15:
				holder =(char)'F';
				break;

			}
		
	
		
		
		
		
	}
	system("pause");
	return 0;
}

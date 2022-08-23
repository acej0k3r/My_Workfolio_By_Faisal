#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string dtob(int decimal) {
	int dec;
	string bin;
	do {
		dec = decimal % 2;
		decimal /= 2;
		//inserts dec values in bins
		bin.insert(0, to_string(dec));
	} while (decimal != 0);
	return bin;
}

string dtoo(int decimal) {
	int dec;
	string octal;
	
	do {
		dec = decimal % 8;
		decimal /= 8;
		octal.insert(0, to_string(decimal));
	} while (decimal != 0);
	return octal;
}

string dtoh(int n) {
	int dec;
	string hexDecimal;

	do {
		dec = n % 16;
		n /= 16;
		switch (dec) {
		case 10:
			hexDecimal.insert(0, "A");
			break;
		case 11:
			hexDecimal.insert(0, "B");
			break;
		case 12:
			hexDecimal.insert(0, "C");
			break;
		case 13:
			hexDecimal.insert(0, "D");
			break;
		case 14:
			hexDecimal.insert(0, "E");
			break;
		case 15:
			hexDecimal.insert(0, "F");
			break;
		default:
			hexDecimal.insert(0, to_string(dec));
			break;
		}
	} while (n != 0);
	return hexDecimal;
}

// program 4 got stuck

float larger(float val1, float val2) {
	if (val1 > val2)
		return val1;
	else
		return val2;
}

int main()
{
	int decimal;
	string binary, hex, octal;
	cout << "Enter a decimal: ";
	cin >> decimal;
	binary = dtob(decimal);
	hex = dtoh(decimal);
	octal = dtoo(decimal);

	cout << decimal << " to binary is " << binary << endl;
	cout << decimal << " to hex is " << hex << endl;
	cout << decimal << " to octal is " << octal << endl;

	float n1, n2;
	cout << "Enter a number: ";
	cin >> n1;
	cout << "Enter another number: ";
	cin >> n2;
	cout << "The larger number is " << larger(n1, n2) << endl;

	system("pause");
	return 0;

}
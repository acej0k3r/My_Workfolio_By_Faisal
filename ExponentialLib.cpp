#include<iostream>
#include<cmath>
using namespace std;

/*int main() {

int num, sum = 0 ,c = 1;

cout << "Please enter any number ";
cin >> num;
//equation
while (sum < num
{
if (num % c == 0)
sum = sum + c;
c++;
}

//answer
if (sum == number){
cout << "The number you provided is perfect \n";
}
else{
cout << " The number you provided is not perfect \n";
}


system("pause");
return 0;

}*/
/*int main()
{
	int num, posNum = 0, negNum = 0, zeros = 0, posCk,negCk,zeroCk;
	cout << "Enter 10 integer numbers, the program returns the percentage of all positive\n";
	cout << "numbers, the percentage of all negative numbers and the percentage of all the zeros." << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter integer number ";
		cin >> num;
		if (num > 0)
			posNum++;

		else if (num < 0)
			negNum++;
		else
			zeros++;

	}
	posCk = posNum;
	negCk = negNum;
	zeroCk = zeros;
	int x,i,s;
	

	for (x = 0; x <= 100; x += 10) {
		cout << x << "   ";
		if (x == 100) {
			cout << "\n";
		}
	}
		for (i = 0; i < 110; i += 10) {
			cout << "|    ";
			if (i == 100) {
				cout << "\n";
			}
				
		}
		for (s = 0; s < 100; s+=10) {
		
			cout << "*****";
			if (s == 90) {
				cout << "\n\n";
			}
		}
		int posCt = posCk - 1, negCt = negCk - 1, zeroCt = zeroCk - 1;

		if (posCk > 0) {
			
		for (int l = 0; l < posCk; l++) {
			cout << "*****";
			if (l == posCt) {
				cout << "* percentage of positive numbers: " << posNum * 10 << "%" << endl;
			}

		}
	
		}
		else {
			cout << "*" << "percentage of positive numbers: " << posNum * 10 << "%" << endl;;
		}


		if (negCk > 0) {
			for (int y = 0; y < negCk; y++) {
				cout << "*****";
				if (y == negCt) {
					cout << "* percentage of negative numbers: " << negNum * 10 << "%" << endl;
				}

			}
		}
		else {
			cout << "*" << "percentage of negative numbers: " << negNum * 10 << "%" << endl;
		}
		if (zeroCk > 0) {


			for (int z = 0; z < zeroCk; z++) {
				cout << "*****";
				if (z == zeroCt) {
					cout << "* percentage of zeros: " << zeros * 10 << "%" << endl;
				}

			}
		}
		else {
			cout << "*" << "percentage of zeros: " << zeros * 10 << "%" << endl;
		}
		
		
	system("pause");
	return 0;
}*/


int main() {
	int integer,addRoot, addPers = 0,nValueHolder, counter =0,orig;
	cout << "Please enter an integer ";
	cin >> integer;
	int orderDisplay;
	//breaks apart integer
	orig = integer;
	nValueHolder = integer;
	int number = integer;
	
	while (nValueHolder > 9) {
		while (nValueHolder != 0) {
			nValueHolder /= 10;
			counter++;
		}
		while (integer != 0) {
			counter--;
			orderDisplay = integer / (int)pow(10, counter);
			integer %= (int)pow(10, counter);

			nValueHolder = nValueHolder + orderDisplay;
			
			if (nValueHolder <= 9) {
				addRoot = nValueHolder;
			}
			addPers++;
		}
		if (integer == 0) {
			integer = nValueHolder;
		}
	}

	cout << "The additive root of the integer you entered";
	cout << orig << "is: " << addRoot << endl;
	cout << "It has an additive persistence of " << addPers << endl;






	system("pause");
	return 0;

	}



/*int main() {


	int base, c,exponent;
	long result = 1;
	cout << "enter a base ";
	cin >>base;
	cout << "enter an exponent ";
	cin >> exponent;
	for (c = 0; c < exponent; c++)
	{
	result *= base;

	}
	cout << "your answer is \n" << result;

	system("pause");
	return 0;
	}
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int randomNgen(int x);

int main()
{
	int count;
	cout << "if you want to encrypt press 1, if you want to decrypt press 2 " << endl;
	cin >> count;

	
	string text, cipherText;
	int  randNum;
	if (count == 1) {
		srand(time(0));
		randNum = randomNgen((int)rand() % 124);
		cout << randNum << " is your key remember this number " << endl;
		cout << "Enter a text you want to cipher " << endl;
		cin.ignore();
		getline(cin, text);
		int p = (int)text.length();
		cipherText = text;
		// algorithm for loping thru each letter
		for (int i = 0; i < (int)text.length(); i++) {
			if (isalpha(text[i])) {
				for (int p = 0; p < randNum; p++) {
					if (text[i] == 'z') { // checks if at z then a 
						text[i] = 'a';
					}
					else {
						text[i]++;
					}
				}
				cipherText[i] = text[i];
			}
			else if (isspace(text[i])) {

				cipherText[i] = text[i];
			}
	
		}
		ofstream cipherFile("cipherFile.txt");
		if (cipherFile.is_open()) {
			cipherFile << cipherText;
		}
		else {

			cout << "The file is not open and there for cipher text will not be entered in the file \n";
			exit(1);
		}
		cipherFile.close();
		cout << endl;
	}
// DECRYPTOIN PROGRAM
	if (count == 2) {
		string orgText;
		int val;
		cout << "Please note you need the random key that only you know \n";
		cout << "please enter your secret key ";
		cin >> val;
		string cipherT;
		ifstream Hola;
		Hola.open("cipherFile.txt");
		if (Hola.is_open()) {
			cin.ignore();
			getline(Hola, cipherT);
			orgText = cipherT;

			for (int i = 0; i <= cipherT.length(); i++) {
				if (isalpha(cipherT[i])) {
					for (int p = 0; p < val; p++) {
						if (cipherT[i] == 'a') {
							cipherT[i] = 'z';
						}
						else {
							cipherT[i]--;
						}					
					}
					orgText[i] = cipherT[i];
				}
				else if (isspace(cipherT[i])) {
	
					orgText[i] = cipherT[i];
				}
				
			}

			cout << orgText << endl;

			ofstream orgTxt("orgTxt.txt");
			orgTxt << orgText;

			orgTxt.close();

		}
		else {
			cout << "The file is not open and there for cipher"
				<< "text will not be retrieved " << endl;
			exit(1);
		}

	}

	system("pause");
	return 0;
}


int randomNgen(int x) {
	int y;
	srand(rand()%300);
	y = (int)(rand() % x) + 1;
	while(y > 26) {

		y -= 26;

	}
	
	return y;

}
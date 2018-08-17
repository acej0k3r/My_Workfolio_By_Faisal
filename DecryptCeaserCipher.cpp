#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<fstream>


using namespace std;
int main() {
	string cipherT;
	ifstream cipherFile;
	cipherFile.open("cipherFile.txt");
	if (cipherFile.is_open()) {
		getline(cipherFile, cipherT);

		cout << cipherT;


	}
	else {
		cout << "The file is not open and there for cipher" 
			<< "text will not be retrieved " << endl;
		exit(1);

	}



	system("pause");
	return 0;
}










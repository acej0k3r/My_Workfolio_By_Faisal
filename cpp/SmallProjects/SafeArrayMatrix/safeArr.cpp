//============================================================================
// Name        : safe.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;



template<class T>
// THIS CLASS WILL ALLOW US TO OVERLOAD [] and we can OVERLOAD[] Matrix class as well to create Matrix[][]
class Col {

private:
	int low, high;
	T* p;


public:
	//default constructor
	Col() {
		low = 0;
		high = -1;
		p = NULL;
	}


	//2 parameter contructor

	Col(int l, int h) {
		//out of bounds
		if ((h - l + 1) <= 0) {
			cout << "constructor error in bounds definition the bounds must be greater than 0" << endl;
			exit(1);
		}

		low = l;
		high = h;
		p = new T[h - l + 1];
	}




	//single parameter constructor where low bound = 0;

	Col(int i) {
		low = 0;
		high = i - 1;

		p = new T[i];

	}


	//copy constructor for pass by value
	Col(const Col& r) {
		int size = r.high - r.low + 1;
		p = new T[size];

		for (int i = 0; i < size; i++) {
			p[i] = r.p[i];
		}


		low = r.low;
		high = r.high;



	}



	//destructor
	~Col() {
		delete[] p;
	}

	//update row function
	Col<T>& getRef() {
		return *this;

	}



	//overloaded []

	T& operator[](const int& i) {
		if (i< low || i > high) {
			cout << "col index " << i << " out of range" << endl;
			exit(1);
		}


		return p[i - low];
	}





	//overloaded =


	Col& operator=(const Col& r) {
		if (this == &r) return*this;
		delete[] p;

		int size = r.high - r.low + 1;
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = r.p[i];
		}

		low = r.low;
		high = r.high;
		return*this;

	}


	//Assign pointers

//print

	void printMem() {
		cout << "low is " << low << "\n" << " high is" << high << endl;
	}


	//will not need to overload << here because this will be in the matrix class


//end of row class
};

template<class T>
class Matrix {


private:
	int low, high;
	int low2, high2;
	Col<T>* p;





public:

	//default constructor
	Matrix() {
		low = 0;
		high = -1;
		low2 = 0;
		high2 = -1;

		p = NULL;
	}


	//Parameterized constructor
	Matrix(int l, int h, int l2, int h2) {

		int size = h - l + 1;
		int size2 = h2 - l2 + 1;

		if ((size <= 0) || (size2 < 0)) {
			cout << "out of bounds matrix values" << endl;

			exit(1);
		}
		cout << "Constructor has taken inputs successfully" << endl;
		low = l;
		high = h;
		low2 = l2;
		high2 = h2;
		//anytime the row value is updated by other means we must update the ptr for row to get correct size
		//** pointing to a set of pointers which will be in col


		p = new Col<T>[size];


		//point to a location of column array gets the pointers for column
		//hence now we have an array of pointers
		for (int i = 0; i < size; i++) {

			Col<T> col(low2, high2);
			p[i] = col.getRef();

		}





	}







	// Double high bound value constructor

	Matrix(int h, int h2) {
		low = 0; low2 = 0;
		high = h - 1; high2 = h2 - 1;

		p = new Col<T>[h];
		for (int i = 0; i < h; i++) {
			Col<T> col(low2, high2);
			p[i] = col.getRef();


		}
	}

	//copy constructor for pass by value
	Matrix(const Matrix& mx) {
		int size = mx.high - mx.low + 1;
		p = new Col<T>[size];


		for (int i = 0; i < size; i++) {
			p[i] = mx.p[i];
		}




		low = mx.low;
		high = mx.high;
		low2 = mx.low2;
		high2 = mx.high2;
	}


	//destructor
	~Matrix() {
		delete[] p;
	}




	//overload col[] but also this will allow us to now finally use row[] as well. creating[][]
	Col<T>& operator[](int j) {
		if (j<low || j>high) {
			cout << "Row index " << j << " out of range" << endl;
			exit(1);
		}

		//p[j-low];



		return p[j - low];
	}



	Matrix<T>& operator=(const Matrix<T>& r) {
		if (this == &r) return*this;
		delete[] p;

		int size = r.high - r.low + 1;


		p = new Col<T>[size];

		for (int i = 0; i < size; i++) {
			p[i] = r.p[i];
		}

		low = r.low;
		high = r.high;
		low2 = r.low2;
		high2 = r.high2;
		return*this;

	}




	//operator overload *
	friend	Matrix<T> operator*(Matrix<T> m1, Matrix<T>n2) {
		//Matrix 1   m row / m2 col
		int sizeM = m1.high - m1.low + 1;
		int sizeM2 = m1.high2 - m1.low2 + 1;

		//Matrix 2
		int sizeN = n2.high - n2.low + 1;
		int sizeN2 = n2.high2 - n2.low2 + 1;

		Matrix<T> temp(sizeM, sizeN2); //if m1(3x2) & n1(2x3) so the return must be z(3x3)

		//how ever this will not work if m1(4x2) & n1(3x4) 2 != 3 therefore we would return an empty 4x4 matrix;
		if (sizeM2 != sizeN) {
			cout << "\n\nWARNING! Matrix cannot be multiplied. Matrix 1s Y value must match matrix 2s X value \n";
			cout << "Hence, Matrix(3x2) * Matrix (2x3) is allowed, however Matrix(3X2) * Matrix (3x2) is now allowed \n";
			cout << "Returned Matrix Z WILL BE A MATRIX OF SIZE (" << sizeM << " , " << sizeN2 << ") but empty indicating multiplication did not work!" << endl;

			return temp;
		}


		//testing 2x3  3x2
				//sieze M = row of matrix 1
				//sizeN2 = col of matrix 2
				// sizeN = row of matrix 2

		cout << "Matrix multiplication has started" << endl;
		for (int i = 0; i < sizeM; i++) {
			for (int j = 0; j < sizeN2; j++) {
				temp[i][j] = 0;

				for (int k = 0; k < sizeN; k++) {
					temp[i][j] += m1[i][k] * n2[k][j];
				}


			}
		}


		return temp;
	}



	friend ostream& operator<<(ostream& os, Matrix<T> mx) {
		cout << "____________" << endl;
		int size = mx.high - mx.low + 1;
		int size2 = mx.high2 - mx.low2 + 1;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size2; j++) {
				os << mx.p[i][j] << " ";
			}
			cout << endl;
		}
		return os;
	}






};
















int main() {

	cout << "Running Safe Array Code" << endl;

	Matrix<int> a(0, 1, 0, 3);
	Matrix<int> b(0, 3, 0, 1);

	//safe array a values
	a[0][0] = 1;
	a[0][1] = 4;
	a[0][2] = 4;
	a[0][3] = 0;
	a[1][0] = 3;
	a[1][1] = 4;
	a[1][2] = 3;
	a[1][3] = 2;

	//safe array b values
	b[0][0] = 2;
	b[0][1] = 6;
	b[1][0] = 3;
	b[1][1] = 1;
	b[2][0] = 2;
	b[2][1] = 4;
	b[3][0] = 5;
	b[3][1] = 7;

	cout << a;
	cout << b;

	Matrix<int> z;

	z = a * b;

	cout << z;
	cout << "Has ended";

	return 0;
}

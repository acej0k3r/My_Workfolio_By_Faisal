#include <iostream>
#include<fstream>
#include <cstdlib>
#include<cmath>

using namespace std;



class listNode {
	friend class linkedListQueue;
	friend class linkedListStack;
	friend class radixSort;
	int data;
	listNode* next;
	listNode(){
		next = NULL;
	
	}
	

};

class linkedListStack {
	friend class radixSort;
public:
	listNode* top = new listNode;

	linkedListStack() {
		top = NULL;
		
	}
	void push(int x) {
		listNode* temp = new listNode;
		temp->data = x;
		temp->next = top;
		top = temp;

		
		
	}

	int pop() {
		listNode* temp = new listNode;
		temp = top;
		top = top->next;
		return temp->data;
	}

	bool isEmpty() {
		if (top == NULL) {
			return 1;
		}
		else if (top != NULL) {
			return 0;
		}
	}


	void printStack(linkedListStack lls, string x) {
		ofstream outFile1;
		outFile1.open(x, std::ios_base::app);
		outFile1 << "THIS IS THE OFFSET STACK \n";
		listNode* curr = new listNode;
		curr = top;
		while (curr != NULL) {
			outFile1 << curr->data << "\n";
			curr = curr->next;
		}


	}




};






class linkedListQueue {
	friend class radixSort;
public:	
	listNode* head = new listNode();
	listNode* tail = new listNode();
	listNode* dummy = new listNode();
	linkedListQueue() {
		head->next = dummy;
		tail->next = dummy;

	}
	void addTail(int x) {
		listNode* temp = new listNode;
		if (!isEmpty2()) {
			temp->data = x;
			tail->next = temp;
			tail = temp;
		}
		else {
			temp->data = x;
			dummy->next = temp;
			tail = temp;
		}
	}

	int deleteFront() {
		if (!isEmpty2()) {
			listNode* holder = new listNode;
			holder = dummy->next;

		if (dummy->next->next != NULL) {		
				dummy->next = dummy->next->next;
				dummy = holder;
				head->next = dummy;
	
			}
			else if (dummy->next->next == NULL) {
				dummy = dummy->next;
				dummy->next = NULL;
				head->next = dummy;  
			}
			
		}
		return dummy->data;
		
	}
	
	bool isEmpty2() {
		if (this->dummy->next == NULL) {
			return 1;
		}
		else if (this->dummy->next != NULL) {
			return 0;
		}

	}

	void printQ(string x) {
		ofstream outFile;
		outFile.open(x,ios_base::app);

		listNode* curr = new listNode;
		curr = this->head->next;
		if (!isEmpty2()) {
			outFile << "FRONT:   ";
			while (curr != tail) {
				outFile << curr->next->data << "\t";
				curr = curr->next;
			}
			outFile << "\nTAIL:   ";
			outFile << this->tail->data << "\t" << "NULL" << endl;


		}
		else {
			outFile << "NULL";
		}

		
	}


};

	class radixSort {
		
	public:
		
		int tableSize = 10;
		int data;
		int currentTable = 0;
		int previousTable = 0;
		int maxDigits;
		int offSet;
		int currentDigit;
		linkedListQueue hashTable[2][10];
		int mul = 1;
		int n = 1;
		int m = 10;






		void firstReading() {
			ifstream inFile;
			inFile.open("RadixSort_Data.txt");
			if (!inFile) {
				cerr << "Unable to open File to read";
				exit(1);
			}
			int curr;
			int min = 0;
			int max = 0;
			while (inFile >> curr) {
				if (curr >= max) {
					max = curr;
				}
				if (curr <= min) {
					min = curr;
				}
			}
		
			maxDigits = getMaxDigits(max) + 1;
			offSet = ((int)abs((double)min));

			inFile.close();
		}

		linkedListStack loadStack(string fileName,linkedListStack lls) {
			ifstream inFile;
			inFile.open(fileName);
			if (!inFile) {
				cerr << "Unable to open file to read";
				exit(1);
			}
			int x;
			while (inFile >> x) {
				//push creates a new node and pushes it
				x += offSet;
				lls.push(x);
			}
			inFile.close();
			return lls;

		}

		void dumpStack(linkedListStack ls) {
			while (!ls.isEmpty()) {

				listNode* nd = new listNode;
				nd->data = ls.pop();

				 int digit = getOneDigit(nd->data);
				 hashTable[currentTable][hashIndex(digit)].addTail(nd->data);
				
			}
			
			printTable();

			
		}

		void tableIndex() {

		}
		int getMaxDigits(int x) {
			int n = x;
			int curr = 0;
			while (n > 0) {
				n /= 10;
				curr++;
			}
			return curr;
		}

		int getOneDigit(int x) {
			m *= mul;
			n *= mul;

			x = x % m;
			x = x / n;

			return x;
			

		}

		int hashIndex(int digit) {
			
			return digit;


		}

		radixSort() {

		}

		void printTable(){
			for (int i = 0; i < 10; i++) {
				while (!(hashTable[currentTable][i].isEmpty2())) {
					hashTable[currentTable][i].printQ("outFile2.txt");
					
				}

				
			}


			


		}


	};


	int main() {
		//WILL STOP APPENDING THE FILE EVEYRTIME THE PROGRAM RUNS
		ofstream outF;
		outF.open("outFile2.txt");
		outF.close();
	
		radixSort rs;
		rs.firstReading();
		linkedListStack lls;

		lls = rs.loadStack("RadixSort_Data.txt", lls);
		lls.printStack(lls, "outFile2.txt");
		rs.dumpStack(lls);
		


		system("pause");
		return 0;

	}




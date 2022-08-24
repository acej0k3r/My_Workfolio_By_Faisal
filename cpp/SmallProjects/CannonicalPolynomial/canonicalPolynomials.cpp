//============================================================================
// Name        : canonicalPolynomials.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


struct node
{
	int cof;
	int deg;
	node* next;
};


class linked_list
{
private:
	node* head, * tail;
	int size = 0;


public:
	linked_list()
	{
		head = NULL;
		tail = NULL;

	}







	void add_node(int cof, int deg)
	{
		//Node initialized
		node* tmp = new node;
		tmp->cof = cof;
		tmp->deg = deg;
		tmp->next = NULL;

		if (head != NULL)
		{
			tail->next = tmp;
			tail = tail->next;

		}
		else
		{
			head = tmp;
			tail = tmp;
		}

		size++;
	}




	void add_linkedListNodes(node* n)
	{
		//Node initialized


		if (head != NULL)//when theres already nodes loaded head!= Null meaning we just wanna continue adding to the current linked list
		{

			//loops through and add all nodes to the linkedlist
			while (n->next != NULL) {
				node* tmp = new node;
				tmp->cof = n->cof;
				tmp->deg = n->deg;
				tmp->next = NULL;


				tail->next = tmp;
				tail = tail->next;
				++size;

				n = n->next;

			}

			node* tmp2 = new node;
			tmp2->cof = n->cof;
			tmp2->deg = n->deg;
			tmp2->next = NULL;

			tail->next = tmp2;
			tail = tail->next;
			++size;

		}
		else// else new linked list and this set of nodes will be the first set applied to the linked list
		{
			node* tmp = new node;
			tmp->cof = n->cof;
			tmp->deg = n->deg;
			tmp->next = NULL;

			head = tmp;
			tail = tmp;
			++size;

			while (n->next != NULL) {

				node* tmp1 = new node;
				n = n->next;
				tmp1->cof = n->cof;
				tmp1->deg = n->deg;
				tmp1->next = NULL;

				tail->next = tmp1;
				tail = tail->next;
				++size;


			}
		}


	}





	node* gethead() {
		return head;
	}

	int getSize() {
		return size;
	}







	string display() {
		node* curr = head;
		string x;

		while (curr->next != NULL) {

				//We compare the degrees and based on that we would show x^2, or x or no x
						if (curr->deg > 1)
						{


									if (curr->cof == 1 || curr->cof == -1) {
										switch(curr->cof){
										case 1:
											x += "x^" + to_string(curr->deg);
										case -1:
											x += "-x^" + to_string(curr->deg);
										}

									}
									else {
										x += to_string(curr->cof) + "x^" + to_string(curr->deg);

									}
						}
						else if (curr->deg == 1)
						{

							if(curr->cof == 1 || curr->cof == -1){

									switch(curr->cof){
									case 1:
										x += "x";
									case -1:
										x += "-x";

										}
							}else {
								x += to_string(curr->cof) + "x";
							}


						}
						else
						{

							if(curr->cof != 0)
								x += to_string(curr->cof);
						}


					//makes sure we distribute the + or - depending on the next coefficient for ex: +(-3) = -3;
					if (curr->next != NULL && curr->next->cof >= 0) {
						x += " +";
					}
					else {
						x += " ";
					}

					curr = curr->next;
		}


		//because we check next != null must run the code one more time for the last node; kind of redundant in terms of coding but it works!
		if (curr->deg > 1) {
			if (curr->cof == 1 || curr->cof == -1) {
				switch(curr->cof){
				case 1:
					x += "x^" + to_string(curr->deg);
					break;
				case -1:
					x += "-x^" + to_string(curr->deg);
					break;
				}
			}
			else {
				x += to_string(curr->cof) + "x^" + to_string(curr->deg) + "\n";

			}

		}
		else if (curr->deg == 1) {
			if (curr->cof == 1 || curr-> cof == -1) {
				switch(curr->cof){
				case 1:
					x += "x\n";
					break;
				case -1:
					x += "-x\n";
					break;


				}

			}
			else {
				x += to_string(curr->cof) + "x" + "\n";
			}

		}
		else {
			if(curr->cof != 0)
			x += to_string(curr->cof) + "\n";


		}

		cout << x;
		return x;

	}




	void sortConsolidate() {
		//Sort code
		node* cur1 = head;
		node* cur2 = head;
		int si = getSize();
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < si - 1; j++) {
				if (cur1->deg > cur2->deg) {
					int tempC = cur1->cof;
					int tempD = cur1->deg;


					cur1->cof = cur2->cof;
					cur1->deg = cur2->deg;
					cur2->cof = tempC;
					cur2->deg = tempD;


				}
				cur2 = cur2->next;
			}//inner loop
			cur2 = head;
			cur1 = head->next;
			for (int k = 0; k < i; k++) {
				cur1 = cur1->next;
			}
		}

		//Consolidate code

		cur1 = head;
		cur2 = head;
		node* tmp;
		while (cur2->next != NULL) {
			cur2 = cur2->next;
			//since we know that the list is sorted the last value and the penultimate degree is either same or not the same.
			//If its same then it will merge otheriwse it will do nothing for the last term

			if (cur1->deg == cur2->deg) {
				cur1->cof += cur2->cof;

				tmp = cur1->next;
				cur1->next = cur2->next;

				size--;


				delete tmp;
			}
			else {
				cur1 = cur1->next;
			}


		}




	}



	void makeNegative() {
		node* cur;
		cur = head;

		while (cur->next != NULL) {
			cur->cof = (cur->cof * -1);
			cur = cur->next;
		}

		cur->cof = (cur->cof * -1);


	}



	void distribution(node* set1, node* set2) {

		node* cur1 = set1;
		node* cur2 = set2;
		int cof;
		int deg;
		while (cur1->next != NULL) {

			while (cur2->next != NULL) {
				cof = cur1->cof * cur2->cof;
				deg = cur1->deg + cur2->deg;
				add_node(cof, deg);

				cur2 = cur2->next;
			}
			cof = cur1->cof * cur2->cof;
			deg = cur1->deg + cur2->deg;
			add_node(cof, deg);

			cur2 = set2;

			cur1 = cur1->next;

		}



		//because we check next != null must run the code one more time for the last node; kind of redundant in terms of coding but it works!
		while (cur2->next != NULL) {
			cof = cur1->cof * cur2->cof;
			deg = cur1->deg + cur2->deg;
			add_node(cof, deg);

			cur2 = cur2->next;
		}
		cof = cur1->cof * cur2->cof;
		deg = cur1->deg + cur2->deg;
		add_node(cof, deg);







	}



};



class Canonical {
private:
	linked_list* dataSet;
	linked_list* l1;
	linked_list* l2;
	linked_list* l3;
	int rows;
	string degree;
	string polynomial;
	bool negativeNum = false;
	bool isPoly = true;
	string finalOutput;




public:
	Canonical() {

		dataSet = NULL;
		l1 = NULL;
		l2 = NULL;
		l3 = NULL;
		rows = 0;
	}

	Canonical(string fi, int r) {
		rows = r;
		//dynamic linked list in memory so if the file has 10 sets of data then there will be 10 linked lists
		dataSet = new linked_list[rows];
		l1 =  new linked_list[rows/2];;
		l2 = new linked_list[rows/2];;
		l3 = new linked_list[rows/2];;

		int fileSize = fi.length();

		int cof = 0;
		int deg = 0;
		int currDataSet = 0; // will track the current linked list

		cout << "\n Constructor Initializing..." << endl;
		for (int i = 0; i < fileSize; i++) {


			if (fi[i] == '-') {

				negativeNum = true;

			}
			else if (fi[i] == ',') {

				currDataSet++;



			}
			else if (fi[i] != ' ') {

				if (isPoly) {
					if (negativeNum) {
						//get character -48 from ascii to gain integer value and cast to int
						//Also for negative *-1
						cof = (int)-1 * (fi[i] - 48);
						negativeNum = false;
					}
					else {
						//positive
						cof = (int)(fi[i] - 48);

					}

					isPoly = false;

				}
				else {// DEGREE


					deg = (int)fi[i] - 48;
					// if its a degree we know we have a pair of cof and deg
					dataSet[currDataSet].add_node(cof, deg);

					//just to reset everything
					cof = 0;
					deg = 0;
					isPoly = true;



				}//is poly


			}//else != ' ' end

		}//for end

		cout << "The file contains the following polynomial terms in non canonical form: " << endl;
		finalOutput += "Non-Canonical Form: \n";
		for (int k = 0; k < rows; k++) {
			finalOutput += dataSet[k].display();

		}


		cout << "\nCanonical form: " << endl;

		//sort the dataSet
		finalOutput += "Canonical Form of Inputfile: \n";
		for (int i = 0; i < rows; i++) {
			dataSet[i].sortConsolidate();
			finalOutput += dataSet[i].display();


		}
		finalOutput += "_______________________\n";

		cout << "Addition" << endl;
		addPolynomialTerms();


		cout << "Subtraction" << endl;
		subPolynomialTerms();


		cout << "Multiplication" << endl;
		mulPolynomialTerms();



		//prints to external file output.txt
		printToExternalFile();

	}// constructor end






	void addPolynomialTerms() {

		int x = 0;
		int y = 1;

		node* h1;
		node* h2;

		//assuming the rows are always even
		for (int i = 0; i < rows / 2; i++) {

			h1 = dataSet[x].gethead();
			h2 = dataSet[y].gethead();

			l1[i].add_linkedListNodes(h1);
			l1[i].add_linkedListNodes(h2);

			l1[i].sortConsolidate();

			finalOutput += "Addition of terms" + to_string(x + 1) + " and " + to_string(x + 2) + ":\n";
			finalOutput += l1[i].display();
			finalOutput += "_______________________\n";

			x += 2;
			y += 2;
		}






	}


	void subPolynomialTerms() {

		int x = 0;
		int y = 1;

		node* h1;
		node* h2;

		//assuming the rows are always even
		for (int i = 0; i < rows / 2; i++) {


			h1 = dataSet[x].gethead();
			dataSet[y].makeNegative();
			h2 = dataSet[y].gethead();

			l2[i].add_linkedListNodes(h1);
			l2[i].add_linkedListNodes(h2);

			l2[i].sortConsolidate();

			finalOutput += "Subtraction of terms" + to_string(x + 1) + " and " + to_string(x + 2) + ":\n";
			finalOutput += l2[i].display();
			finalOutput += "_______________________\n";

			x += 2;
			y += 2;
		}





	}


	void mulPolynomialTerms() {

		int x = 0;
		int y = 1;
		node* h1;
		node* h2;

		//assuming the rows are always even
		for (int i = 0; i < rows / 2; i++) {

			h1 = dataSet[x].gethead();
			h2 = dataSet[y].gethead();

			l3[i].distribution(h1, h2);

			l3[i].sortConsolidate();

			finalOutput += "Multiplication of terms" + to_string(x + 1) + " and " + to_string(x + 2) + ":\n";
			finalOutput += l3[i].display();
			finalOutput += "_______________________\n";

			x += 2;
			y += 2;
		}



	}

	void printToExternalFile() {
		ofstream out;
		out.open("output.txt");
		out << finalOutput;
		out.close();
		cout << "File output is ready" << endl;


	}

	~Canonical() {
		delete[] dataSet;
		delete[] l1;
		delete[] l2;
		delete[] l3;
	}


};


int main() {
	string line;
	string file;
	int rows = 0;
	//input file data
	 /*	  -3x^2 + 5x - 2
		  4x + 2x^2 + 9x^5 + 2x
		  2x - 9 - 2x^5
		  -3 + 2x^2 + 3x^2 - x^3 + 1
	*/

	ifstream myfile("input.txt");



	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			//store entire file in a string, the reason we are reading the file first is to obtain the size so we can allocate dynamic memory as required and not excessive
			file += line + ",";
			++rows;

		}


		myfile.close();
	}
	else cout << "Unable to open file";

	//code for dynamic memory

	cout << file;
	Canonical c(file, rows);

	//system("pause");
	return 0;
}

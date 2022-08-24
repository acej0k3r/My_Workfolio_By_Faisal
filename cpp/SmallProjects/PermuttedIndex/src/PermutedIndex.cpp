//============================================================================
// Name        : PermutedIndex.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

struct node
{
	int lineNum;
	int lineDeg;
	node* next;
};


//LINKED LIST KEEPING TRACK OF ALL LINES FOR A WORD
class linked_list
{
private:
	node* head, * tail;
	int size = 0;
	string listDetail = "";


public:
	linked_list()
	{
		head = NULL;
		tail = NULL;

	}







	void add_node(int lineN)
	{

		//Node initialized
		node* tmp = new node;
		tmp->lineNum = lineN;
		tmp->lineDeg = 1;
		tmp->next = NULL;

		if (head != NULL)
		{
			if (tail->lineNum != lineN) {
				tail->next = tmp;
				tail = tail->next;
				size++;
			}
			else {
				//so we start with degree 1 if there are 3 copies in a line then deg 3 and will display as line#(deg)
				tail->lineDeg++;
				delete tmp;
			}

		}
		else
		{
			head = tmp;
			tail = tmp;
			size++;
		}

	}


	void displayListToConsole(){
		node* tmp = new node;
		tmp = head;

		cout << "[";
		while(tmp != NULL){
			if(tmp->lineDeg == 1){

				if(tmp == tail){
					cout << tmp->lineNum << "] ->";

				}else{
					cout << tmp->lineNum << ", ";

				}


			}else{

				if(tmp == tail){
					cout << tmp->lineNum << "(" << tmp->lineDeg << ")" << "] ->";
				}
				else{
				cout << tmp->lineNum << "(" << tmp->lineDeg << ")" << ", ";
				}

			}


			tmp = tmp->next;
		}

	}


	//what we output
	string displayListToFileMode(){
			node* tmp = new node;
			tmp = head;

			while(tmp != NULL){
				if(tmp->lineDeg == 1){

					if(tmp == tail){
						listDetail += to_string(tmp->lineNum) + "\n";

					}else{
						listDetail += to_string(tmp->lineNum) + ", ";

					}


				}else{

					if(tmp == tail){
						listDetail += to_string(tmp->lineNum) + "(" + to_string(tmp->lineDeg)+ ")\n";
					}
					else{
						listDetail += to_string(tmp->lineNum) + "(" + to_string(tmp->lineDeg) + ")" + ", ";
					}

				}


				tmp = tmp->next;
			}

			return listDetail;

		}

	node* gethead() {
		return head;
	}


	int getSize() {
		return size;
	}


};//END linked_list nodes


///////////////////////////////////////////////////////////////////WORD FOLDER/////////////////////////////////////////////////////////////
struct wordNode {
	string word = "";
	wordNode* nxtWord = NULL;
	linked_list* lineList = NULL;
};

struct letterNode {
	char letter;
	wordNode* nxtWord;
	letterNode* next;
	int wordQty = 0;
};




class wordFolder {
private:

	letterNode* lhead, * ltail, * lmid;
	int size = 0;
	bool doOnceFLag = 1;
	string finalOutPut;



public:
	//default constructor
	wordFolder() {
		lhead = NULL;
		ltail = NULL;
		size = 0;
		addLetterNode('a'); addLetterNode('b');	addLetterNode('c'); addLetterNode('d'); addLetterNode('e'); addLetterNode('f');
		addLetterNode('g'); addLetterNode('h');	addLetterNode('i'); addLetterNode('j'); addLetterNode('k'); addLetterNode('l');
		addLetterNode('m'); addLetterNode('n');	addLetterNode('o'); addLetterNode('p'); addLetterNode('q'); addLetterNode('r');
		addLetterNode('s'); addLetterNode('t');	addLetterNode('u'); addLetterNode('v'); addLetterNode('w'); addLetterNode('x');
		addLetterNode('y'); addLetterNode('z'); //addLetterNode('.');


		setMid();
		cout << "The middle of the list is 13 digits away and the letter is : " << lmid->letter << endl;

		cout << "Size: " << size << endl;

	}


	void setMid() {
		letterNode* tmp = new letterNode;
		tmp = lhead;

		for (int i = 0; i < 13; i++) {
			tmp = tmp->next;
		}
		lmid = tmp;
		lmid->letter = tmp->letter;
		lmid->next = tmp->next;
		lmid->nxtWord = tmp->nxtWord;

	}


	letterNode* getlHead() {
		return lhead;
	}

	void addLetterNode(char l) {
		letterNode* tmp = new letterNode;
		tmp->letter = l;
		tmp->next = NULL;
		tmp->nxtWord = NULL;
		if (lhead != NULL)
		{
			ltail->next = tmp;
			ltail = ltail->next;

		}
		else
		{
			lhead = tmp;
			ltail = tmp;
		}

		size++;
	}


	// adds word to the folder list and its line
	void addToFolder(string word, int line) {


		insertIntoLetter(getNodeLetterForWord(word), word, line);


	}



	/////////////////////////////////////////////////////11111111111111111111111111111111

	//Find which letter to insert words into
	letterNode* getNodeLetterForWord(string word) {
		letterNode* letterList = new letterNode;
		if (word[0] < 'n') {

			letterList = lhead;

			for (int i = 0; i < 13; i++) {
				if (word[0] == letterList->letter) {
					break;
				}
				letterList = letterList->next;
			}


		}
		else {// word[0] > 'm'

			letterList = lmid;

			for (int i = 0; i < 13; i++) {
				if (word[0] == letterList->letter) {
					break;
				}
				letterList = letterList->next;
			}
			if(doOnceFLag == 1){
				if(letterList-> letter == 'n'){
					doOnceFLag = 0;
					letterList->nxtWord = NULL;
				}
			}
		}
		return letterList;
	}




/////////////////////////////////////////////////////2222222222222222222222222222222
	void insertIntoLetter(letterNode* ln, string word, int line) {

		wordNode* wordPtr = new wordNode;
		wordNode* backPtr = new wordNode;

		wordPtr = ln->nxtWord;
		bool doesWordExist = 0;

		if (ln->nxtWord == NULL) {
			wordNode* wrd = new wordNode;
			linked_list* li = new linked_list;
			wrd->word = word;
			wrd->lineList = li;
			wrd->lineList->add_node(line);
			wrd->nxtWord = NULL;
			ln->nxtWord = wrd;
			ln->wordQty++;

		}
		else {


			while (wordPtr != NULL) {

				if (wordPtr->word == word) {
					doesWordExist = 1;
					wordPtr->lineList->add_node(line);
				}


				backPtr = wordPtr;
				wordPtr = wordPtr->nxtWord;
			}






				if (doesWordExist == 0) {
					wordNode* wrd = new wordNode;
					linked_list* li = new linked_list;
					wrd->word = word;
					wrd->lineList = li;
					wrd->lineList->add_node(line);
					wrd->nxtWord = NULL;
					ln->wordQty++;
					backPtr->nxtWord = wrd;
					backPtr = backPtr->nxtWord;

				}
		}


		if(wordPtr == NULL){
			delete wordPtr;
		}

		if(backPtr == NULL){
			delete backPtr;
		}
		//get rid of unnecessary pointer

	}



	void sortWords() {
			//Sort code
		letterNode* ln = new letterNode;
		ln = lhead;
		while(ln != NULL){


			wordNode* cur1 = ln->nxtWord;
			wordNode* cur2 = ln->nxtWord;
			int si = ln->wordQty;
			for (int i = 0; i < si; i++) {
				for (int j = 0; j < si - 1; j++) {
					if (cur1->word < cur2->word) {
						string tempC = cur1->word;
						linked_list *tempL = cur1->lineList;


						cur1->word = cur2->word;
						cur2->word = tempC;

						cur1->lineList = cur2->lineList;
						cur2->lineList = tempL;



					}
					cur2 = cur2->nxtWord;
				}//inner loop
				cur2 = ln->nxtWord;
				cur1 = ln->nxtWord->nxtWord;
				for (int k = 0; k < i; k++) {
					cur1 = cur1->nxtWord;
				}


			}//end of for



			ln = ln->next;
		}//end of while



}//end of sort



/////////////////////////////////////////////////////DISPLAY AND PRINT TO OUTPUT FILE/////////////////////////////////////////////////////////

	 void displayAllToConsoleAndFile(letterNode* head) {
		if (head == NULL)
		{
			cout << "NULL" << endl;
		}
		else
		{
			cout << head->letter << " -> ";
			displayWords(head->nxtWord);
			if(head->nxtWord != NULL){
				finalOutPut += "_________________________________________________________________\n";
			}
			displayAllToConsoleAndFile(head->next);
		}
	}

	 void displayWords(wordNode* node) {
		if (node == NULL)
		{
			cout << "NULL" << endl;
		}
		else
		{

			finalOutPut += node->word + ": ";
			finalOutPut += node->lineList->displayListToFileMode();


			cout << node->word << " -> ";
			node->lineList->displayListToConsole();
			displayWords(node->nxtWord);
		}
	}


	 void printToExternalFile() {
	 	ofstream out;
	 	out.open("output.txt");
	 	out << finalOutPut;
	 	out.close();
	 	cout << "File output is ready" << endl;


	 }


};//END OF CLASS WORDFILE


int main() {
	cout << "Permuted Index Program Started..." << endl; // prints !!!Hello World!!!



	wordFolder wf;
	string line;
	string word;
	int rows = 0;
	string allWords = "";



	ifstream myfile("input.txt");
	/*
	 *  Hello bye a
		Cannot bye cannot a
		Hello i hello bye a
		Cannot love robots but love computers
	 */




	if (myfile.is_open()) {
		while (getline(myfile, line)) {

			std::for_each(line.begin(), line.end(), [](char& c) {
				c = ::tolower(c);
			});

			for (auto x : line) {
				if (x == ' ') {
					//rows + 1 to display proper row like row1 and not row0
					wf.addToFolder(word, rows+1);
					word = "";
				}
				else {
					word = word + x;
				}
			}

			wf.addToFolder(word, rows+1);
			word = "";

			++rows;

		}


		myfile.close();
	}
	else cout << "Unable to open file" << endl;


	wf.sortWords();
	wf.displayAllToConsoleAndFile(wf.getlHead());
	wf.printToExternalFile();

	cout << "End of program" << endl;
	return 0;
}

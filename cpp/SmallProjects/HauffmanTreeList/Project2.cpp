
#include "HuffmanListTree.h"

void project2::main(std::vector<std::wstring> &args)
{
	std::vector<std::wstring> r(100);
	std::vector<int> e(100);
	int counter = 0;

	Scanner *inFile = nullptr;

	try
	{
		File tempVar(L"HuffmanCoding_Data1.txt");
		inFile = new Scanner(&tempVar);


		while (inFile->hasNext())
		{
			r[counter] = inFile->next();
			e[counter] = inFile->nextInt();
			counter++;

			inFile++;
		}

	}
	catch (const std::exception &err)
	{
		std::wcout << L"Could not find file" << std::endl;
	}

	std::vector<std::wstring> chrHolder(counter);
	std::vector<int> probHolder(counter);

	//new arrays with the appropriate size required to hold data
	for (int i = 0; i < counter; i++)
	{
		chrHolder[i] = r[i];
		probHolder[i] = e[i];
	}
	//old arrays made null to regain memory
	r.clear();
	e.clear();

	delete inFile;



	//constructs huffmanlisttree		
	HuffmanListTree *ll = new HuffmanListTree();
	ll->ConstructLinkedList(chrHolder, probHolder);
	//stores the linnked list data as a string into output
	std::wstring output = ll->printList();

	std::wcout << output << std::endl;
	//writes the string output to outfile1


	File *outFile1 = new File(L"outFile1.txt");
	try
	{
		if (!outFile1->exists())
		{

			outFile1->createNewFile();
		}
		PrintWriter *pw = new PrintWriter(outFile1);
		pw->println(output);
		delete pw;


	}
	catch (const IOException &e1)
	{
		// TODO Auto-generated catch block
		e1->printStackTrace();
	}

	ll->ConstructBinTree(ll->listHead);
	ll->constructCode(ll->Root, L"");
	ll->preOrderTravTreee(ll->Root);



}


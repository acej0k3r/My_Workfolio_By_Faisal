#include "HuffmanListTree.h"
#include "listBinTreeNode.h"
#include "exceptionhelper.h"
HuffmanListTree::HuffmanListTree()
{
	listHead = new listBinTreeNode(L"Dummy", 0);

}

listBinTreeNode *HuffmanListTree::ConstructLinkedList(std::vector<std::wstring> &chArr, std::vector<int> &prob)
{
	listBinTreeNode *spot;
	for (int i = 0; (i < chArr.size() || i < prob.size()); i++)
	{
		listBinTreeNode *newNode = new listBinTreeNode(chArr[i], prob[i]);

		spot = findSpot(listHead, newNode);
		insertNewNode(spot, newNode);

	}
	return listHead;
}

void HuffmanListTree::ConstructBinTree(listBinTreeNode *listHead)
{



	while (listHead->getNext()->getNext() != nullptr)
	{
		listBinTreeNode *newNode = new listBinTreeNode(L"empty", 0);
		listBinTreeNode *firstNode = listHead->getNext();
		listBinTreeNode *secondNode = firstNode->getNext();

		std::wstring concat = firstNode->getchStr() + secondNode->getchStr();
		int totalProb = firstNode->getProb() + secondNode->getProb();
		newNode->setchStr(concat);
		newNode->setProb(totalProb);
		newNode->setLeftChild(firstNode);
		newNode->setRightChild(secondNode);

		printNode(newNode);
		listBinTreeNode *spot = findSpot(listHead, newNode);
		insertNewNode(spot, newNode);
		printList(listHead);
		listHead = secondNode;

	}
	Root = listHead->getNext();

}

void HuffmanListTree::constructCode(listBinTreeNode *Root, const std::wstring &bitstr)
{
	if (Root == nullptr)
	{
		std::wcout << L"This is an empty tree" << std::endl;
		exit(0);
	}
	else if (isLeaf(Root))
	{
		Root->setCode(bitstr);
		printLeaf(Root);
	}
	else
	{
		constructCode(Root->getLeftChild(), bitstr + L"0");
		constructCode(Root->getRightChild(), bitstr + L"1");
	}
}

bool HuffmanListTree::isLeaf(listBinTreeNode *t)
{
	assert((t->getLeftChild() == nullptr) && (t->getRightChild() == nullptr)) || ((t->getLeftChild() != nullptr) && (t->getRightChild() != nullptr));
	return (t->getLeftChild() == nullptr) && (t->getRightChild() == nullptr);
}

void HuffmanListTree::inOrderTravTreee(listBinTreeNode *focusNode)
{

	if (focusNode != nullptr)
	{
		inOrderTravTreee(focusNode->getLeftChild());
		printNode(focusNode, 0);
		inOrderTravTreee(focusNode->getRightChild());
	}
}

void HuffmanListTree::preOrderTravTreee(listBinTreeNode *focusNode)
{

	if (focusNode != nullptr)
	{


		printNode(focusNode, 0);
		preOrderTravTreee(focusNode->getLeftChild());
		preOrderTravTreee(focusNode->getRightChild());
	}
}

void HuffmanListTree::postOrderTravTreee(listBinTreeNode *focusNode)
{

	if (focusNode != nullptr)
	{



		postOrderTravTreee(focusNode->getLeftChild());
		postOrderTravTreee(focusNode->getRightChild());
		printNode(focusNode, 0);
	}



}

listBinTreeNode *HuffmanListTree::findSpot(listBinTreeNode *listHead, listBinTreeNode *T)
{
	listBinTreeNode *spot = listHead;

	if (isEmpty())
	{
		spot = listHead;
	}
	else if (T->getProb() == listHead->getNext()->getProb() || T->getProb() < listHead->getNext()->getProb())
	{

		// REPLACE SECONDNODE WITH NEWNODE AND LINK SECONDNODE TO NEWNODE
		spot = listHead;

	}
	else if (T->getProb() > listHead->getNext()->getProb())
	{
		//making local reference


		while ((spot->getNext() != nullptr) && (T->getProb() > spot->getNext()->getProb()) && (T->getProb() != spot->getNext()->getProb()))
		{
			spot = spot->getNext();

		}

	}

	return spot;

}

void HuffmanListTree::insertNewNode(listBinTreeNode *spot, listBinTreeNode *newNode)
{
	newNode->setNext(spot->getNext());
	spot->setNext(newNode);


}

bool HuffmanListTree::isEmpty()
{
	if (listHead->getNext() == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void HuffmanListTree::printList(listBinTreeNode *listHead)
{
	listBinTreeNode *spot = listHead;
	std::wstring x = L"";
	while (spot->getNext() != nullptr)
	{
		x += std::wstring(L"(") + L" \"" + spot->getchStr() + L"\"" + L"," + std::to_wstring(spot->getProb()) + L"," + L"\"" + spot->getNext()->getchStr() + L"\"" + L")";
		spot = spot->getNext();
	}
	//we know there is still one next because it stops after .getnext
	x += std::wstring(L"(") + L" \"" + spot->getchStr() + L"\"" + L"," + std::to_wstring(spot->getProb()) + L"," + L"NULL" + L")" + L"(" + L"NULL" + L")";

	n += x;
	//puts it in file 2
	File *outFile2 = new File(L"outFile.txt");
	try
	{
		if (!outFile2->exists())
		{

			outFile2->createNewFile();
		}
		PrintWriter *pw = new PrintWriter(outFile2);
		pw->println(n += L"                     \n");
		delete pw;


	}
	catch (const IOException &e1)
	{
		// TODO Auto-generated catch block
		e1->printStackTrace();
	}




}

std::wstring HuffmanListTree::printList()
{
	listBinTreeNode *spot = listHead;
	std::wstring x = L"";
	while (spot->getNext() != nullptr)
	{
		x += std::wstring(L"(") + L" \"" + spot->getchStr() + L"\"" + L"," + std::to_wstring(spot->getProb()) + L"," + L"\"" + spot->getNext()->getchStr() + L"\"" + L")";
		spot = spot->getNext();
	}
	//we know there is still one next because it stops after .getnext
	x += std::wstring(L"(") + L" \"" + spot->getchStr() + L"\"" + L"," + std::to_wstring(spot->getProb()) + L"," + L"NULL" + L")" + L"(" + L"NULL" + L")";

	return x;
}

void HuffmanListTree::printNode(listBinTreeNode *t)
{
	std::wstring x = L"";

	File *outFile2_0 = new File(L"outFile2.txt");
	if (t->getNext() != nullptr)
	{
		x += L"(" + t->getchStr() + L"," + std::to_wstring(t->getProb()) + L", " + t->getCode() + L", " + t->getNext()->getchStr() + L", " + t->getLeftChild()->getchStr() + L", " + t->getRightChild()->getchStr() + L")";
	}
	else
	{
		x += L"(" + t->getchStr() + L"," + std::to_wstring(t->getProb()) + L", " + t->getCode() + L", " + L"NULL" + L", " + t->getLeftChild()->getchStr() + L", " + t->getRightChild()->getchStr() + L")";
	}

	r += x;
	try
	{
		if (!outFile2_0->exists())
		{

			outFile2_0->createNewFile();
		}
		PrintWriter *pw = new PrintWriter(outFile2_0);
		pw->println(r);
		delete pw;

	}
	catch (const IOException &e1)
	{
		// TODO Auto-generated catch block
		e1->printStackTrace();
	}

}

void HuffmanListTree::printNode(listBinTreeNode *t, int lol)
{
	std::wstring x = L"";
	x += L"(" + t->getchStr() + L"," + std::to_wstring(t->getProb()) + L", " + t->getCode() + L")";

	rp += x;
	File *outFile2_0 = new File(L"outFile4.txt");

	try
	{
		if (!outFile2_0->exists())
		{

			outFile2_0->createNewFile();
		}
		PrintWriter *pw = new PrintWriter(outFile2_0);
		pw->println(rp);
		delete pw;

	}
	catch (const IOException &e1)
	{
		// TODO Auto-generated catch block
		e1->printStackTrace();
	}

}

void HuffmanListTree::printLeaf(listBinTreeNode *Root)
{
	std::wstring x = L"(" + Root->getchStr() + L"," + Root->getCode() + L")";
	File *outFile2_0 = new File(L"outFile3.txt");
	rpr += x;
	try
	{
		if (!outFile2_0->exists())
		{

			outFile2_0->createNewFile();
		}
		PrintWriter *pw = new PrintWriter(outFile2_0);
		pw->println(rpr);
		delete pw;

	}
	catch (const IOException &e1)
	{
		// TODO Auto-generated catch block
		e1->printStackTrace();
	}
}






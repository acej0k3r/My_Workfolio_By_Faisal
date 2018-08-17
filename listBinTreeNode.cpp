
#include "listBinTreeNode.h"

void listBinTreeNode::setProb(int x)
{
	this->prob = x;
}

int listBinTreeNode::getProb()
{
	return this->prob;

}

void listBinTreeNode::setchStr(const std::wstring &x)
{
	this->chStr = x;
}

std::wstring listBinTreeNode::getchStr()
{
	return this->chStr;
}

void listBinTreeNode::setCode(const std::wstring &x)
{
	this->code = x;
}

std::wstring listBinTreeNode::getCode()
{
	return this->code;
}

void listBinTreeNode::setNext(listBinTreeNode *T)
{
	this->next = T;
}

listBinTreeNode *listBinTreeNode::getNext()
{


	return this->next;
}

void listBinTreeNode::setLeftChild(listBinTreeNode *T)
{
	this->leftChild = T;
}

listBinTreeNode *listBinTreeNode::getLeftChild()
{

	return this->leftChild;
}

void listBinTreeNode::setRightChild(listBinTreeNode *T)
{
	this->rightChild = T;


}

listBinTreeNode *listBinTreeNode::getRightChild()
{

	return this->rightChild;
}

listBinTreeNode::listBinTreeNode(const std::wstring &word, int key)
{

	this->prob = key;
	this->chStr = word;
}

std::wstring listBinTreeNode::toString()
{
	return chStr + L" has a key " + std::to_wstring(prob);

}

void listBinTreeNode::printNode(listBinTreeNode *T)
{
	std::wcout << L"T's chrStr is: " << T->chStr << L"T's prob is: " << T->prob << L"T's code is:" << T->code << L"T's next chStr is \n: " << T->next->chStr << L"T's left's chStr is: " << T->leftChild->chStr << L"T's right's chStr is: " << T->rightChild->chStr << std::endl;
}


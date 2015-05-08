// Programming Project #2
// Author: Stephanie Gilchrist
// Instructor: Dr. Reza Sanati
// Class: CS 2420-601 
// Semester: UVU Spring 2015
// Last Edited: 01/30/2015
// --------------------------------------------------------------------
// I declare that the following source code was written solely by me.
// I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
// --------------------------------------------------------------------
// Program Description: This program implements a single and double 
// linked list. First a user specified .txt file is opened. The integer 
// values from the file are read in and added to a single link list. 
// The single link list is traversed and the data in the list is added 
// to a double link list in ascending order. Both the data from the 
// single link list and the double link list are print when a print 
// function is sent as a parameter to the list classes traverse functions. 
// --------------------------------------------------------------------

#include "SingleLinkList.h"

SingleLinkList::SingleLinkList()
{
	count = 0;
	head = nullptr;
}

SingleLinkList::~SingleLinkList()
{
	Node* next = this->getHead();
	while (next != nullptr)
	{
		Node* deleter = next;
		next = next->link;
		delete deleter;
	}
}

int SingleLinkList::getCount()
{
	return count;
}

Node* SingleLinkList::getHead()
{
	return head;
}


void SingleLinkList::traverse()
{
	Node* temp = head;
	while (temp->link != nullptr)
	{
		temp = temp->link;
	}
}

Node* SingleLinkList::traverser()
{
	Node* temp = head;
	while (temp->link != nullptr)
	{
		return temp;
		temp = temp->link;
	}
}

void SingleLinkList::traversePrint(void(visit(Node*)))
{
	Node* temp = head;
	while (temp->link != nullptr)
	{
		visit(temp);
		temp = temp->link;
	}
}

void SingleLinkList::insert(int num)
{
	Node* addNode = new Node;
	addNode->data = num;
	addNode->link = nullptr;

	if (head == nullptr)
		head = addNode;
	else
	{
		Node* temp = head;
		while (temp->link != nullptr)
			temp = temp->link;	
		temp->link = addNode;
	}
	count++;
}


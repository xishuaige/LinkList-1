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

#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList()
{
	count = 0;
	current = nullptr;
}

DoubleLinkList::~DoubleLinkList()
{
	Node* next = this->getCurrent();
	while (next != nullptr)
	{
		Node* deleter = next;
		delete deleter->previous;
		delete deleter->previous->link;
		next = next->link;
		delete deleter;
	}
}

int DoubleLinkList::getCount()
{
	return count;
}

Node* DoubleLinkList::getCurrent()
{
	return current;
}

void DoubleLinkList::traverse()
{
	Node* temp = current;
	while (temp->link != nullptr)
	{
		temp = temp->link;
	}
}

void DoubleLinkList::traversePrint(void(visit(Node*)))
{
	int traverseCount = 0;
	Node* temp = nullptr;
	temp = current;

	while (traverseCount < count)
	{
		visit(temp);
		temp = temp->link;
		traverseCount++;
	}
}

void DoubleLinkList::insert(int num)
{
	// created a new node to store the data in
	Node* add = new Node;
	add->data = num;

	// if the double link list is empty
	if (count == 0)
	{
		current = add;
	}
	// if the double link list has only one Node
	else if (count == 1)
	{
		if (add->data < current->data)
		{
			current->previous = add;
			add->link = current;
			current->link = add;
			add->previous = current;
		}
		else
		{
			current->link = add;
			add->previous = current;
			current->previous = add;
			add->link = current;
		}
	}
	// if double link list has more than one Node
	else
	{
		// if add data is larger than current data
		if (add->data > current->data)
		{
			while (current->data > add->data || add->data > current->link->data)
			{
				current = current->link;
			}

			while (current->data < add->data && add->data < current->link->data)
			{
				add->link = current->link;
				current->link->previous = add;
				current->link = add;
				add->previous = current;
			}
		}
		else
		{
			// if add data is smaller than current data
			if (current->data > add->data)
			{
				while (add->data < current->data && add->data < current->previous->data)
				{
					current = current->previous;
					// if add data is the smallest element in the list
					if (current->previous->data > current->data)
					{
						add->previous = current->previous;
						current->previous->link = add;
						add->link = current;
						current->previous = add;
						break;
					}
				}
				while ((add->data < current->data && add->data > current->previous->data))
				{
					add->previous = current->previous;
					current->previous->link = add;
					add->link = current;
					current->previous = add;
				}
			}
		}
		while (current->data > current->previous->data)
		{
			current = current->previous;
		}
	}
	count++;
}


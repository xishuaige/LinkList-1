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

#pragma once
#include "Node.h"

class SingleLinkList
{
public:
	// The single link list default constructor 
	// Purpose: set the data members to default values
	// Parameters: none
	// Returns: none
	// Preconditions: a single link list is instantiated
	// Postcondtions: a single link list is created
	SingleLinkList();

	// The single link list destructor 
	// Purpose: return dynamically allocated memory to heap when list is no longer needed 
	// Parameters: none
	// Returns: none
	// Preconditions: memory for a list must have been dynamically allocated
	// Postconditions: after use dynamically memory is properly returned to the heap
	~SingleLinkList();

	// The get count funtion
	// Purpose: get the count of nodes in the single link list
	// Parameters: none
	// Returns: the integer value of the number of nodes in the list
	// Preconditions: a list must be created
	// Postcondtions: the correct number of elements in the list is returned as an integer value
	int getCount();

	// The get head funtion
	// Purpose: get the head node pointed to in the list
	// Parameters: none
	// Returns: the node pointer of the head in the list
	// Preconditions: there must be at least one node in the list
	// Postcondtions: the pointer to the head node is returned
	Node* getHead();

	// The traverse function 
	// Purpose: visits each node in the list
	// Parameters: none
	// Returns: none
	// Preconditions: a list must be created
	// Postcondtions: each node in the list is visited
	void traverse();

	// The traverser function 
	// Purpose: visits each node in the list
	// Parameters: none
	// Returns: a node pointer
	// Preconditions: a list must be created
	// Postcondtions: the node pointer visisted is returned
	Node* traverser();

	// The traverse print function
	// Purpose: visits each node in the list and sends its data to the visiting function
	// Parameters: a visiting fuctions with a node parameter
	// Returns: none
	// Preconditons: the list must contain at least one node
	// Postcondtions: the data of each node in the list is sent to the visiting functions
	void traversePrint(void(visit(Node*)));

	// The insert function
	// Purpose: inserts a new node to the end of the list
	// Parameters: one integer to be added to as the data to a node
	// Returns: none
	// Preconditions: a list must be created
	// Postcondtions: a new node with the passed data is inserted to the end of the list
	void insert(int num);

private:
	// member data
	int count;
	Node* head;
};



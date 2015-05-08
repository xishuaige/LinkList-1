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

class DoubleLinkList
{
public:
	// The double link list default constructor 
	// Purpose: set the data members to default values
	// Parameters: none
	// Returns: none
	// Preconditions: a double link list is instantiated
	// Postcondtions: a double link list is created
	DoubleLinkList();

	// The double link list destructor 
	// Purpose: return dynamically allocated memory to heap when list is no longer needed 
	// Parameters: none
	// Returns: none
	// Preconditions: memory for a list must have been dynamically allocated
	// Postconditions: after use dynamically memory is properly returned to the heap
	~DoubleLinkList();

	// The get count funtion
	// Purpose: get the count of nodes in the double link list
	// Parameters: none
	// Returns: the integer value of the number of nodes in the list
	// Preconditions: a list must be created
	// Postcondtions: the correct number of elements in the list is returned as an integer value
	int getCount();

	// The get current funtion
	// Purpose: get the current node pointed to in the list
	// Parameters: none
	// Returns: the node pointer of the current node pointed to in the list
	// Preconditions: there must be at least one node in the list
	// Postcondtions: the pointer to the current node is returned
	Node* getCurrent();

	// The traverse function 
	// Purpose: visits each node in the list
	// Parameters: none
	// Returns: none
	// Preconditions: a list must be created
	// Postcondtions: each node in the list is visited
	void traverse();

	// The traverse print function
	// Purpose: visits each node in the list and sends its data to the visiting function
	// Parameters: a visiting fuctions with a node parameter
	// Returns: none
	// Preconditons: the list must contain at least one node
	// Postcondtions: the data of each node in the list is sent to the visiting functions
	void traversePrint(void(visit(Node*)));

	// The insert function
	// Purpose: inserts a new node in sequential ascending order
	// Parameters: one integer to be added to as the data to a node
	// Returns: none
	// Preconditions: a list must be created
	// Postcondtions: a new node with the passed data is inserted in the correct order in the list
	void insert(int num);

private:
	// data members
	int count;
	Node* current;
};



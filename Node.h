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

struct Node
{
	// declare data types
	int data;
	Node* link;
	Node* previous;

	// The node default constructor 
	// Purpose: set the node data to default values
	// Parameters: none
	// Returns: none
	// Preconditions: new node must be created
	// Postconditions: newly created codes have default settings
	Node::Node()
	{
		data = 0;
		link = nullptr;
		previous = nullptr;
	}

	// The node destructor 
	// Purpose: return dynamically allocated memory to heap after Node is no longer being used
	// Parameters: none
	// Returns: none
	// Preconditions: memory for a node must have been dynamically allocated
	// Postconditions: after use dynamically memory is properly returned to the heap
	Node::~Node()
	{
		if (link != nullptr)
		{
			delete link;
			link = nullptr;
		}
		if (previous != nullptr)
		{
			delete previous;
			previous = nullptr;
		}
	}
};
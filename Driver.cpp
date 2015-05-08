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
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include "SingleLinkList.h";
#include "DoubleLinkList.h"
#include "Node.h"

using namespace std;

// The print fuction
// Purpose: to print the data located in a node
// Parameters: a node pointer
// Returns: none
// Preconditions: the node passed in must contaion data
// Postconditions: the data in the node is displayed on the console
void print(Node*);

// The single to double function
// Purpose: traverse a single link list and copy data to a double link list
// Parameters: a pointer to a single link list and a pointer to a double link list
// Returns: none
// Preconditions: the single link list must contain nodes with data
// Postconditions: a double link list contaion the single link list data is created
void singleToDouble(SingleLinkList*, DoubleLinkList*);

int main()
{
	// print name, class, section number and program name/number
	cout << "Stephanie Gilchrist\nCS 2420 Section 601\nProgram 2 - Linked Lists\n";

	// declare variables
	Node* addNode = new Node;
	int num;

	// instantiate SingleLinkList and DoubleLinkList
	SingleLinkList* singleList = new SingleLinkList;
	DoubleLinkList* doubleList = new DoubleLinkList;

	// declare variables
	ifstream inputFile;
	string fileName;
	do
	{
		// prompt user for file name (file containing integers) to be read include option to exit
		cout << "\nPlease enter the .txt file you would like to open (or press 'e' to exit):\n";
		cin >> fileName;
		if (fileName == "e" || fileName == "E")
			return 0;

		// open the file
		inputFile.open(fileName.c_str());
		// error check—if file cannot be opened, handle the error
		if (inputFile.fail())
			cout << "\nCould not open file\n";
		else
			cout << "\nFile opened\n";

	} while (inputFile.fail());

	while (!inputFile.eof())
	{
		// check for eof
		if (inputFile.eof())
			cout << "End of File\n\n";
		// read in one integer from the file
		inputFile >> num;
		// call the SingleLinkList object’s insert method
		// add the data from the file to a new node at the end of the single linked list
		singleList->insert(num);
	}

	// close the file
	inputFile.close();

	// traverse the single linked list (use SLL traverse function)
	singleList->traverse();

	// call single to double function to transfer data in the single link list to a double link list
	singleToDouble(singleList, doubleList);

	// Pass the print function as a parameter to the SLL traverse function and print each integer in the SLL in 
	// the order they were read in from the file
	cout << "\n" << "Single List\n";
	singleList->traversePrint(print);

	// Pass the print function as a parameter to the DLL traverse function and print each integer in the DLL in 
	// ascending order
	cout << "\n" << "Double List\n";
	doubleList->traversePrint(print);

	cout << "\nEnd of File\n";

	system("pause");
	return 0;
}


void print(Node* temp)
{
	cout << temp->data << endl;
}

void singleToDouble(SingleLinkList* singleList, DoubleLinkList* doubleList)
{
	int data = 0;
	Node* traverseNode = singleList->traverser();
	for (int i = 0; i < (singleList->getCount() - 1); i++)
	{
		data = traverseNode->data;
		doubleList->insert(data);
		traverseNode = traverseNode->link;
	}
}
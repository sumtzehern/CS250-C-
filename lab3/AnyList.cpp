#include "AnyList.h"

using namespace std;

void AnyList::insertFront(int newData)
{	
	first = new Node(newData, first);
	++count;
}

void AnyList::print() const
{
	if (first == nullptr) 
	// Check if the list is empty.
	// You can also use: if (count == 0)
		cerr << "List is empty.";  
		// Use cerr, instead of cout. Why?
	else
	{
        	Node *current = first;   
		// Create a pointer to traverse the list.		
		// This pointer will point to the first node in the list.

		while (current != nullptr)	
		// While the current pointer is NOT a nullptr,
		// that is, while the current pointer has not reached  
		// the end of the list.
		{	                        
			// Output the data. 
			cout << current->getData() << " "; 
			// Move the pointer current forward.
			current = current->getNext();                         
		}		
	}
}

void AnyList::rotateNodesLeft(int num)
{
	//if num is 0 then no rotate need
	if (num == 0)
	{
		return;
	}

	//We find the newFirst
	Node* newFirst = first;
	for(int i = 0; i < num; i++)
	{
		newFirst = newFirst->getNext();
	}

	//Traverse untill last node
	Node* newLast = first;
	while (newLast->getNext() != nullptr)
	{
		newLast = newLast->getNext();
	}

	newLast->setNext(first);// connect last to the old first

	//Set newFirst prev to nullptr
	Node* prev = first;
	while (prev->getNext() != newFirst)
	{
		prev = prev->getNext();
	}
	prev->setNext(nullptr);


	//Update first to newfirst
	first = newFirst;

	//set to null
	newFirst = nullptr;
	newLast = nullptr;
	prev = nullptr;
}

// This function does not delete the 
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{ 	
	Node  *temp = first; 	
	// Pointer to delete the node, which	
	// starts by pointing to the first node.
	
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	// Update the count outside the loop.
   	count = 0;
}

AnyList::~AnyList()
{
	if (first != nullptr)
		 clearList();
}
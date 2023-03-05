#include "DoublyList.h"

using namespace std;

void DoublyList::insertFront(int newData)
{
    if (first == nullptr)
    {
        first = new DLLNode(newData, nullptr, nullptr);
        last = first;	
        // Common error: Forgetting to reset pointer last.
    }
    else
    {
        first = new DLLNode(newData, nullptr, first);
        first->getNext()->setPrev(first);
        // Common error: Forgetting to connect pointer 
        // prev of what is now the second node to the 
        // new first node.
    }

    ++count;
}

void DoublyList::printForward() const
{
    DLLNode* current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
}

void DoublyList::printReverse() const
{
    DLLNode* current = last;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
}

void DoublyList::rotateNodesRight(int num)
{   DLLNode* newlast = last;
    
    for (int i = 0; i < num; i++)
        newlast = newlast->getPrev();
        
    DLLNode* newFirst = newlast->getNext();
    newFirst->setPrev(nullptr); 
    newlast->setNext(nullptr); 
    
    last->setNext(first); 
    first->setPrev(last);
        
    first = newFirst;
    last = newlast;
}

void DoublyList::clearList()
{ 	
    DLLNode* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;		
    // Don't forget to reset pointer last to nullptr.
    count = 0;
}

DoublyList::~DoublyList()
{
    if (first != nullptr)
        clearList();
}
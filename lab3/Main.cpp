/*
	Sum, Wesley

	March 4, 2023
	CS A250

	Lab 1
*/

#include "AnyList.h"
#include "DoublyList.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> data = {
	{25, 76, 35, 67, 15, 98},
	{1, 2, 3, 4, 5, 6, 7, 8, 9},
	{10, 20},
	{34, 56, 78, 12, 89, 34, 76, 28, 54, 22, 41},
	{123, 873, 619},

	};

	vector<int> nodesToRotate = { 2, 3, 1, 9, 2 };

	/* Uncomment section below when testing AnyList::rotateNodesLeft() */
	{
		AnyList singlyList;
		int vectorSize = static_cast<int>(data.size());
		for (int i = 0; i < vectorSize; ++i)
		{
			int innerSize = static_cast<int>(data[i].size());
			for (int j = innerSize - 1; j >= 0; --j)
				singlyList.insertFront(data[i].at(j));
			cout << "Rotate left: " << nodesToRotate[i] << "\n";	
			cout << "       List is: ";
			singlyList.print();
			cout << "\n";						
			singlyList.rotateNodesLeft(nodesToRotate[i]);
			cout << "After rotating: "; 
			singlyList.print();
			cout << "\n\n";
			singlyList.clearList();
		}
	}

	cout << "----------------------\n";

	/* uncomment section below when testing doublylist::rotatenodesright() */
	{
		DoublyList doublylist;
		int vectorsize = static_cast<int>(data.size());
		for (int i = 0; i < vectorsize; ++i)
		{
			int innersize = static_cast<int>(data[i].size());
			for (int j = innersize - 1; j >= 0; --j)
				doublylist.insertFront(data[i].at(j));
			cout << "rotate right: " << nodesToRotate[i] << "\n";
			cout << "       list is: ";
			doublylist.printForward();
			cout << "\n";
			doublylist.rotateNodesRight(nodesToRotate[i]);
			cout << "after rotating:";
			cout << "\n  print forward: ";
			doublylist.printForward();
			cout << "\nprint backwards: ";
			doublylist.printReverse();
			cout << "\n\n";
			doublylist.clearList();
		}
	}

	cout << "\n";
	//system("Pause");
	return 0;
}



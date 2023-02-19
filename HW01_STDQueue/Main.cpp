#include "queue.h"
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

void TestFunction()
{
	// Define queue of ints
	queue<int> myIntQueue;
	// Check the print with empty queue
	myIntQueue.Print();
	// Push some elements (out of order)
	myIntQueue.Push(5);
	std::cout << "	just pushed +++++" << std::endl;
	myIntQueue.Push(3);
	std::cout << "	just pushed +++++" << std::endl;
	myIntQueue.Push(12);
	std::cout << "	just pushed +++++" << std::endl;
	// Check with print 
	myIntQueue.Print();
	// Pop and return an element
	std::cout << "	" << myIntQueue.Pop() << "	just popped -----" << std::endl;
	myIntQueue.Print();
	// Push a few more elements
	myIntQueue.Push(6);
	std::cout << "	just pushed +++++" << std::endl;
	myIntQueue.Push(9);
	std::cout << "	just pushed +++++" << std::endl;
	myIntQueue.Push(12);
	std::cout << "	just pushed +++++" << std::endl;
	myIntQueue.Print();
	std::cout << "Number of elements in queue: " << myIntQueue.GetSize() << std::endl;
	// Copy Constuctor
	queue<int> copyConstMyIntQueue(myIntQueue);
	std::cout << "Copy ...." << std::endl;
	copyConstMyIntQueue.Print();
	std::cout << "Number of elements in queue: " << myIntQueue.GetSize() << std::endl;
	// Pop some elements in copy
	std::cout << "Popping in copy ...." << std::endl;
	std::cout << "	" << copyConstMyIntQueue.Pop() << "	just popped -----" << std::endl;
	std::cout << "	" << copyConstMyIntQueue.Pop() << "	just popped -----" << std::endl;
	std::cout << "	" << copyConstMyIntQueue.Pop() << "	just popped -----" << std::endl;
	std::cout << "Printing from copy queue" << std::endl;
	copyConstMyIntQueue.Print();
	// Copying back over to main int queue via assignment
	std::cout << "Copying back to main queue via assignment" << std::endl;
	myIntQueue = copyConstMyIntQueue;
	std::cout << "Printing from main queue" << std::endl;
	myIntQueue.Print();
	// Loop to empty queue

}

int main(void)
{
	TestFunction();

	if (_CrtDumpMemoryLeaks() == 1)
	{
		std::cout << "\nThere are still memory leaks!" << std::endl;
	}
	else
	{
		std::cout << "\nThere are no memory leaks!" << std::endl;
	}
	std::cout << "Press Enter to exit ... " << std::endl;
	getchar();
}
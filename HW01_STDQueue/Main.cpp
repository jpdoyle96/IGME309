#include "queue.h"
#include "Alberto.h"
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
	while (myIntQueue.GetSize() > 0)
	{
		std::cout << "	" << myIntQueue.Pop() << "	just popped -----" << std::endl;
	}
	std::cout << "Checking if empty ... " << std::endl;
	myIntQueue.Print();

	std::cout << "\n\n" << "Alberto Class Testing" << std::endl;
	// Alberto class testing
	queue<AlbertoClass> myAlbertoQueue;
	// Push some elements
	myAlbertoQueue.Push(AlbertoClass(4));
	std::cout << "	just pushed +++++" << std::endl;
	myAlbertoQueue.Push(AlbertoClass(9));
	std::cout << "	just pushed +++++" << std::endl;
	myAlbertoQueue.Push(AlbertoClass(15));
	std::cout << "	just pushed +++++" << std::endl;
	myAlbertoQueue.Push(AlbertoClass(3));
	std::cout << "	just pushed +++++" << std::endl;
	myAlbertoQueue.Print();
	// Popping objects
	std::cout << "	" << myAlbertoQueue.Pop() << "	just popped -----" << std::endl;
	std::cout << "	" << myAlbertoQueue.Pop() << "	just popped -----" << std::endl;
	// Printing out results
	myAlbertoQueue.Print();
	// Looping to empty queue
	std::cout << "Looping to empty queue" << std::endl;
	while (!myAlbertoQueue.IsEmpty()) 
	{
		std::cout << "	" << myAlbertoQueue.Pop() << "	just popped -----" << std::endl;
	}
	std::cout << "Checking if empty" << std::endl;
	myAlbertoQueue.Print();

	// Note: Copy constructors and assignment already tested with the above 
}

int main(void)
{
	// Seperate function encases tests to test for memory leaks by scoping out the queues
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
	getchar();	// Prevents windows from auto closing
}
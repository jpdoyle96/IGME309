/*----------------------------------------------
Programmer: Jack Doyle (jpd2690@rit.edu)
Date: 1/29/2023
----------------------------------------------*/


#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <iostream>

#define INIT_SIZE 10 // Initial size of the queue

template <class T> class queue 
{
	T* data;		// Array of queue elements
	int lastIndex;	// points to last element in the queue
	int capacity;	// total capacity of array

public:
	// Constuctor
	queue() : data(new T[INIT_SIZE]) 
	{
		lastIndex = -1; // Indicates an empty queue
		capacity = INIT_SIZE;
	}

	// Copy Constructor
	queue(const queue& other) : data(new T[other.capacity])
	{
		lastIndex = other.lastIndex;
		capacity = other.capacity;

		// copies elements
		for (int i = 0; i < capacity; i++)
		{
			data[i] = other.data[i];
		}
	}

	// Copy Assignment
	queue& operator= (const queue& other)
	{
		if (this != &other)
		{
			if (data != nullptr)
			{
				delete[] data;
				data = nullptr;
			}

			lastIndex = other.lastIndex;
			capacity = other.capacity;
			data = new T[capacity];
			// copies elements
			for (int i = 0; i < capacity; i++)
			{
				data[i] = other.data[i];
			}
			return *this;
		}
		else
		{
			return *this;
		}
	}

	// Destructor
	~queue()
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		lastIndex = -1;
	}

	// ----- Methods -----

	// Push method
	void Push(T input)
	{
		// only used if no elements in queue
		if (lastIndex == -1)
		{
			lastIndex++;
			data[lastIndex] = input;
		}
		else 
		{
			// Sorts and inserts the new element
			// Note: Sort will call the expand method if needed
			Sort(input);
		}
	}

	// Pop method
	T Pop()
	{
		if (IsEmpty())
		{
			return NULL;	// Returns a NULL if the queue is empty
		}
		T popped = data[0];
		ShiftLeft();
		return popped;
	}

	// Print method
	void Print()
	{
		std::cout << "Begining of queue......." << std::endl;
		for (int i = 0; i <= lastIndex; i++)
		{
			std::cout << data[i] << std::endl;
		}
		std::cout << "End of queue............" << std::endl;
	}

	// GetSize method
	int GetSize()
	{
		return lastIndex + 1;
	}

	// IsEmpty method
	bool IsEmpty()
	{
		if (lastIndex == -1) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	// ----- Helper methods -----

	// Sort helper method
	void Sort(T element)
	{
		// Checking capacity
		if (lastIndex + 1 >= capacity)
		{
			Expand();
		}
		// Checking if greater than last element for trivial 
		//		insertion at end of array
		// Note: Using ! instead of reversing operands to allow < to remain 
		//		the minimum comparision precondition while acting as 
		//		(data[lastIndex] <= element) in this case
		if (!(element < data[lastIndex]))
		{
			lastIndex++;
			data[lastIndex] = element;
		}
		// Parsing through array for insertion position
		else 
		{
			int placementIndex = -1;
			for (int i = 0; i <= lastIndex; i++)
			{
				if (element < data[i]) 
				{
					placementIndex = i;
					break;
				}
			}
			ShiftRight(placementIndex);	// This method handles incrementing lastIndex
			data[placementIndex] = element;
		}
	}

	// Shift right helper method
	void ShiftRight(int startingIndex)
	{
		// Notes: Capacitry must be checked and expanded before calling this method
		lastIndex++;
		// Shift data up 1 index
		for (int i = lastIndex; i > startingIndex; i--)
		{
			data[i] = data[i - 1];
		}
	}

	// Shift left helper method
	void ShiftLeft()
	{
		// Shift data down 1 index
		for (int i = 0; i < lastIndex; i++)
		{
			data[i] = data[i + 1];
		}
		lastIndex--;	// Move the last index down
	}

	// Expand helper method
	void Expand()
	{
		int oldCapacity = capacity;	// Temp capacity
		capacity *= 2;
		T* oldData = data;	// Temp dynamic array
		for (int i = 0; i < oldCapacity; i++)	// Copies from old array
		{
			data[i] = oldData[i];
		}
		delete[] oldData;	// Delete temp dynamic array
		oldData = nullptr;	// Nulls array reference
	}
};

#endif // __QUEUE_H_
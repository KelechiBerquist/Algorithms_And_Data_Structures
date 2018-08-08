#include <system_error>
#include <iostream>
#include <stdlib.h>  
#include <stdexcept> 

//Class definition using templates
template<typename T>
class Stack
{
	private:
		int currentSize, lastFilledIndx;
		void *ThisStack;

	public:
		stack();
		T pop();
		void push(T);
};


//Class constructor using template
template<typename T>
Stack<T>::Stack (void)
{
	currentSize             =  1000, 
	lastFilledIndx          =  0,
	ThisStack               =  malloc(currentSize*sizeof(T));
}


//Setting pop methods inside class using templates
template<typename T>
T Stack<T>::pop ()
{
	if (lastFilledIndx >= 0 )
	{
		return ThisStack[lastFilledIndx--];
	}
	else
	{
		throw out_of_range("Stack::pop() error. This Stack is empty");
	}
	
}

//Setting push methods inside class using templates
template<typename T>
void Stack<T>::push (const T& newElement)
{
	if (lastFilledIndx < currentSize)
	{
		ThisStack[++lastFilledIndx] = newElement;
	}
	else
	{
		T NewStack = malloc(2*currentSize*sizeof(T));

		for (int i = 0; i < currentSize; i++)
		{
			NewStack[i] = ThisStack[i];
		}

		NewStack[++lastFilledIndx]   =  newElement;
		currentSize                  =  2*currentSize;

		free (ThisStack);
		ThisStack = NewStack;
		
	}
}







 // g++ -std=c++11 -o Bla /mnt/c/Users/Vanessa/Documents/Personal\ Development/PersonalStudy/Algorithms_And_DataStructures/PractiseCoding.cpp


#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DL_List
{
	private:
		struct eachValue
		{
			T  thisValue;
			eachValue * forePointer;
			eachValue * backPointer;
		};
		eachValue * rootPointer;
		eachValue * basePointer;
		eachValue * searchHelpFunc (eachValue * thisPointer, T deleteValue);
		void printHelpFunc (eachValue * thisPointer);

	public:
		int listSize;
		DL_List();
		T pop();
		void push (T newValue);
		std::string search (T searchValue);
		void del (T deleteValue);
		void print ();
		int size ();
		T peek(T peekValue);
		eachValue * begin();
		eachValue * end();

	

};
// 
// 
// 
template <typename T>
DL_List<T>::DL_List()
{
	listSize    = 0;
	DL_List<T>::rootPointer = NULL;
	DL_List<T>::basePointer = NULL;
}
// 
// 
// 
template <typename T>
typename DL_List<T>::eachValue * DL_List<T>::begin ()
{
	return rootPointer;
}
// 
// 
// 
template <typename T>
typename DL_List<T>::eachValue * DL_List<T>::end ()
{
	return basePointer;
}
// 
// 
// 
template <typename T>
void DL_List<T>::push (T newValue)
{
	listSize++;
	DL_List<T>::eachValue * newPointer     =  (DL_List<T>::eachValue *) std::malloc(sizeof(DL_List<T>::eachValue));
	newPointer->thisValue                   =  newValue;

	if (rootPointer == NULL)
	{
		rootPointer = newPointer;
	}
	else if (basePointer == NULL)
	{
		basePointer                =  newPointer;
		rootPointer->forePointer   =  newPointer;
		basePointer->backPointer   =  rootPointer;
	}
	else
	{
		basePointer->forePointer   =  newPointer;
		newPointer->backPointer    =  basePointer;
		basePointer                =  newPointer;
	}
}
// 
// 
// 
template <typename T>
T DL_List<T>::pop ()
{
	listSize--;
	DL_List<T>::eachValue * tempPointer  =  rootPointer;
	rootPointer              =  tempPointer->forePointer;
	T thisValue             =  tempPointer->thisValue;

	std::free(tempPointer);
	return thisValue;
}
// 
// 
// 
template <typename T>
int DL_List<T>::size ()
{
	return listSize;
}
// 
// 
// 
// This searches the pointer itself for the values. Unlike singly linked list that searches a parent for the child's value
template <typename T> 
typename DL_List<T>::eachValue * DL_List<T>::searchHelpFunc (DL_List<T>::eachValue * thisPointer, T searchValue)
{
	if (thisPointer != NULL)
	{
		if (thisPointer->thisValue == searchValue)
		{
			return thisPointer;
		}
		else
		{
			DL_List<T>::searchHelpFunc (thisPointer->forePointer, searchValue);
		}
	}

	else
	{
		return NULL;
	}	
}
// 
// 
// 
template <typename T>
void DL_List<T>::del (T deleteValue)
{
	DL_List<T>::eachValue * tempPointer  =  DL_List<T>::searchHelpFunc (rootPointer, deleteValue);

	if (tempPointer != NULL)
	{
		DL_List<T>::eachValue * forePointed    =  tempPointer->forePointer;
		DL_List<T>::eachValue * backPointed    =  tempPointer->backPointer;
		backPointed->forePointer                =  forePointed;
		if (forePointed != NULL)
		{
			forePointed->backPointer   =  backPointed;
		}

		std::free(tempPointer);
	}	
}
// 
// 
// 
template <typename T>
std::string DL_List<T>::search (T searchValue)
{
	DL_List<T>::eachValue * tempPointer  =  DL_List<T>::searchHelpFunc (rootPointer, searchValue);

	if (tempPointer != NULL)
	{
		return "value found in list";
	}
	return "value not found in list";
}
// 
// 
// 
template <typename T>
T DL_List<T>::peek (T peekValue)
{
	DL_List<T>::eachValue * tempPointer  =  DL_List<T>::searchHelpFunc (rootPointer, peekValue);

	if (tempPointer != NULL)
	{
		return tempPointer->forePointer->thisValue;
	}
	return -1;
}
// 
// 
// 
template <typename T>
void DL_List<T>::print ()
{
	DL_List<T>::printHelpFunc (rootPointer);
}
// 
// 
// 
template <typename T>
void DL_List<T>::printHelpFunc (DL_List<T>::eachValue * thisPointer)
{
	if (thisPointer != NULL)
	{
		std::cout<<thisPointer->thisValue <<"   ";
		DL_List<T>::printHelpFunc (thisPointer->forePointer);
	}
}
// 
// 
// 

#endif
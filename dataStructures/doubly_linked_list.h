#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T1>
class DL_List
{
	private:
		struct eachValue
		{
			T1  thisValue;
			eachValue * forePointer;
			eachValue * backPointer;
		};
		eachValue * rootPointer;
		eachValue * basePointer;
		eachValue * searchHelpFunc (eachValue * thisPointer, T1 deleteValue);
		void printHelpFunc (eachValue * thisPointer);

	public:
		int listSize;
		DL_List();
		T1 pop();
		void push (T1 newValue);
		std::string search (T1 searchValue);
		void del (T1 deleteValue);
		void print ();
		int size ();
		T1 peek(T1 peekValue);
		eachValue * begin();
		eachValue * end();

	

};
// 
// 
// 
template <typename T1>
DL_List<T1>::DL_List()
{
	listSize    = 0;
	DL_List<T1>::rootPointer = NULL;
	DL_List<T1>::basePointer = NULL;
}
// 
// 
// 
template <typename T1>
typename DL_List<T1>::eachValue * DL_List<T1>::begin ()
{
	return rootPointer;
}
// 
// 
// 
template <typename T1>
typename DL_List<T1>::eachValue * DL_List<T1>::end ()
{
	return basePointer;
}
// 
// 
// 
template <typename T1>
void DL_List<T1>::push (T1 newValue)
{
	listSize++;
	DL_List<T1>::eachValue * newPointer     =  (DL_List<T1>::eachValue *) std::malloc(sizeof(DL_List<T1>::eachValue));
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
		// std::cout<<"Before: "  <<basePointer->thisValue <<"  "  <<newPointer->thisValue <<"  "    <<"\n";
		// std::cout<<"Before: " <<tempPointer->thisValue <<"  "  <<basePointer->thisValue <<"  "  <<"\n";
		// DL_List <T1>::eachValue * tempPointer  =  basePointer;
		basePointer->forePointer               =  newPointer;
		newPointer->backPointer                =  basePointer;
		basePointer                            =  newPointer;
		
		// DL_List <T1>::eachValue * tempPointer  =  basePointer;
		// basePointer                            =  newPointer;
		// tempPointer->forePointer               =  newPointer;
		// basePointer->backPointer               =  tempPointer;
		
		// std::cout<<"After: "  <<newPointer->backPointer->thisValue <<"  " <<newPointer->thisValue <<"  "  <<basePointer->thisValue <<"  "  <<"\n";
		// std::cout<<"After: " <<tempPointer->thisValue <<"  "  <<basePointer->thisValue <<"  "  <<"\n";
		

		// DL_List<T1>::eachValue * tempPointer   =  basePointer->backPointer;
		// tempPointer->forePointer  =  newPointer;
		// newPointer->backPointer   =  tempPointer;
		// newPointer->forePointer   =  basePointer;
		// basePointer->backPointer  =  newPointer;
	}
}
// 
// 
// 
template <typename T1>
T1 DL_List<T1>::pop ()
{
	listSize--;
	DL_List<T1>::eachValue * tempPointer  =  rootPointer;
	rootPointer              =  tempPointer->forePointer;
	T1 thisValue             =  tempPointer->thisValue;

	std::free(tempPointer);
	return thisValue;
}
// 
// 
// 
template <typename T1>
int DL_List<T1>::size ()
{
	return listSize;
}
// 
// 
// 
// This searches the pointer itself for the values. Unlike singly linked list that searches a parent for the child's value
template <typename T1> 
typename DL_List<T1>::eachValue * DL_List<T1>::searchHelpFunc (DL_List<T1>::eachValue * thisPointer, T1 searchValue)
{
	// std::cout  <<basePointer->thisValue <<"  "  <<"\n";

	if (thisPointer != NULL)
	{
		if (thisPointer->thisValue == searchValue)
		{
			return thisPointer;
		}
		else
		{
			DL_List<T1>::searchHelpFunc (thisPointer->forePointer, searchValue);
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
template <typename T1>
void DL_List<T1>::del (T1 deleteValue)
{
	DL_List<T1>::eachValue * tempPointer  =  DL_List<T1>::searchHelpFunc (rootPointer, deleteValue);

	if (tempPointer != NULL)
	{
		DL_List<T1>::eachValue * forePointed    =  tempPointer->forePointer;
		DL_List<T1>::eachValue * backPointed    =  tempPointer->backPointer;
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
template <typename T1>
std::string DL_List<T1>::search (T1 searchValue)
{
	DL_List<T1>::eachValue * tempPointer  =  DL_List<T1>::searchHelpFunc (rootPointer, searchValue);

	if (tempPointer != NULL)
	{
		return "value found in list";
	}
	return "value not found in list";
}
// 
// 
// 
template <typename T1>
T1 DL_List<T1>::peek (T1 peekValue)
{
	DL_List<T1>::eachValue * tempPointer  =  DL_List<T1>::searchHelpFunc (rootPointer, peekValue);

	if (tempPointer != NULL)
	{
		return tempPointer->forePointer->thisValue;
	}
	return -1;
}
// 
// 
// 
template <typename T1>
void DL_List<T1>::print ()
{
	DL_List<T1>::printHelpFunc (rootPointer);
}
// 
// 
// 
template <typename T1>
void DL_List<T1>::printHelpFunc (DL_List<T1>::eachValue * thisPointer)
{
	if (thisPointer != NULL)
	{
		std::cout<<thisPointer->thisValue <<"   ";
		DL_List<T1>::printHelpFunc (thisPointer->forePointer);
	}
	// else ()
}
// 
// 
// 

#endif
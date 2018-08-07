#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

template <typename T1>
class SL_List
{
	public:
		int listSize;
		SL_List();
		T1 pop();
		void push (T1 newValue);
		std::string search (T1 searchValue);
		void del (T1 deleteValue);
		void print ();
		int size ();
		T1 peek(T1 peekValue);

	private:
		struct eachValue
		{
			T1  thisValue;
			eachValue * backPointer;
		};
		eachValue * rootPointer;
		eachValue * basePointer;
		eachValue * searchHelpFunc (eachValue * thisPointer, T1 deleteValue);
		void printHelpFunc (eachValue * thisPointer);

};
// 
// 
// 
template <typename T1>
SL_List<T1>::SL_List()
{
	listSize    = 0;
	SL_List<T1>::rootPointer = NULL;
	SL_List<T1>::basePointer = NULL;
}
// 
// 
// 
template <typename T1>
void SL_List<T1>::push (T1 newValue)
{
	listSize++;
	SL_List<T1>::eachValue * newPointer     =  (SL_List<T1>::eachValue *) std::malloc(sizeof(SL_List<T1>::eachValue));
	newPointer->thisValue                   =  newValue;

	if (basePointer == NULL)
	{
		basePointer = newPointer;
	}
	else
	{
		SL_List<T1>::eachValue * tempPointer   =  basePointer;
		basePointer                            =  newPointer;
		basePointer->backPointer               =  tempPointer;
	}
}
// 
// 
// 
template <typename T1>
T1 SL_List<T1>::pop ()
{
	listSize--;
	SL_List<T1>::eachValue * tempPointer  =  basePointer;
	basePointer                           =  tempPointer->backPointer;
	T1 thisValue                          =  tempPointer->thisValue;

	std::free(tempPointer);
	return thisValue;
}
// 
// 
// 
template <typename T1>
int SL_List<T1>::size ()
{
	return listSize;
}
// 
// 
// 
// In Singly linked list, this returns the parent of the pointer we are interested in.
// In doubly linked list, this returns the actual pointer we are interested in.
template <typename T1> 
typename SL_List<T1>::eachValue * SL_List<T1>::searchHelpFunc (SL_List<T1>::eachValue * thisPointer, T1 searchValue)
{
	if (thisPointer == basePointer and basePointer->thisValue == searchValue)
	{
		return basePointer;
	}

	else if (thisPointer->backPointer != NULL)
	{
		if (thisPointer->backPointer->thisValue == searchValue)
		{
			return thisPointer;
		}
		else
		{
			SL_List<T1>::searchHelpFunc (thisPointer->backPointer, searchValue);
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
void SL_List<T1>::del (T1 deleteValue)
{
	SL_List<T1>::eachValue * parentPointer  =  SL_List<T1>::searchHelpFunc (basePointer, deleteValue);

	if (parentPointer != NULL)
	{
		SL_List<T1>::eachValue * tempPointer  = parentPointer->backPointer;
		parentPointer->backPointer = tempPointer->backPointer;

		std::free(tempPointer);
	}
	// else
	// {
	// 	break;
	// }	
}
// 
// 
// 
template <typename T1>
std::string SL_List<T1>::search (T1 searchValue)
{
	SL_List<T1>::eachValue * tempPointer  =  SL_List<T1>::searchHelpFunc (basePointer, searchValue);

	if (tempPointer != NULL)
	{
		return "value found in list";
	}
	return "value not found in list";
}


template <typename T1>
T1 SL_List<T1>::peek (T1 peekValue)
{
	SL_List<T1>::eachValue * tempPointer  =  SL_List<T1>::searchHelpFunc (basePointer, peekValue);

	if (tempPointer != NULL)
	{
		return tempPointer->backPointer->backPointer->thisValue;
	}
	return -1;
}
// 
// 
// 
template <typename T1>
void SL_List<T1>::print ()
{
	SL_List<T1>::printHelpFunc (basePointer);
}
// 
// 
// 
template <typename T1>
void SL_List<T1>::printHelpFunc (SL_List<T1>::eachValue * thisPointer)
{
	if (thisPointer != NULL)
	{
		std::cout<<thisPointer->thisValue <<"   ";
		SL_List<T1>::printHelpFunc (thisPointer->backPointer);
	}
}
// 
// 
// 

#endif
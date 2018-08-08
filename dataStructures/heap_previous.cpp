#ifndef HEAP_H
#define HEAP_H

#include "diffNode.h"
#include "doubly_linked_list.h"

template<typename T>
class Heap
{
	private:
		binNode<T> * rootNode;
		binNode<T> * baseNode;
		DL_List <binNode<T> * > myDL_List;


	public:
		Heap();
		void add(T newValue);
		void maxHeapify();
		void minHeapify ();
		int  popMin();
};

template<typename T>
Heap<T>::Heap()
{
	rootNode = NULL;
	baseNode = NULL;
}

template<typename T>
Heap<T>::add(int newValue)
{
	binNode<T> * newNode  =  (binNode<T>*) std::malloc(sizeof(binNode<T>));
	newNode-> value       =  newValue;

	Heap<T>::addHelpFunc(binNode<T>::rootNode, newValue);
}
//********* Find Node To Add Add Item******************//
template<typename T>
binNode<T> * Heap<T>::addHelpFunc(binNode<T> * oldNode, T newValue)
{
	if (oldNode == NULL)
	{
		return oldNode;
	}
	else
	{
		
	}
}
template<typename T>
Heap<T>::maxHeapify()
{

}
template<typename T>
Heap<T>::minHeapify()
{

}
template<typename T>
Heap<T>::popMin()
{

}


#endif

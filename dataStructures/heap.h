#ifndef HEAP_H
#define HEAP_H

// #include <math.h>   
#include <cmath>   
#include "diffNode.h"
#include "doubly_linked_list.h"


template<typename T>
class Heap
{
	private:
		std::vector<T> dataVector;
		void bubbleUpFixedNodeViolationMax (int child, int stopValue);
		void bubbleUpFixedNodeViolationMin (int child, int stopValue);
		void fixNodeViolationMax (int stopValue);
		void fixNodeViolationMin (int stopValue);
		


	public:
		Heap();
		void add(T newValue);
		void maxHeapify ();
		void minHeapify ();
		void maxHeapSort ();
		void minHeapSort ();
		void  print();
		void  testMaxHeap();
		void  testMinHeap();
};
// 
// 
// 
template<typename T>
Heap<T>::Heap()
{

}
// 
// 
// 
//********* Find Node To Add Add Item******************//
template<typename T>
void Heap<T>::add(T newValue)
{
	dataVector.push_back(newValue);
}
// 
// 
// 
//********* Find Node To Add Add Item******************//
template<typename T>
void Heap<T>::maxHeapSort()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		Heap<T>::fixNodeViolationMax(dataVector.size()-parent);
		Heap<T>::print();
		T temp                                   =   dataVector[0];
		dataVector[0]                            =   dataVector[dataVector.size()-parent-1];
		dataVector[dataVector.size()-parent-1]   =   temp;
	}
}
// 
// 
// 
//********* Find Node To Add Add Item******************//
template<typename T>
void Heap<T>::minHeapSort()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		Heap<T>::fixNodeViolationMin(dataVector.size()-parent);
		Heap<T>::print();
		T temp                                   =   dataVector[0];
		dataVector[0]                            =   dataVector[dataVector.size()-parent-1];
		dataVector[dataVector.size()-parent-1]   =   temp;
	}

}
// 
// 
// 
template<typename T>
void Heap<T>::maxHeapify()
{
	Heap<T>::fixNodeViolationMax(dataVector.size());
}
// 
// 
// 
template<typename T>
void Heap<T>::fixNodeViolationMax(int stopValue)
{
	// parent = n; children = 2n+1, 2n+2
	// child = N; parent = -1 + ceil(n/2)
	for (int parent = 0;  parent < stopValue;  parent++)
	{
		int child1   =  2*parent+1;
		int child2   =  2*parent+2;

		if (child1  < stopValue)
		{
			if (dataVector[parent] < dataVector[child1])
			{
				T temp               =   dataVector[child1];
				dataVector[child1]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		if (child2  < stopValue )
		{
			if (dataVector[parent] < dataVector[child2])
			{
				T temp               =   dataVector[child2];
				dataVector[child2]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		Heap<T>::bubbleUpFixedNodeViolationMax(parent, dataVector.size());
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::bubbleUpFixedNodeViolationMax(int child, int stopValue)
{
	// // parent = n; children = 2n+1, 2n+2 OR 2n, 2n+1
	// // child = N; parent = -1 + ceil(n/2)
	int parent = ceil(0.5*child)-1;

	if (parent  >= 0 and child < stopValue)
	{
		if (dataVector[parent] < dataVector[child])
		{
			T temp               =   dataVector[child];
			dataVector[child]    =   dataVector[parent];
			dataVector[parent]   =   temp;
		}
		Heap<T>::bubbleUpFixedNodeViolationMax(parent, stopValue);
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::minHeapify()
{
	Heap<T>::fixNodeViolationMin(dataVector.size());
}
// 
// 
// 
template<typename T>
void Heap<T>::fixNodeViolationMin(int stopValue)
{
	// parent = n; children = 2n+1, 2n+2
	// child = N; parent = -1 + ceil(n/2)
	for (int parent = 0;  parent < stopValue;  parent++)
	{
		int child1   =  2*parent+1;
		int child2   =  2*parent+2;

		if (child1  < stopValue)
		{
			if (dataVector[parent] > dataVector[child1])
			{
				T temp               =   dataVector[child1];
				dataVector[child1]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		if (child2  < stopValue )
		{
			if (dataVector[parent] > dataVector[child2])
			{
				T temp               =   dataVector[child2];
				dataVector[child2]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		Heap<T>::bubbleUpFixedNodeViolationMin(parent, stopValue);
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::bubbleUpFixedNodeViolationMin(int child, int stopValue)
{
	// // parent = n; children = 2n+1, 2n+2 OR 2n, 2n+1
	// // child = N; parent = -1 + ceil(n/2)
	int parent = ceil(0.5*child)-1;

	if (parent  >= 0 and child < stopValue)
	{
		if (dataVector[parent] > dataVector[child])
		{
			T temp               =   dataVector[child];
			dataVector[child]    =   dataVector[parent];
			dataVector[parent]   =   temp;
		}
		Heap<T>::bubbleUpFixedNodeViolationMin(parent, stopValue);
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::print()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		std::cout<<dataVector[parent]<<"  ";
	}
	std::cout<<"  \n";
}
// 
// 
// 
template<typename T>
void Heap<T>::testMaxHeap()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		int child1   =  2*parent+1;
		int child2   =  2*parent+2;

		if (child1  < dataVector.size() and dataVector[parent] < dataVector[child1] )
		{
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-maxv";
			std::cout<<";   ";
		}
		if (child2  < dataVector.size() and dataVector[parent] < dataVector[child2])
		{
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-maxv";
			std::cout<<";   ";
		}
	}
	std::cout<<"  \n";
}
// 
// 
// 
template<typename T>
void Heap<T>::testMinHeap()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		int child1   =  2*parent+1;
		int child2   =  2*parent+2;

		if (child1  < dataVector.size() and dataVector[parent] > dataVector[child1] )
		{
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-minv";
			std::cout<<";   ";
		}
		if (child2  < dataVector.size() and dataVector[parent] > dataVector[child2])
		{
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-minv";
			std::cout<<";   ";
		}
	}
	std::cout<<"  \n";
}
// 
// 
// 
#endif

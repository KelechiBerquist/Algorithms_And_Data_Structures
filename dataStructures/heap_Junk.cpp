#ifndef HEAP_H
#define HEAP_H

#include "diffNode.h"
#include "doubly_linked_list.h"

template<typename T>
class Heap
{
	private:
		// int parent1 = 
		std::vector<T> dataVector;
		DL_List<T> myQueue;


	public:
		Heap();
		void add(T newValue);
		void maxHeapify();
		void minHeapify ();
		T  popMin();
		void  print();
};
// 
// 
// 
template<typename T>
Heap<T>::Heap()
{
	// dataVector.push_back(-1);
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
template<typename T>
void Heap<T>::maxHeapify()
{
	// parent = n; children = 2n+1, 2n+2
	// child = N; parent = -1 + ceil(n/2)

	// for (int vecIndx = dataVector.size()-1;  vecIndx >= 0;  vecIndx--)
	// {
	// 	if (dataVector[-1 + ceil(vecIndx/2)] < dataVector[vecIndx] )
	// 	{
	// 		T temp                             =   dataVector[vecIndx];
	// 		dataVector[vecIndx]                =   dataVector[-1 + ceil(vecIndx/2)];
	// 		dataVector[-1 + ceil(vecIndx/2)]   =   temp;
	// 	}
	// }

	for (int vecIndx = 0;  vecIndx < dataVector.size();  vecIndx++)
	{
		if (dataVector[2*vecIndx+1] < dataVector[vecIndx] )
		{
			T temp                             =   dataVector[vecIndx];
			dataVector[vecIndx]                =   dataVector[-1 + ceil(vecIndx/2)];
			dataVector[-1 + ceil(vecIndx/2)]   =   temp;
		}
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::minHeapify()
{
	// parent = n; children = 2n+1, 2n+2
	// child = N; parent = -1 + ceil(n/2)
	for (int vecIndx = dataVector.size()-1;  vecIndx >= 0;  vecIndx--)
	{
		if (dataVector[-1 + ceil(vecIndx/2)] > dataVector[vecIndx] )
		{
			T temp                             =   dataVector[vecIndx];
			dataVector[vecIndx]                =   dataVector[-1 + ceil(vecIndx/2)];
			dataVector[-1 + ceil(vecIndx/2)]   =   temp;
		}
	}
}
// 
// 
// 
template<typename T>
T Heap<T>::popMin()
{

}
// 
// 
// 
template<typename T>
void Heap<T>::print()
{
	for (int vecIndx = 0;  vecIndx < dataVector.size();  vecIndx++)
	// for (int vecIndx = 0;  2*vecIndx+2 < dataVector.size();  vecIndx++)
	{
		std::cout<<dataVector[vecIndx]<<"  ";
		// if (dataVector[vecIndx] > dataVector[2*vecIndx+1])
		// {
		// 	T temp                    =   dataVector[vecIndx];
		// 	dataVector[vecIndx]       =   dataVector[2*vecIndx+1];
		// 	dataVector[2*vecIndx+1]   =   temp;
		// }
		// if (dataVector[vecIndx] < dataVector[2*vecIndx+2])
		// {
		// 	T temp                    =   dataVector[vecIndx];
		// 	dataVector[vecIndx]       =   dataVector[2*vecIndx+2];
		// 	dataVector[2*vecIndx+2]   =   temp;
		// }
	}
}
// 
// 
// 
#endif

// for (int vecIndx = dataVector.size()-1;  -1 + ceil(vecIndx/2) >= 0;  vecIndx--)
	// {
	// 	if (dataVector[vecIndx] > dataVector[-1 + ceil(vecIndx/2)])
	// 	{
	// 		T temp                             =   dataVector[vecIndx];
	// 		dataVector[vecIndx]                =   dataVector[-1 + ceil(vecIndx/2)];
	// 		dataVector[-1 + ceil(vecIndx/2)]   =   temp;
	// 	}
	// 	// if (dataVector[vecIndx] < dataVector[2*vecIndx+2])
	// 	// {
	// 	// 	T temp                    =   dataVector[vecIndx];
	// 	// 	dataVector[vecIndx]       =   dataVector[2*vecIndx+2];
	// 	// 	dataVector[2*vecIndx+2]   =   temp;
	// 	// }
	// }
	// for (int vecIndx = dataVector.size()-1;  2*vecIndx+2 < dataVector.size();  vecIndx++)
	// {
	// 	if (dataVector[vecIndx] < dataVector[2*vecIndx+1])
	// 	{
	// 		T temp                    =   dataVector[vecIndx];
	// 		dataVector[vecIndx]       =   dataVector[2*vecIndx+1];
	// 		dataVector[2*vecIndx+1]   =   temp;
	// 	}
	// 	if (dataVector[vecIndx] < dataVector[2*vecIndx+2])
	// 	{
	// 		T temp                    =   dataVector[vecIndx];
	// 		dataVector[vecIndx]       =   dataVector[2*vecIndx+2];
	// 		dataVector[2*vecIndx+2]   =   temp;
	// 	}
	// }

// for (int vecIndx = dataVector.size()-1;  -1 + ceil(vecIndx/2) >= 0;  vecIndx--)
	// {
	// 	if (dataVector[vecIndx] < dataVector[-1 + ceil(vecIndx/2)])
	// 	{
	// 		T temp                             =   dataVector[vecIndx];
	// 		dataVector[vecIndx]                =   dataVector[-1 + ceil(vecIndx/2)];
	// 		dataVector[-1 + ceil(vecIndx/2)]   =   temp;
	// 	}
	// }
	// for (int vecIndx = 0;  2*vecIndx+2 < dataVector.size();  vecIndx++)
	// {
	// 	if (dataVector[vecIndx] > dataVector[2*vecIndx+1])
	// 	{
	// 		T temp                    =   dataVector[vecIndx];
	// 		dataVector[vecIndx]       =   dataVector[2*vecIndx+1];
	// 		dataVector[2*vecIndx+1]   =   temp;
	// 	}
	// 	if (dataVector[vecIndx] < dataVector[2*vecIndx+2])
	// 	{
	// 		T temp                    =   dataVector[vecIndx];
	// 		dataVector[vecIndx]       =   dataVector[2*vecIndx+2];
	// 		dataVector[2*vecIndx+2]   =   temp;
	// 	}
	// }
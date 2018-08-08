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
		// int parent1 = 
		std::vector<T> dataVector;
		DL_List<T> myQueue;
		void bubbleUpFixedNodeViolationMax (int child);
		void bubbleUpFixedNodeViolationMin (int child);
		void fixNodeViolationMax (int stopValue);
		void fixNodeViolationMin (int stopValue);
		


	public:
		Heap();
		void add(T newValue);
		void maxHeapify ();
		void minHeapify ();
		Heap<T> maxHeapSort ();
		Heap<T> minHeapSort ();
		T  popMin();
		void  print();
		void  printMax();
		void  printMin();
};
// 
// 
// 
template<typename T>
Heap<T>::Heap()
{
	// std::cout<<1.0/2.0<<"\n";
	// dataVector.push_back(-1);
	// std::cout<<"Check ceil in header: " <<ceil(1/2)-1<<"  "  <<ceil(5/2)-1<<"  "  <<ceil(7/2)-1<<"  "  <<ceil(13/2)-1<<"  "  <<"\n";
	// std::cout<<"Check ceil in header: " <<ceil(0.5)-1<<"  "  <<ceil(2.5)-1<<"  "  <<ceil(3.5)-1<<"  "  <<ceil(6.5)-1<<"  "  <<"\n";
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
Heap<T> Heap<T>::maxHeapSort()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		Heap<T>::fixNodeViolationMax(dataVector.size()-parent);
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
Heap<T> Heap<T>::minHeapSort()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		Heap<T>::fixNodeViolationMin(dataVector.size()-parent);
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

		if (child1  < dataVector.size())
		{
			if (dataVector[parent] < dataVector[child1])
			{
				T temp               =   dataVector[child1];
				dataVector[child1]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		if (child2  < dataVector.size() )
		{
			if (dataVector[parent] < dataVector[child2])
			{
				T temp               =   dataVector[child2];
				dataVector[child2]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		Heap<T>::bubbleUpFixedNodeViolationMax(parent);
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::bubbleUpFixedNodeViolationMax(int child)
{
	// // parent = n; children = 2n+1, 2n+2 OR 2n, 2n+1
	// // child = N; parent = -1 + ceil(n/2)
	int parent = ceil(0.5*child)-1;

	if (parent  >= 0 and child < dataVector.size())
	{
		if (dataVector[parent] < dataVector[child])
		{
			T temp               =   dataVector[child];
			dataVector[child]    =   dataVector[parent];
			dataVector[parent]   =   temp;
		}
		Heap<T>::bubbleUpFixedNodeViolationMax(parent);
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

		if (child1  < dataVector.size())
		{
			if (dataVector[parent] > dataVector[child1])
			{
				T temp               =   dataVector[child1];
				dataVector[child1]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		if (child2  < dataVector.size() )
		{
			if (dataVector[parent] > dataVector[child2])
			{
				T temp               =   dataVector[child2];
				dataVector[child2]   =   dataVector[parent];
				dataVector[parent]   =   temp;
			}
		}

		Heap<T>::bubbleUpFixedNodeViolationMin(parent);
	}
}
// 
// 
// 
template<typename T>
void Heap<T>::bubbleUpFixedNodeViolationMin(int child)
{
	// // parent = n; children = 2n+1, 2n+2 OR 2n, 2n+1
	// // child = N; parent = -1 + ceil(n/2)
	int parent = ceil(0.5*child)-1;

	if (parent  >= 0 and child < dataVector.size())
	{
		if (dataVector[parent] > dataVector[child])
		{
			T temp               =   dataVector[child];
			dataVector[child]    =   dataVector[parent];
			dataVector[parent]   =   temp;
		}
		Heap<T>::bubbleUpFixedNodeViolationMin(parent);
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
void Heap<T>::printMax()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		// std::cout<<dataVector[parent]<<"";
		int child1   =  2*parent+1;
		int child2   =  2*parent+2;

		if (child1  < dataVector.size() and dataVector[parent] < dataVector[child1] )
		{
			// if (dataVector[parent] > dataVector[child1] or dataVector[parent] > dataVector[child2])
			// {
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-maxv";
			std::cout<<";   ";
			// }
		}
		if (child2  < dataVector.size() and dataVector[parent] < dataVector[child2])
		{
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-maxv";
			std::cout<<";   ";
		}

		// if (child1  < dataVector.size() or child2  < dataVector.size() )
		// {
		// 	if (dataVector[parent] < dataVector[child1] or dataVector[parent] < dataVector[child2])
		// 	{
		// 		std::cout<<dataVector[parent]<<"";
		// 		std::cout<<"<-maxv";
		// 		std::cout<<";   ";
		// 	}
		// }
		// std::cout<<";   ";
	}
	std::cout<<"  \n";
}
// 
// 
// 
template<typename T>
void Heap<T>::printMin()
{
	for (int parent = 0;  parent < dataVector.size();  parent++)
	{
		// std::cout<<dataVector[parent]<<"";
		int child1   =  2*parent+1;
		int child2   =  2*parent+2;

		if (child1  < dataVector.size() and dataVector[parent] > dataVector[child1] )
		{
			// if (dataVector[parent] > dataVector[child1] or dataVector[parent] > dataVector[child2])
			// {
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-minv";
			std::cout<<";   ";
			// }
		}
		if (child2  < dataVector.size() and dataVector[parent] > dataVector[child2])
		{
			std::cout<<dataVector[parent]<<"";
			std::cout<<"<-minv";
			std::cout<<";   ";
		}
		// if (child1  < dataVector.size() or child2  < dataVector.size() )
		// {
		// 	if (dataVector[parent] > dataVector[child1] or dataVector[parent] > dataVector[child2])
		// 	{
		// 		std::cout<<dataVector[parent]<<"";
		// 		std::cout<<"<-minv";
		// 		std::cout<<";   ";
		// 	}
		// }
		// // std::cout<<";   ";
	}
	std::cout<<"  \n";
}
// 
// 
// 
#endif

// // 
// // 
// // 
// template<typename T>
// void Heap<T>::maxViolation()
// {
// 	// // parent = n; children = 2n+1, 2n+2 OR 2n, 2n+1
// 	// // child = N; parent = -1 + ceil(n/2)

// 	for (int child = dataVector.size()-1;  ceil(0.5*child)-1 >= 0;  child--)
// 	{
// 		int parent = ceil(0.5*child)-1;

// 		if (dataVector[parent] < dataVector[child])
// 		{
// 			T temp               =   dataVector[child];
// 			dataVector[child]    =   dataVector[parent];
// 			dataVector[parent]   =   temp;

// 			std::cout<<"p: " <<parent <<"c: " <<child <<"\n";
// 		}
// 	}
// }
// // 
// // 
// // 
// template<typename T>
// void Heap<T>::minViolation()
// {
// 	// parent = n; children = 2n+1, 2n+2
// 	// child = N; parent = -1 + ceil(n/2)
// 	for (int child = dataVector.size()-1;  ceil(0.5*child)-1 >= 0;  child--)
// 	{
// 		int parent = ceil(0.5*child)-1;

// 		if (dataVector[parent] > dataVector[child])
// 		{
// 			T temp               =   dataVector[child];
// 			dataVector[child]    =   dataVector[parent];
// 			dataVector[parent]   =   temp;

// 			std::cout<<"p: " <<parent <<"c: " <<child <<"\n";
// 		}
// 	}
// }
// // 
// // 
// // 

// 
// 
// 
// template<typename T>
// void Heap<T>::maxHeapify()
// {
// 	// parent = n; children = 2n+1, 2n+2
// 	// child = N; parent = -1 + ceil(n/2)
// 	for (int parent = 0;  2*parent+2 < dataVector.size();  parent++)
// 	{
// 		// int child = 2*parent+2;
// 		// if (dataVector[parent] < dataVector[child])
// 		// {
// 		// 	Heap<T>::maxHeapify(parent);
// 		// }

// 		// int child1   =  2*parent+1;
// 		// int child2   =  2*parent+2;

// 		// if (child1  < dataVector.size() or child2  < dataVector.size() )
// 		// {
// 		// 	if (dataVector[parent] < dataVector[child1] or dataVector[parent] < dataVector[child2])
// 		// 	{
// 		// 		Heap<T>::bubbleUpFixedNodeViolationMax(parent);
// 		// 	}
// 		// }

// 		Heap<T>::bubbleUpFixedNodeViolationMax(parent);
// 	}
// }
// // 
// // 
// // 
// template<typename T>

// void Heap<T>::minHeapify()
// {
// 	// parent = n; children = 2n+1, 2n+2
// 	// child = N; parent = -1 + ceil(n/2)
// 	for (int parent = 0;  2*parent+2 < dataVector.size();  parent++)
// 	{
// 		// int child = 2*parent+2;
// 		// if (dataVector[parent] < dataVector[child])
// 		// {
// 		// 	Heap<T>::maxHeapify(parent);
// 		// }

// 		int child1   =  2*parent+1;
// 		int child2   =  2*parent+2;

// 		if (child1  < dataVector.size() or child2  < dataVector.size() )
// 		{
// 			if (dataVector[parent] > dataVector[child1] or dataVector[parent] > dataVector[child2])
// 			{
// 				Heap<T>::bubbleUpFixedNodeViolationMin(parent);
// 			}
// 		}

// 		// Heap<T>::bubbleUpFixedNodeViolationMin(parent);
// 	}
// }
// // 
// // 
// // 
// template<typename T>
// void Heap<T>::bubbleUpFixedNodeViolationMax(int parent)
// {
// 	// // parent = n; children = 2n+1, 2n+2 OR 2n, 2n+1
// 	// // child = N; parent = -1 + ceil(n/2)

// 	int child1   =  2*parent+1;
// 	int child2   =  2*parent+2;

// 	if (child1  < dataVector.size())
// 	{
// 		if (dataVector[parent] < dataVector[child1])
// 		{
// 			T temp               =   dataVector[child1];
// 			dataVector[child1]   =   dataVector[parent];
// 			dataVector[parent]   =   temp;
// 		}
// 		Heap<T>::bubbleUpFixedNodeViolationMax(child1);
// 	}

// 	if (child2  < dataVector.size() )
// 	{
// 		if (dataVector[parent] < dataVector[child2])
// 		{
// 			T temp               =   dataVector[child2];
// 			dataVector[child2]   =   dataVector[parent];
// 			dataVector[parent]   =   temp;
// 		}
// 		Heap<T>::bubbleUpFixedNodeViolationMax(child2);
// 	}
// }
// // 
// // 
// // 
// template<typename T>
// void Heap<T>::bubbleUpFixedNodeViolationMin(int child)
// {
// 	// parent = n; children = 2n+1, 2n+2
// 	// child = N; parent = -1 + ceil(n/2)
// 	for (int child = dataVector.size()-1;  ceil(0.5*child)-1 >= 0;  child--)
// 	{
// 		int parent = ceil(0.5*child)-1;

// 		if (dataVector[parent] > dataVector[child])
// 		{
// 			T temp               =   dataVector[child];
// 			dataVector[child]    =   dataVector[parent];
// 			dataVector[parent]   =   temp;

// 			// std::cout<<"p: " <<parent <<"c: " <<child <<"\n";
// 		}
// 	}
// }
// // 
// // 
// // 

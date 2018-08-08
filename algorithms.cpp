// QuickSort.cpp

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <utility>      // std::pair, std::make_pair
#include <cstddef>
#include <new>          // ::operator new
#include <math.h>  
#include <cmath>   


#include "algorithms/sortFunctions.h"
#include "algorithms/searchFunctions.h"
#include "dataStructures/binarySearchTree.h"
#include "dataStructures/graph.h"
#include "dataStructures/trie.h"
#include "dataStructures/doubly_linked_list.h"
#include "dataStructures/singly_linked_list.h"
#include "dataStructures/diffNode.h"
#include "dataStructures/heap.h"


using std::vector;
using std::list;
using std::cout;
using std::cin;
using std::string;


constexpr auto low_bound = 0;
constexpr auto up_bound = 10000;
int m = 0;



int main()
{
	cout<<"Enter length of array: ";
	cin>>m;

	auto seed = std::chrono::system_clock::now().time_since_epoch().count();//seed
	std::default_random_engine dre(seed);//engine
	std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution

	std::vector <int> ArrayToSort(m);

	std::generate(ArrayToSort.begin(), ArrayToSort.end(), [&]{ return di(dre);});

	// for (auto i: ArrayToSort)
	// {
	// 	// cout<<i<<"  ";
	// }
	// cout<<"\n";
	// cout<<"\n";

	// vector<int>Heapified = Heapify (ArrayToSort);
	// for (auto i: Heapified)
	// {
	// 	cout<<i<<"  ";
	// }
	// cout<<"\n";
	// cout<<"\n";


	// cout<<"Check ceil: " <<ceil(1/2)-1<<"  "  <<ceil(5/2)-1<<"  "  <<ceil(7/2)-1<<"  "  <<ceil(13/2)-1<<"  "  <<"\n";
	// cout<<"Check ceil: " <<ceil(0.5)-1<<"  "  <<ceil(2.5)-1<<"  "  <<ceil(3.5)-1<<"  "  <<ceil(6.5)-1<<"  "  <<"\n";


	// // ******************************************************************************************************//
	// // **************** Begin For Implementing MyHeap *************************//
	// // ******************************************************************************************************//
	Heap <int> myHeap1;
	Heap <int> myHeap2;

	for (int i : ArrayToSort)
	{
		myHeap1.add(i);
		myHeap2.add(i);
	}

	// myHeap1.print();
	// myHeap2.print();
	cout<<"\n";
	cout<<"\n";
	myHeap1.maxHeapify();
	myHeap2.minHeapify();

	// cout<<"\n";
	// cout<<"\n";
	myHeap1.printMax();
	cout<<"\n";
	cout<<"\n";
	myHeap2.printMin();
	cout<<"\n";
	cout<<"\n";

	Heap <int> mySortedHeap1 = myHeap1.maxHeapSort();
	Heap <int> mySortedHeap2 = myHeap2.minHeapSort();

	mySortedHeap1.print();
	cout<<"\n";
	cout<<"\n";
	// mySortedHeap2.print();
	
	// // ******************************************************************************************************//
	// // **************** End For Implementing MyHeap *************************//
	// // ******************************************************************************************************//



	// // ******************************************************************************************************//
	// // **************** Begin For Implementing SL_ and DL_List *************************//
	// // ******************************************************************************************************//
	// DL_List <int> myDL_List;	
	// SL_List <int> mySL_List;	
	// for (int i : ArrayToSort)
	// {
	// 	myDL_List.push(i);
	// 	mySL_List.push(i);
	// 	// cout<< myDL_List.size() <<"  ";
	// 	// cout<< mySL_List.size() <<"  ";
	// }
	// cout<<"\n";
	// myDL_List.print();
	// cout<<"\n";
	// mySL_List.print();
	// cout<<"\n";

	// myDL_List.pop();
	// cout<< myDL_List.size() <<"  ";
	// mySL_List.pop();
	// cout<< mySL_List.size() <<"  ";
	// cout<<"\n";

	// myDL_List.push(90099);
	// cout<< myDL_List.size() <<"  ";
	// cout<<"\n";
	// mySL_List.push(90099);
	// cout<< mySL_List.size() <<"  ";
	// cout<<"\n";

	// cout<<myDL_List.search(-77) <<"  " <<mySL_List.search(-77) <<"  ";
	// cout<<"\n";

	// cout<<myDL_List.search(ArrayToSort[3]) <<"  " <<mySL_List.search(ArrayToSort[3]) <<"  ";
	// cout<<"\n";

	// cout<< ArrayToSort[3] <<"   " <<myDL_List.peek(ArrayToSort[3]) <<"  " <<mySL_List.peek(ArrayToSort[3]) <<"  ";
	// cout<<"\n";

	// myDL_List.del(ArrayToSort[3]);
	// myDL_List.print();
	// cout<<"\n";
	// mySL_List.del(ArrayToSort[3]);
	// mySL_List.print();
	// cout<<"\n";
	// cout<<"\n";
	// cout<<"\n";
	// // ******************************************************************************************************//
	// // **************** End For Implementing SL_ and DL_List *************************//
	// // ******************************************************************************************************//



	// // ******************************************************************************************************//
	// // **************** Begin For Implementing BST *************************//
	// // ******************************************************************************************************//
	// BST <int> myTree;	
	// for (int i : ArrayToSort)
	// {
	// 	myTree.add(i);
	// }
	// // cout<<"\n";
	// // cout<<"\n";
	// myTree.print();
	// cout<<"\n";
	// cout<<"\n";
	// cout<<-77 <<":   ";
	// cout<<myTree.search(-77) <<"  " ;
	// cout<<"\n";
	// cout<<"\n";
	// cout<< ArrayToSort[3]-704 <<":   " ;
	// cout<<myTree.search(ArrayToSort[3]-704) <<"  " ;
	// cout<<"\n";
	// cout<<"\n";
	// cout<< ArrayToSort[m-1]+99 <<":   " ;
	// cout<<myTree.search(ArrayToSort[m-1]+99) <<"  " ;
	// cout<<"\n";
	// cout<<"\n";
	// cout<< ArrayToSort[m-17]*10 <<":   " ;
	// cout<<myTree.search(ArrayToSort[m-17]*10) <<"  " ;
	// cout<<"\n";
	// cout<<"\n";
	// // ******************************************************************************************************//
	// // **************** End For Implementing BST *************************//
	// // ******************************************************************************************************//



	// //******************************************************************************************************//
	// //**************** Begin For Implementing Graph *************************//
	// //******************************************************************************************************//
	// double weight    =  20;
	// int src       =  0,
	//     dest      =  1;

	// Graph myGraph = Graph(m);

	// myGraph.addEdge(src, dest, weight);
	// //******************************************************************************************************//
	// //**************** End For Implementing Graph *************************//
	// //******************************************************************************************************//


 	
 	//******************************************************************************************************//
	//**************** Begin For Implementing Trie *************************//
	//******************************************************************************************************//
	// Trie <int> myTrie;

	// for (string a : {"peter", "piper", "picked", "peck", "pickled", "pepper", "kelechi", "is", "the", "bestest", "good", "gehn", "googler", "abrada", "cabra", "cool", "whip"})
	// {
	// 	// cout<<a<<" ";
	// 	myTrie.add(a);
	// }
	// cout<<"\n";
	// cout<<"\n";
	// cout<<"\n";
	// myTrie.print();
	// cout<<"\n";
	//******************************************************************************************************//
	//**************** Begin For Implementing Trie *************************//
	//******************************************************************************************************//
	

	//******************************************************************************************************//
	//**************** Begin For Implementing All Linear Container Sort and Search *************************//
	//******************************************************************************************************//
	// for (auto i: ArrayToSort)
	// {
	// 	cout<<i<<"  ";
	// }
	// cout<<"\n";
	// cout<<"\n";

	// // Implement MergeSort
	// vector <int> SortedArray(MergeSort (ArrayToSort));
	// for (auto i: SortedArray)
	// {
	// 	cout<<i<<"  ";
	// }
	// cout<<"\n";


	// int thisNumber = di(dre);

	// // Implement Binary Search
	// int theIndex = BinarySearch (SortedArray, thisNumber);
	// cout<<"\nReturn: ";
	// cout<<thisNumber<<"   "<<theIndex<<"\n";



	// std::uniform_int_distribution <int> thatDi (0, SortedArray.size());
	// thisNumber = thatDi (dre);



	// theIndex = BinarySearch (SortedArray, SortedArray[thisNumber]);
	// cout<<"\nReturn: ";
	// cout<<SortedArray[thisNumber]<<"   "<<thisNumber<<"   "<<theIndex<<"\n";

	//******************************************************************************************************//
	//**************** Begin For Implementing All Linear Container Sort and Search *************************//
	//******************************************************************************************************//

	return 0;
}
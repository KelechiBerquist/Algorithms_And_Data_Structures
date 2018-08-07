#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iterator>
#include <algorithm>

#include "sortFunctions.h"

using namespace std;
using std::vector;
using std::list;
using std::cout;
using std::cin;


vector <int> Heapify (vector <int> ThisArray)
{
	for (int it1 = ThisArray.size()-1;  it1 >= 0;  it1--)
	{
		if ( ThisArray[it1] <=  ThisArray[floor((it1-1)/2)])
		{
			continue;
		}

		else if (ThisArray[it1] >  ThisArray[floor((it1-1)/2)])
		{
			int temp1                    =  ThisArray[floor((it1-1)/2)];
			ThisArray[floor((it1-1)/2)]  =  ThisArray[it1];
			ThisArray[it1]               =  temp1;
		}
	}

	return ThisArray;
}
// 
// 
// 
vector <int> HeapSort (vector <int> ThisArray)
{
	vector <int> SortedVector = {};

	while (!ThisArray.empty())
	{
		int temp1  =  ThisArray.back();
		ThisArray.erase(--ThisArray.end());
		ThisArray.insert(ThisArray.begin(), temp1);
		ThisArray  =  Heapify (ThisArray);
		SortedVector.insert(SortedVector.begin(), ThisArray.front());
		ThisArray.erase(ThisArray.begin());
	}

	return SortedVector;
}
// 
// 
// 
vector<int> BubbleSort (vector<int>ThisArray)
{
	for (int i = 0;  i < ThisArray.size();  i++)
	{
		for (int j = i+1;  j < ThisArray.size();  j++)
		{
			if (ThisArray[i] < ThisArray[j])
			{
				continue;
			}
			else
			{
				int temp1    = ThisArray[i];
				ThisArray[i] = ThisArray[j];
				ThisArray[j] = temp1;
			}
		}
	}
	return ThisArray;
}
// 
// 
// 
vector <int> InsertionSort (vector <int> ThisArray)
{
	for (int it1 = 1;  it1 < ThisArray.size();  it1++)
	{
		for (int it2 = 0;  it2 < it1;  it2++)
		{
			
			if (it1 != it2 and ThisArray[it1] < ThisArray[it2])
			// if (it1 != it2 and ThisArray[it1] >= ThisArray[it2-1] and ThisArray[it1] < ThisArray[it2])
			{
				int temp1 = ThisArray[it1];
				ThisArray.erase(ThisArray.begin()+it1);
				ThisArray.insert(ThisArray.begin()+it2, temp1);
				break;
			}
		}
	}

	return ThisArray;
}
// 
// 
// 
list<int> InsertionSortList (list <int> ThisArray)
{
	for (list<int>::iterator it1 = ++ThisArray.begin();  it1 != ThisArray.end();  ++it1)
	{
		for (list<int>::iterator it2 = ThisArray.begin();  it2 != it1;  ++it2)
		{
			if (it1 != it2 and *it1 < *it2)
			{	
				int temp1 = *it1;
				ThisArray.erase(it1);
				ThisArray.insert(it2, temp1);
				break;
			}
		}
	}
	return ThisArray;
}
// 
// 
// 
std::vector<int> MergeSort (vector<int> SortArray)
{
	if (SortArray.size() == 1)
	{
		return SortArray;
	}

	vector <int> LHS = MergeSort (vector<int> ( SortArray.begin(), SortArray.begin()+ceil(SortArray.size()/2) ));
	vector <int> RHS = MergeSort (vector<int> ( SortArray.begin()+ceil(SortArray.size()/2), SortArray.end() ));


	vector <int> SortedVector = {};

	while (LHS.size() and RHS.size())
	{
		if (LHS[0] < RHS[0])
		{
			SortedVector.push_back(LHS[0]);
			LHS.erase(LHS.begin() + 0);
		}
		else
		{
			SortedVector.push_back(RHS[0]);
			RHS.erase(RHS.begin() + 0);
		}
	}
	
	SortedVector.insert(SortedVector.end(), LHS.begin(), LHS.end());	
	SortedVector.insert(SortedVector.end(), RHS.begin(), RHS.end());
	return SortedVector;
}
// 
// 
// 
vector <int> QuickSort (vector <int> ThisArray)
{
	if (ThisArray.size() == 1)
	{
		return ThisArray;
	}

	double pivot = (ThisArray.front() + ThisArray.back()) / 2;

	int wall = 0;


	for (int it1 = 0;  it1 < ThisArray.size();  it1++)
	{
		if (ThisArray[it1] <= pivot)
		{
			int temp1 = ThisArray[it1];
			ThisArray.erase(ThisArray.begin()+it1);
			ThisArray.insert(ThisArray.begin()+wall++, temp1);
		}
	}

	vector <int> LHS = QuickSort( vector <int> ( ThisArray.begin(), ThisArray.begin()+wall ) );
	vector <int> RHS = QuickSort( vector <int> ( ThisArray.begin()+wall, ThisArray.end() ) );

	vector <int> SortedVector = {};

	SortedVector.insert(SortedVector.begin(), LHS.begin(), LHS.end());
	SortedVector.insert(SortedVector.end(), RHS.begin(), RHS.end());

	for (auto i: SortedVector)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

	return SortedVector;
}
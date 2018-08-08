// QuickSort.cpp

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iterator>
#include <algorithm>

using namespace std;
using std::vector;
using std::list;
using std::cout;
using std::cin;


constexpr auto low_bound = 0;
constexpr auto up_bound = 1000;
int m = 0;


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


int main()
{

	cout<<"Enter length of array: ";
	cin>>m;

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();//seed
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution

    std::vector <int> ArrayToSort(m);
  
    std::generate(ArrayToSort.begin(), ArrayToSort.end(), [&]{ return di(dre);});
 	
 	
    for (auto i: ArrayToSort)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

    vector <int> SortedArray(HeapSort (ArrayToSort));
    
    
    for (auto i: SortedArray)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

	return 0;
}
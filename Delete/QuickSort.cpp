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

    vector <int> SortedArray(QuickSort (ArrayToSort));
    
    
    for (auto i: SortedArray)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

	// cout <<SortedArray.front()<<"  "  <<"  " <<"\n";

	return 0;
}
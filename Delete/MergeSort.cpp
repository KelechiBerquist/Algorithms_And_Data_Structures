// MergeSort_1D.cpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using std::vector;
using std::cout;
using std::cin;
using std::string;



constexpr auto low_bound = 0;
constexpr auto up_bound = 1000;

int m = 0;




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


int main ()
{
    cout<<"Enter length of array: ";
	cin>>m;

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();//seed
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution

    std::vector<int> ArrayToSort(m);
  
    std::generate(ArrayToSort.begin(), ArrayToSort.end(), [&]{ return di(dre);});
 	

	std::vector<int> SortedArray( MergeSort (ArrayToSort) ) ;


	for (auto i: ArrayToSort)
	{
		cout <<i <<"   ";
	}
	cout<<"\n";


	for (auto i: SortedArray)
	{
		cout <<i <<"   ";
	}
	cout<<"\n";

	return 0;

}

// InsertionSort.cpp

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


list<int> InsertionSort (list <int> ThisArray)
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


int main()
{

	cout<<"Enter length of array: ";
	cin>>m;

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();//seed
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution

    std::list<int> ArrayToSort(m);
  
    std::generate(ArrayToSort.begin(), ArrayToSort.end(), [&]{ return di(dre);});
 	
 	
    for (auto i: ArrayToSort)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

    list <int> SortedArray(InsertionSort (ArrayToSort));
    
    
    for (auto i: SortedArray)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

	return 0;
}
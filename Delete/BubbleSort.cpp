// BubbleSort.cpp

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using std::vector;
using std::cout;
using std::cin;


constexpr auto low_bound = 0;
constexpr auto up_bound = 1000;
int m = 0;


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

int main()
{

	cout<<"Enter length of array: ";
	cin>>m;

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();//seed
    std::default_random_engine dre(seed);//engine
    std::uniform_int_distribution<int> di(low_bound,up_bound);//distribution

    std::vector<int> ArrayToSort(m);
  
    std::generate(ArrayToSort.begin(), ArrayToSort.end(), [&]{ return di(dre);});
 	
 	
    for (auto i: ArrayToSort)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

    std::vector<int> SortedArray(BubbleSort (ArrayToSort));
    
    
    for (auto i: SortedArray)
	{
		cout<<i<<"  ";
	}
	cout<<"\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iterator>
#include <algorithm>

#include "search.h"

using namespace std;
using std::vector;
using std::list;
using std::cout;
using std::cin;



int BinarySearch (vector <int> ThatArray, int number)
{
	int foundIndex  =  ThatArray.size();
	int startIndex  =  0;
	int stopIndex   =  ThatArray.size()-1;
	int midIndex    =  floor((startIndex + stopIndex)/2);
	
	while (startIndex <= stopIndex)
	{	
		midIndex    =  floor((startIndex + stopIndex)/2);
		cout <<"   "<<number<<":"<<startIndex<<","<<midIndex<<","<<stopIndex;

		if (number == ThatArray[midIndex])
		{
			return midIndex;
		}

		else if (number < ThatArray[midIndex])
		{			
			stopIndex   =  midIndex-1;
		}

		else if (number > ThatArray[midIndex])
		{
			startIndex  =  midIndex+1;
		}
	}
	return -1;
}

int BreadFirstSearch (vector <int> ThatArray, int number)
{
	int foundIndex  =  ThatArray.size();
	int startIndex  =  0;
	int stopIndex   =  ThatArray.size()-1;
	int midIndex    =  floor((startIndex + stopIndex)/2);
	
	while (startIndex <= stopIndex)
	{	
		midIndex    =  floor((startIndex + stopIndex)/2);
		cout <<"   "<<number<<":"<<startIndex<<","<<midIndex<<","<<stopIndex;

		if (number == ThatArray[midIndex])
		{
			return midIndex;
		}

		else if (number < ThatArray[midIndex])
		{			
			stopIndex   =  midIndex-1;
		}

		else if (number > ThatArray[midIndex])
		{
			startIndex  =  midIndex+1;
		}
	}
	return -1;
}
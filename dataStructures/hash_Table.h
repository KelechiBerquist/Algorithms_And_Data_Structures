#ifndef HASH_TABLE
#define HASH_TABLE

#include "diffNode.h"

template<typename T1, typename T2>
class HashTable
{
	private:
		int outerSize;
		int innerSize;
		std::vector<hashNode<T1, T2> *> underVector;
		hashNode<T1, T2> * addHelpFunc(hashNode<T1, T2> * oldNode, T1 newKey, T2 newValue);
		hashNode<T1, T2> * searchHelpFunc(hashNode<T1, T2> * thisNode, T1 searchKey);
		void  printHelpFunc(hashNode<T1, T2> * thisNode);

	public:
		HashTable();
		void add(T1 newKey, T2 newValue);
		T2 search(T1 searchKey);
		void print();



};
// 
// 
// 
template<typename T1, typename T2>
HashTable<T1, T2>::HashTable()
{
	outerSize = 100;
	underVector.resize(outerSize);

	for (int i = 0;  i < outerSize;  i++)
	{
		underVector[i] = NULL;
	}
}
// 
// 
// 
// 
template<typename T1, typename T2>
void HashTable<T1, T2>::add(T1 newKey, T2 newValue)
{
	hashNode<T1, T2> * newNode  =  (hashNode<T1, T2> *) std::malloc(sizeof(hashNode<T1, T2>));
	newNode->key                =  newKey;
	newNode->value              =  newValue;

	if (underVector[newKey%outerSize] == NULL)
	{
		underVector[newKey%outerSize] = newNode;
	}
	else
	{
		hashNode<T1, T2> * bottomNode  =  HashTable<T1, T2>::addHelpFunc(underVector[newKey%outerSize], newKey, newValue);

		if (bottomNode != NULL and bottomNode->key != newNode->key)
		{
			newNode->parent   =  bottomNode;

			if (newNode->key < bottomNode->key)
			{
				bottomNode->child_left = newNode;
			}
			else
			{
				bottomNode->child_right = newNode;
			}
		}
	}
}
// 
// 
// 
template<typename T1, typename T2>
hashNode<T1, T2> * HashTable<T1, T2>::addHelpFunc(hashNode<T1, T2> * oldNode, T1 newKey, T2 newValue)
{
	if ( newKey == oldNode->key)
	{
		return NULL;
	}

	else if ( newKey < oldNode->key)
	{
		if (oldNode->child_left == NULL)
		{
			return oldNode;
		}
		else
		{
			// std::cout<<"Search Left of: " <<oldNode->value <<";  \n";
			HashTable<T1, T2>::addHelpFunc(oldNode->child_left, newKey, newValue);
		}
	}

	else 
	{
		if (oldNode->child_right == NULL)
		{
			return oldNode;
		}
		else
		{
			// std::cout<<"Search Right of: " <<oldNode->value <<";  \n";
			HashTable<T1, T2>::addHelpFunc(oldNode->child_right, newKey, newValue);
		}
	}
}
// 
// 
// 
template<typename T1, typename T2>
T2 HashTable<T1, T2>::search(T1 searchKey)
{	
	hashNode<T1, T2> * thisNode = HashTable<T1, T2>::searchHelpFunc(underVector[searchKey%outerSize], searchKey);
	if(thisNode != NULL)
	{
		return thisNode->value;
		return thisNode->value;
	}
	return -1;
}
// 
// 
// 
template<typename T1, typename T2>
hashNode<T1, T2> *  HashTable<T1, T2>::searchHelpFunc(hashNode<T1, T2> * thisNode, T1 searchKey)
{
	if (thisNode != NULL)	
	{
		std::cout<<thisNode->key <<":"<<thisNode->value <<"  ";
		if (thisNode->key == searchKey)
		{
			return thisNode;
		}
		else if (searchKey < thisNode->key)
		{
			HashTable<T1, T2>::searchHelpFunc(thisNode->child_left, searchKey);
		}
		else
		{
			HashTable<T1, T2>::searchHelpFunc(thisNode->child_right, searchKey);
		}
	}
	else
	{
		return NULL;
	}
}
// 
// 
// 
template<typename T1, typename T2>
void HashTable<T1, T2>::print()
{	
	for (int i = 0;  i < outerSize;  i++)
	{
		HashTable<T1, T2>::printHelpFunc(underVector[i]);
	}
}
// 
// 
// 
template<typename T1, typename T2>
void  HashTable<T1, T2>::printHelpFunc(hashNode<T1, T2> * thisNode)
{
	if (thisNode != NULL)	
	{
		HashTable<T1, T2>::printHelpFunc(thisNode->child_left);
		std::cout<<thisNode->key <<":"<<thisNode->value <<"  ";
		HashTable<T1, T2>::printHelpFunc(thisNode->child_right);
	}
}
// 
// 
// 
#endif
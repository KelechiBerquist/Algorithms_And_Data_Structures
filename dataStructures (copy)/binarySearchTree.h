#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "doubly_linked_list.h"
#include "diffNode.h"


template<typename T>
class BST
{
	private:
		int nodeHeight;
		DL_List <binNode<T> * > myQueue;

		binNode<T> * rootNode;
		binNode<T> * addHelpFunc(binNode<T> * oldNode, T newValue);
		void printPreOrderFunc(binNode<T> *oldPointer);
		void printInOrderFunc(binNode<T> *oldPointer);
		void printPostOrderFunc(binNode<T> *oldPointer);
		bool searchHelpFunc(DL_List <binNode<T> * > myQueue, T searchValue);
		void printBFTFunc(DL_List <binNode<T> * > myQueue);


		

	public:
		BST();
		void add(T newValue);
		bool search(T searchValue);
		void del(T value);
		void print();
		int height ();

	
		
};
// 
// 
//
template<typename T>
BST<T>::BST(void)
{
	BST<T>::rootNode =  NULL;
}
// 
// 
// 
//********* Find Node To Add Add Item******************//
template<typename T>
binNode<T> * BST<T>::addHelpFunc(binNode<T> * oldNode, T newValue)
{
	if ( newValue == oldNode->value)
	{
		return NULL;
	}

	else if ( newValue < oldNode->value)
	{
		if (oldNode->child_left == NULL)
		{
			return oldNode;
		}
		else
		{
			// std::cout<<"Search Left of: " <<oldNode->value <<";  \n";
			BST<T>::addHelpFunc(oldNode->child_left, newValue);
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
			BST<T>::addHelpFunc(oldNode->child_right, newValue);
		}
	}
}
// 
// 
// 
//********* Add Item To Tree In Found Node******************//
template<typename T>
void BST<T>::add(T newValue)
{
	binNode<T> * newNode    =  (binNode<T> *) std::malloc(sizeof(binNode<T>));
	newNode->value          =  newValue;
	
	if (BST<T>::rootNode == NULL)
	{
		BST<T>::rootNode         =  newNode;
		// std::cout<<"Root Node is Added: " <<BST<T>::rootNode->value <<"   \n";
	}
	else
	{
		binNode<T> * bottomNode  =  BST::addHelpFunc(BST<T>::rootNode, newValue);
		if (bottomNode != NULL)
		{
			newNode->parent         =  bottomNode;

			if (newValue < bottomNode->value)
			{			
				bottomNode->child_left   =  newNode;
				// std::cout<<"Left Node is Added to: "<<bottomNode->value <<" " <<newNode->value <<"   \n";
			}

			else if (newValue > bottomNode->value)
			{
				bottomNode->child_right   =  newNode;
				// std::cout<<"Right Node is Added to: "<<bottomNode->value <<" " <<newNode->value <<"   \n";
			}
		}
	}
}
// 
// 
// 
//********* Print BST ******************//
template<typename T>
bool BST<T>::searchHelpFunc(DL_List <binNode<T> * > myQueue, T searchValue)
{
	if (myQueue.size())
	{
		binNode<T> * thisNode = myQueue.pop();

		if (thisNode != NULL)	
		{
			std::cout<<thisNode->value <<"  ";
			if (thisNode->value == searchValue)
			{
				return true;
			}
			else if (searchValue < thisNode->value)
			{
				myQueue.push(thisNode->child_left);
			}
			else
			{
				myQueue.push(thisNode->child_right);
			}
			BST<T>::searchHelpFunc(myQueue, searchValue);	
		}
	}
	else
	{
		return false;
	}
}
// 
// 
// 
//********* Print BST ******************//
template<typename T>
bool BST<T>::search(T searchValue)
{
	myQueue.push(BST<T>::rootNode);
	bool truthValue = BST<T>::searchHelpFunc(myQueue, searchValue);

	return truthValue;
}
// 
// 
// 
// **************************************************//
// **************************************************//
// The methods for doing depth-first search are:
// // // pre-order - node, left-branch, right-branch
// // // in-order - left-branch, node, right-branch
// // // post-order - left-branch, right-branch, node
// **************************************************//
// **************************************************//
// 
// 
// 
//********* Print BST ******************//
template<typename T>
void BST<T>::print()
{
	printPreOrderFunc(BST<T>::rootNode);
	std::cout<<"  \n";
	std::cout<<"  \n";
	std::cout<<"  \n";
	printInOrderFunc(BST<T>::rootNode);
	std::cout<<"  \n";
	std::cout<<"  \n";
	std::cout<<"  \n";
	printPostOrderFunc(BST<T>::rootNode);
	std::cout<<"  \n";
	std::cout<<"  \n";
	std::cout<<"  \n";
	myQueue.push(BST<T>::rootNode);
	printBFTFunc(myQueue);
}
// 
// 
// 
//********* Helper Function for Printing BST******************//
template<typename T>
void BST<T>::printPreOrderFunc(binNode<T> *thisNode)
{
	if (thisNode != NULL)
	{
		std::cout <<thisNode->value<<"  ";
		printPreOrderFunc(thisNode->child_left);
		printPreOrderFunc(thisNode->child_right);
	}
}
// 
// 
// 
//********* Helper Function for Printing BST******************//
template<typename T>
void BST<T>::printInOrderFunc(binNode<T> *thisNode)
{
	if (thisNode != NULL)
	{
		printInOrderFunc(thisNode->child_left);
		std::cout <<thisNode->value<<"  ";
		printInOrderFunc(thisNode->child_right);
	}
}
// 
// 
// 
//********* Helper Function for Printing BST******************//
template<typename T>
void BST<T>::printPostOrderFunc(binNode<T> *thisNode)
{
	if (thisNode != NULL)
	{
		printInOrderFunc(thisNode->child_left);
		printInOrderFunc(thisNode->child_right);
		std::cout <<thisNode->value<<"  ";
	}
}
// 
// 
// 
//********* Print BFT ******************//
template<typename T>
void BST<T>::printBFTFunc(DL_List <binNode<T> * > myQueue)
{
	if (myQueue.size())
	{
		binNode<T> * thisNode = myQueue.pop();

		if (thisNode != NULL)	
		{
			std::cout<<thisNode->value <<"  ";
			myQueue.push(thisNode->child_left);
			myQueue.push(thisNode->child_right);	
		}
		BST<T>::printBFTFunc(myQueue);
	}
}
// 
// 
// 
#endif
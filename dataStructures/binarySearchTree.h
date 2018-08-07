#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "doubly_linked_list.h"

template<typename T>
class BST
{
	private:
		int nodeHeight;
		struct Node
		{
			T value;
			Node * parent      =   NULL;
			Node * child_left  =   NULL;
			Node * child_right =   NULL;
		};

		Node * rootNode;
		Node * preAdd(Node * oldNode, T newValue);
		void printPreOrderFunc(Node *oldPointer);
		void printInOrderFunc(Node *oldPointer);
		void printPostOrderFunc(Node *oldPointer);

		DL_List <Node * > myDL_List;
		bool visitBfs(DL_List <Node * > myDL_List, T searchValue);
		bool visitDfs(DL_List <Node * > myDL_List, T searchValue);


		

	public:
		BST();
		void add(T newValue);
		bool dfs(T searchValue);
		bool bfs(T searchValue);
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
	rootNode =  NULL;
}
// 
// 
// 
//********* Find Node To Add Add Item******************//
template<typename T>
typename BST<T>::Node* BST<T>::preAdd(BST::Node * oldNode, T newValue)
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
			BST<T>::preAdd(oldNode->child_left, newValue);
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
			BST<T>::preAdd(oldNode->child_right, newValue);
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
	if (rootNode == NULL)
	{
		rootNode         =  (BST::Node*) std::malloc(sizeof(BST::Node));
		rootNode->value  =  newValue;
		// std::cout<<"Root Node is Added: " <<rootNode->value <<"   \n";
	}
	else
	{
		BST::Node * bottomNode  =  BST::preAdd(rootNode, newValue);
		if (bottomNode != NULL)
		{
			BST::Node * newNode     =  (BST::Node*) std::malloc(sizeof(BST::Node));
			newNode->value          =  newValue;
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
void BST<T>::print()
{
	std::cout<<"  \n";
	std::cout<<"  \n";
	std::cout<<"  \n";
	printPreOrderFunc(rootNode);
	std::cout<<"  \n";
	std::cout<<"  \n";
	std::cout<<"  \n";
	printInOrderFunc(rootNode);
	std::cout<<"  \n";
	std::cout<<"  \n";
	std::cout<<"  \n";
	printPostOrderFunc(rootNode);
}
// 
// 
// 
//********* Helper Function for Printing BST******************//
template<typename T>
void BST<T>::printPreOrderFunc(BST::Node *thisNode)
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
void BST<T>::printInOrderFunc(BST::Node *thisNode)
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
void BST<T>::printPostOrderFunc(BST::Node *thisNode)
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
bool BST<T>::visitBfs(DL_List <BST::Node * > myDL_List, T searchValue)
{
	if (myDL_List.size())
	{
		BST<T>::Node * thisNode = myDL_List.pop();

		if (thisNode != NULL)	
		{
			std::cout<<thisNode->value <<"  ";
			if (thisNode->value == searchValue)
			{
				return true;
			}
			else if (searchValue < thisNode->value)
			{
				myDL_List.push(thisNode->child_left);
			}
			else
			{
				myDL_List.push(thisNode->child_right);
			}
			BST<T>::visitBfs(myDL_List, searchValue);	
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
bool BST<T>::bfs(T searchValue)
{
	myDL_List.push(rootNode);
	bool truthValue = BST<T>::visitBfs(myDL_List, searchValue);

	return truthValue;
}
// 
// 
// 
template<typename T>
bool BST<T>::visitDfs(DL_List <BST::Node * > myDL_List, T searchValue)
{
	if (myDL_List.size())
	{
		BST<T>::Node * thisNode = myDL_List.pop();

		if (thisNode != NULL)	
		{
			std::cout<<thisNode->value <<"  ";
			if (thisNode->value == searchValue)
			{
				return true;
			}
			else if (searchValue < thisNode->value)
			{
				myDL_List.push(thisNode->child_left);
			}
			else
			{
				myDL_List.push(thisNode->child_right);
			}
			BST<T>::visitDfs(myDL_List, searchValue);	
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
bool BST<T>::dfs(T searchValue)
{
	myDL_List.push(rootNode);
	bool truthValue = BST<T>::visitDfs(myDL_List, searchValue);

	return truthValue;
}
// 
// 
// 
#endif

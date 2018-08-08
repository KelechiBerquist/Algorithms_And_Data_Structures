#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// 
// 
// 
struct Node
{
	int value;
	Node * parent      =   NULL;
	Node * child_left  =   NULL;
	Node * child_right =   NULL;
};
// 
// 
// 
class BST
{
	public:
		BST();
		void add(int newValue);
		int search(int value);
		void del(int value);
		void print();
		int height ();

	private:
		Node * rootNode;
		Node * preAdd(Node * oldNode, int newValue);
		void printFuncDF(Node *oldPointer);
		void printFuncBF(Node *oldPointer);
};
// 
// 
//
BST::BST(void)
{
	rootNode =  NULL;
}
// 
// 
// 
//********* Find Node To Add Add Item******************//
Node* BST::preAdd(Node * oldNode, int newValue)
{
	if ( newValue < oldNode->value)
	{
		if (oldNode->child_left == NULL)
		{
			return oldNode;
		}
		else
		{
			std::cout<<"Search Left of: " <<oldNode->value <<";  \n";
			BST::preAdd(oldNode->child_left, newValue);
		}
	}


	else if ( newValue > oldNode->value)
	{
		if (oldNode->child_right == NULL)
		{
			return oldNode;
		}
		else
		{
			std::cout<<"Search Right of: " <<oldNode->value <<";  \n";
			BST::preAdd(oldNode->child_right, newValue);
		}
	}
}
// 
// 
// 
//********* Add Item To Tree In Found Node******************//
void BST::add(int newValue)
{
	if (rootNode == NULL)
	{
		rootNode         =  (Node*) malloc(sizeof(Node));
		rootNode->value  =  newValue;
		std::cout<<"Root Node is Added: " <<rootNode->value <<"   \n";
	}
	else
	{
		Node * bottomNode  =  BST::preAdd(rootNode, newValue);
		Node * newNode     =  (Node*) malloc(sizeof(Node));
		newNode->value     =  newValue;
		newNode->parent    =  bottomNode;

		if (newValue < bottomNode->value)
		{			
			bottomNode->child_left   =  newNode;
			std::cout<<"Left Node is Added to: "<<bottomNode->value <<" " <<newNode->value <<"   \n";
		}

		else
		{
			bottomNode->child_right   =  newNode;
			std::cout<<"Right Node is Added to: "<<bottomNode->value <<" " <<newNode->value <<"   \n";
		}
	}
	
}

// 
// 
// 
//********* Print BST ******************//
void BST::print()
{
	std::cout <<rootNode->value<<"  ";
	printFunc(rootNode->child_left);
	printFunc(rootNode->child_right);
}
// 
// 
// 
//********* Helper Function for Printing BST******************//
void BST::printFunc(Node *thisNode)
{
	if (thisNode != NULL)
	{
		std::cout <<thisNode->value<<"  ";
		printFunc(thisNode->child_left);
		printFunc(thisNode->child_right);
	}
}
#endif


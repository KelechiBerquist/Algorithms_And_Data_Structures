#ifndef TRIE_H
#define TRIE_H


class Trie
{
	public:
		const int  numChar = 26;
		Trie();
		void add(std::string newString);
		void print();
		// void add(std::string newString);

		


	private:
		struct Node
		{
			Node();
			int value;
			void *child_Node;
			// std::vector <Trie::Node *> *child_Node;
			// std::vector <Node *> *child_Node;
			// std::vector <Node *> child_Node = std::vector <Node *> (numChar, nullptr);
			bool isLeaf = false;
		};
		Node * rootNode;
		// Node *  createNode();
		void addHelpFunc(Trie::Node* thisNode, std::string newString, int i);
		void printHelpFunc(Trie::Node* thisNode, std::string Word);


};
// 
// 
// 
Trie::Trie()
{
	// Node::child_Node  =  (std::vector <Node *> *)::operator new (numChar*sizeof(Trie::Node));
	rootNode          =  new (Trie::Node);
	// rootNode = (Trie::Node*) new (numChar*sizeof(Trie::Node));
	// Node::child_Node = std::vector <Node *> (numChar, nullptr);
	// Trie::Node::child_Node(numChar, nullptr);
	// Trie::Node::child_Node = std::vector <Node *> (numChar, nullptr);
}
// 
// 
// 
Trie::Node::Node()
{
	// Node::child_Node  = (std::vector <Node *> *)::operator new (numChar*sizeof(Trie::Node));

	// Node::child_Node = new (numChar*sizeof(Trie::Node));
	// Node::child_Node = (std::vector <Trie::Node *> *) std::malloc(numChar*sizeof(Trie::Node));

	// Node::child_Node = (std::vector <Trie::Node *> *) std::malloc(numChar*sizeof(Trie::Node));
	// Node::child_Node = (std::vector <Trie::Node *> *) std::malloc(Trie::numChar*sizeof(Trie::Node));
	// Node::child_Node = (std::vector <Node *> *) malloc (sizeof (std::vector <Node *>(numChar, nullptr) ) );
}
// 
// 
// 
// Trie::Node * Trie::createNode()
// {
// 	Node newNode = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 	newNode->child_Node.resize(numChar);
// 	return newNode;
// }



// void Trie::add(std::string newString)
// {
// 	if (rootNode->child_Node[int(newString[0])-'a'] == NULL)
// 	{
// 		rootNode->child_Node[int(newString[0])-'a'] = (Trie::Node *) std::malloc(sizeof(Trie::Node));

// 		std::cout<<"Created Level " <<0 <<" for " <<newString  <<"\n";
// 	}
// 	Trie::addHelpFunc(rootNode->child_Node[int(newString[0])-'a' + 1], newString, 1);
// }
// // 
// // 
// // 
// void Trie::addHelpFunc(Trie::Node* thisNode, std::string newString, int i)
// {
// 	if (i < newString.size())
// 	{
// 		if (thisNode == NULL)
// 		{	thisNode = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 			thisNode->child_Node.resize(numChar);
// 			std::cout<<"Created Level " <<i <<" for " <<newString <<"\n";
// 		}

// 		Trie::addHelpFunc(thisNode->child_Node[int(newString[i+1])-'a'], newString, i+1);

// 		if (i == newString.size()-1)
// 		{
// 			thisNode->isLeaf = true;

// 			std::cout<<"End of " <<newString <<"\n";
// 		}
// 	}
// 	// if (i < newString.size() and thisNode->child_Node[int(newString[i])-'a'] == NULL)
// 	// {
// 	// 	thisNode->child_Node[int(newString[i])-'a'] = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 	// 	thisNode->child_Node.resize(numChar);

// 	// 	std::cout<<"Created Level " <<i <<" for " <<newString <<"\n";

// 	// 	Trie::addHelpFunc(thisNode->child_Node[int(newString[i])-'a' + 1], newString, i+1);

// 	// 	if (i == newString.size()-1)
// 	// 	{
// 	// 		thisNode->isLeaf = true;

// 	// 		std::cout<<"End of " <<newString <<"\n";
// 	// 	}
// 	// }
// }



// void Trie::print()
// {
// 	for (int i = 0;  i < Trie::numChar;  i++)
// 	{
// 		std::string Word = "";
// 		if(rootNode->child_Node[i] != NULL)
// 		{
			
// 			Word += char(i+'a');
// 			Trie::printHelpFunc(rootNode->child_Node[i], Word);
// 			// std::cout<<Word<<"  \n";
// 		}	
// 	}	
// }
// // 
// // 
// // 
// void Trie::printHelpFunc(Trie::Node* thisNode, std::string Word)
// {
// 	if(thisNode != NULL)
// 	{
// 		std::cout<<Word <<"  " <<thisNode->child_Node.size() <<"  \n";
// 		if (thisNode->isLeaf)
// 		{
// 			std::cout<<" | "<<Word<<"  \n";
// 		}

// 		for (int i = 0;  i < Trie::numChar;  i++)
// 		{
// 			if(thisNode->child_Node[i] != NULL)
// 			{
// 				std::cout<<Word<<"  \n";
// 				Word += char(i+'a');
// 				Trie::printHelpFunc(thisNode->child_Node[i], Word);
// 			}
// 		}
// 	}
// }

#endif





// class Trie
// {
// 	public:
// 		const int numChar = 26;
// 		Trie();
// 		void add(std::string newString);
// 		void print();
// 		// void add(std::string newString);


// 	private:
// 		struct Node
// 		{
// 			int value;
// 			Node* child_Node [Trie::numChar];
// 			bool isLeaf = false;
// 		};
// 		Node * rootNode;
// 		void addHelpFunc(Trie::Node* thisNode, std::string newString, int i);
// 		void printHelpFunc(Trie::Node* thisNode, std::string Word);


// };
// // 
// // 
// // 
// Trie::Trie()
// {
// 	rootNode = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// }
// // 
// // 
// // 
// void Trie::add(std::string newString)
// {
// 	if (rootNode->child_Node[int(newString[0])-'a'] == NULL)
// 	{
// 		rootNode->child_Node[int(newString[0])-'a'] = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 	}
// 	Trie::addHelpFunc(rootNode->child_Node[int(newString[1])-'a' + 1], newString, 1+1);
// }
// // 
// // 
// // 
// void Trie::addHelpFunc(Trie::Node* thisNode, std::string newString, int i)
// {
// 	if (i < newString.size() and thisNode->child_Node[int(newString[i])-'a'] == NULL)
// 	{
// 		thisNode->child_Node[int(newString[i])-'a'] = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 		// thisNode->child_Node.resize(numChar);

// 		Trie::addHelpFunc(thisNode->child_Node[int(newString[i])-'a' + 1], newString, i+1);

// 		if (i == newString.size()-1)
// 		{
// 			thisNode->isLeaf = true;
// 		}
// 	}
// }



// void Trie::print()
// {
// 	for (int i = 0;  i < Trie::numChar;  i++)
// 	{
// 		std::string Word = "";
// 		if(rootNode->child_Node[i] != NULL)
// 		{
// 			Word += char(i+'a');
// 			Trie::printHelpFunc(rootNode->child_Node[i], Word);
// 		}	
// 	}	
// }
// // 
// // 
// // 
// void Trie::printHelpFunc(Trie::Node* thisNode, std::string Word)
// {
// 	for (int i = 0;  i < Trie::numChar;  i++)
// 	{
// 		if(thisNode->child_Node[i] != NULL)
// 		{
// 			Word += char(i+'a');
// 			if (thisNode->isLeaf)
// 			{
// 				std::cout<<Word<<"  ";
// 			}
// 			Trie::printHelpFunc(thisNode->child_Node[i], Word);
// 		}
// 	}
// }


// ************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************ //

// class Trie
// {

// 	public:
		
// 		Trie();
// 		void add(std::string newString);
// 		void print();
// 		// void add(std::string newString);


// 	private:
// 		const int numChar = 26;
// 		struct Node
// 		{
// 			int value;
// 			// std::vector <Node*> child_Node;
// 			Node* child_Node [numChar];
// 			bool isLeaf = false;
// 		};
// 		Node * rootNode;
// 		void addHelpFunc(Trie::Node* thisNode, std::string newString, int i);
// 		void printHelpFunc(Trie::Node* thisNode, std::string Word);


// };
// // 
// // 
// // 
// Trie::Trie()
// {
// 	rootNode = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 	// rootNode->child_Node.resize(numChar);
// }
// // 
// // 
// // 
// void Trie::add(std::string newString)
// {
// 	if (rootNode->child_Node[int(newString[0])-'a'] == NULL)
// 	{
// 		rootNode->child_Node[int(newString[0])-'a'] = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 	}
// 	Trie::addHelpFunc(rootNode->child_Node[int(newString[1])-'a' + 1], newString, 1+1);
// }
// // 
// // 
// // 
// void Trie::addHelpFunc(Trie::Node* thisNode, std::string newString, int i)
// {
// 	if (i < newString.size() and thisNode->child_Node[int(newString[i])-'a'] == NULL)
// 	{
// 		thisNode->child_Node[int(newString[i])-'a'] = (Trie::Node *) std::malloc(sizeof(Trie::Node));
// 		// thisNode->child_Node.resize(numChar);

// 		Trie::addHelpFunc(thisNode->child_Node[int(newString[i])-'a' + 1], newString, i+1);

// 		if (i == newString.size()-1)
// 		{
// 			thisNode->isLeaf = true;
// 		}
// 	}
// }



// void Trie::print()
// {
// 	for (int i = 0;  i < rootNode->child_Node.size();  i++)
// 	{
// 		std::string Word = "";
// 		if(rootNode->child_Node[i] != NULL)
// 		{
// 			Word += char(i+'a');
// 			Trie::printHelpFunc(rootNode->child_Node[i], Word);
// 		}	
// 	}	
// }
// // 
// // 
// // 
// void Trie::printHelpFunc(Trie::Node* thisNode, std::string Word)
// {
// 	for (int i = 0;  i < thisNode->child_Node.size();  i++)
// 	{
// 		if(thisNode->child_Node[i] != NULL)
// 		{
// 			Word += char(i+'a');
// 			if (thisNode->isLeaf)
// 			{
// 				std::cout<<Word<<"  ";
// 			}
// 			Trie::printHelpFunc(thisNode->child_Node[i], Word);
// 		}
// 	}
// }
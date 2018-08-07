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
			// Node * makeNode();
			int value;
			Trie::Node **childNode;
			bool isLeaf = false;
		};
		Node * makeNode();
		Node * rootNode;
		// Node *  createNode();
		int *  createNodeArray();
		void addHelpFunc(Trie::Node* thisNode, std::string newString, int i);
		void printHelpFunc(Trie::Node* thisNode, std::string Word);


};
// 
// 
// 
Trie::Trie()
{
	rootNode    =  Trie::makeNode();
}
// 
// 
// 
Trie::Node * Trie::makeNode()
{
	Trie::Node * newNode  =  (Trie::Node *)  std::malloc(sizeof(Trie::Node));
	newNode->childNode    =  (Trie::Node **) std::malloc(26*sizeof(void *));
	
	return newNode;
}
// 
// 
// 
void Trie::add(std::string newString)
{
	Trie::addHelpFunc(rootNode, newString, 0);
}
// 
// 
// 
void Trie::addHelpFunc(Trie::Node* thisNode, std::string newString, int i)
{
	if (i < newString.size())
	{
		if (thisNode->childNode[int(newString[i])-'a'] == NULL)
		{	
			Trie::Node *  newNode                        =  Trie::makeNode();
			thisNode->childNode[int(newString[i])-'a']   =  newNode;
			// std::cout<<"Created Level " <<i <<" for " <<newString <<"\n";
		}

		Trie::Node *  thatNode  = thisNode->childNode[int(newString[i])-'a'];
		Trie::addHelpFunc(thatNode, newString, i+1);
	}

	if (i == newString.size())
	{
		thisNode->isLeaf = true;

		// std::cout<<"End of " <<newString <<"\n";
	}
}
// 
// 
// 
void Trie::print()
{
	for (int i = 0;  i < Trie::numChar;  i++)
	{
		
		if(rootNode->childNode[i] != NULL)
		{
			std::string Word = "";
			Trie::printHelpFunc(rootNode, Word);
		}	
	}	
}
// 
// 
// 
void Trie::printHelpFunc(Trie::Node* thisNode, std::string Word)
{
	std::string newWord;
	if(thisNode != NULL)
	{
		if (thisNode->isLeaf)
		{
			std::cout<<" "<<Word<<"  ";
		}

		for (int i = 0;  i < Trie::numChar;  i++)
		{
			if(thisNode->childNode[i] != NULL)
			{
				newWord = Word + char(i+'a');
				Trie::Node *  thatNode  = thisNode->childNode[i];
				Trie::printHelpFunc(thatNode, newWord);
			}
		}
		
	}
	else
	{
		Word = "";
	}
}
#endif
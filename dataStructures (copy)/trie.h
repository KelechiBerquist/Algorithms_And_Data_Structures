#ifndef TRIE_H
#define TRIE_H

#include "diffNode.h"

template <typename T>
class Trie
{
	public:
		const int  numChar = 26;
		Trie();
		void add(std::string newString);
		void print();

		


	private:
		trieNode<T> * makeNode();
		trieNode<T> * rootNode;
		int *  createNodeArray();
		void addHelpFunc(trieNode<T> * thisNode, std::string newString, int i);
		void printHelpFunc(trieNode<T> * thisNode, std::string Word);
};
// 
// 
// 
template <typename T>
Trie<T>::Trie()
{
	Trie<T>::rootNode    =  Trie<T>::makeNode();
}
// 
// 
// 
template <typename T>
trieNode<T> * Trie<T>::makeNode()
// typename trieNode<T> * Trie<T>::makeNode()
{
	trieNode<T> * newNode  =  (trieNode<T> *)  std::malloc(sizeof(trieNode<T>));
	newNode->childNode    =  (trieNode<T> **) std::malloc(numChar*sizeof(void *));
	
	return newNode;
}
// 
// 
// 
template <typename T>
void Trie<T>::add(std::string newString)
{
	Trie<T>::addHelpFunc(Trie<T>::rootNode, newString, 0);
}
// 
// 
// 
template <typename T>
void Trie<T>::addHelpFunc(trieNode<T> * thisNode, std::string newString, int i)
{
	if (i < newString.size())
	{
		if (thisNode->childNode[int(newString[i])-'a'] == NULL)
		{	
			trieNode<T> *  newNode                        =  Trie<T>::makeNode();
			thisNode->childNode[int(newString[i])-'a']   =  newNode;
			// std::cout<<"Created Level " <<i <<" for " <<newString <<"\n";
		}

		trieNode<T> *  thatNode  = thisNode->childNode[int(newString[i])-'a'];
		Trie<T>::addHelpFunc(thatNode, newString, i+1);
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
template <typename T>
void Trie<T>::print()
{
	std::string Word = "";
	Trie<T>::printHelpFunc(Trie<T>::rootNode, Word);
}
// 
// 
// 
template <typename T>
void Trie<T>::printHelpFunc(trieNode<T> * thisNode, std::string Word)
{
	std::string newWord;
	if(thisNode != NULL)
	{
		if (thisNode->isLeaf)
		{
			std::cout<<" "<<Word<<"  ";
		}

		for (int i = 0;  i < Trie<T>::numChar;  i++)
		{
			if(thisNode->childNode[i] != NULL)
			{
				newWord = Word + char(i+'a');
				trieNode<T> *  thatNode  = thisNode->childNode[i];
				Trie<T>::printHelpFunc(thatNode, newWord);
			}
		}
	}
}
#endif
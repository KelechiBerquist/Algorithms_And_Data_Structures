#ifndef DIFF_NODE_H
#define DIFF_NODE_H

template <typename T>
struct trieNode
{
	T value;
	trieNode **childNode;
	bool isLeaf = false;
};


template <typename T>
struct binNode
{
	T value;
	Node * child_left  =   NULL;
	Node * child_right =   NULL;
};

#endif
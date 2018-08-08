#ifndef DIFF_NODE_H
#define DIFF_NODE_H

template <typename T>
struct trieNode
{
	T value;
	trieNode <T> **childNode;
	bool isLeaf = false;
};


template <typename T>
struct binNode
{
	T value;
	binNode <T> * parent      =   NULL;
	binNode <T> * child_left  =   NULL;
	binNode <T> * child_right =   NULL;
};

#endif
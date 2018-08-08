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


template <typename T1, typename T2>
struct hashNode
{
	T1 key;
	T2 value;
	hashNode <T1, T2> * parent      =   NULL;
	hashNode <T1, T2> * child_left  =   NULL;
	hashNode <T1, T2> * child_right =   NULL;
};



#endif
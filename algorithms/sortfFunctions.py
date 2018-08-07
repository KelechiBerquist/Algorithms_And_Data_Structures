import numpy as np


def Heapify (ArrayToSort):
	

	return ArrayToSort
# 
# 
# 
def HeapSort (ArrayToSort):
	

	return ArrayToSort
# 
# 
# 
def BubbleSort (ArrayToSort):
	SortedArray = []
	
	for i in range (len(ArrayToSort)):
		for j in range(i+1, len(ArrayToSort)):
			if (ArrayToSort[i] < ArrayToSort[j]):
				continue
			else:
				temp1 = ArrayToSort[i]
				ArrayToSort[i] = ArrayToSort[j] 
				ArrayToSort[j] = temp1

	return ArrayToSort
# 
# 
# 
def InsertionSort (ArrayToSort):
	

	return ArrayToSort
# 
# 
# 
def MergeSort(toSort):
	if len(toSort) < 2:
		return toSort

	RHS = mergeSort(toSort[:math.ceil(len(toSort)/2)])
	LHS = mergeSort(toSort[math.ceil(len(toSort)/2):])
	
	sL = []
	while len(LHS) and len(RHS):
		if LHS[0] < RHS[0]:
			sL.append(LHS.pop(0))
		else:
			sL.append(RHS.pop(0))
	sL.extend(LHS)
	sL.extend(RHS)
	# print (sL)
	return sL
# 
# 
# 
def QuickSort (ArrayToSort):
	

	return ArrayToSort


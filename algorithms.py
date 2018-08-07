# BubbleSort.py

import numpy as np
import math
import sortfFunctions as sortFunctions


ArrayToSort       =   np.array([])
l                 =   0
m                 =   0


def CreateArray ():
	l = int (input("Enter highest number in array to be sorted: "))
	m = int (input("Enter number of columns array to be sorted: "))

	global ArrayToSort
	ArrayToSort = np.random.randint(l, size=m)
	ArrayToSort = ArrayToSort.tolist()



CreateArray ()
print(ArrayToSort)
SortedArray = sortFunctions.BubbleSort(ArrayToSort)
print(SortedArray)
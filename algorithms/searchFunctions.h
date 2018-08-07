#ifndef SEARCHFUNCTIONS_H
#define SEARCHFUNCTIONS_H


//********************Function Prototypes********************
int BinarySearch (std::vector <int> ThisArray, int number);
std::vector <int> HeapSort (std::vector <int> ThisArray);
std::vector <int> BubbleSort (std::vector <int> ThisArray);
std::vector <int> InsertionSort (std::vector <int> ThisArray);
std::list   <int> InsertionSortList (std::list <int> ThisArray);
std::vector <int> MergeSort (std::vector <int> SortArray);
std::vector <int> QuickSort (std::vector <int> ThisArray);
#endif
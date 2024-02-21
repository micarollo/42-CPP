#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>

class PmergeMe
{
private:
public:
    void merge(std::vector<int> &arr, int left, int middle, int right);
    void mergeSort(std::vector<int> &arr, int left, int right);
    void printArray(const std::vector<int> &arr);
    void merge(std::list<int> &arr, std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
    void mergeSort(std::list<int> &arr, std::list<int>::iterator left, std::list<int>::iterator right);
    void printList(const std::list<int> &arr);
};
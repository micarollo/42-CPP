#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>

class PmergeMe
{
private:
public:
    PmergeMe();
    ~PmergeMe();
    void mergeVector(std::vector<int> &arr, int left, int middle, int right);
    void mergeSortVector(std::vector<int> &arr, int left, int right);
    // void mergeList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
    // void mergeSortList(std::list<int> &arr, std::list<int>::iterator left, std::list<int>::iterator right);
    void printVector(const std::vector<int> &arr);
    void printList(const std::list<int> &arr);

    std::list<int> insertSortlist( std::list<int> list );
    std::list<int> mergeList( std::list<int> left, std::list<int> right );
    // std::list<int> insertSortList(std::list<int> list);
    std::vector<int> insertSortVector( std::vector<int> vector );
    std::vector<int> mergeVector( std::vector<int> left, std::vector<int> right );
    // std::vector<int> insertSortVector( std::vector<int> vector );
};
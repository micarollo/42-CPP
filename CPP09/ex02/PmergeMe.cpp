#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeVector(std::vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSortVector(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        if (middle - left + 1 <= 10)
        {
            for (int i = left + 1; i <= right; i++)
            {
                int key = arr[i];
                int j = i - 1;
                while (j >= left && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
        else
        {
            mergeSortVector(arr, left, middle);
            mergeSortVector(arr, middle + 1, right);
            mergeVector(arr, left, middle, right);
        }
    }
}

void PmergeMe::mergeList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
{
    std::list<int> l(left, middle);
    std::list<int> r(middle, right);

    std::list<int>::iterator it = left;

    while (!l.empty() && !r.empty())
    {
        if (l.front() <= r.front())
        {
            *it = l.front();
            l.pop_front();
        }
        else
        {
            *it = r.front();
            r.pop_front();
        }
        ++it;
    }

    while (!l.empty())
    {
        *it = l.front();
        l.pop_front();
        ++it;
    }

    while (!r.empty())
    {
        *it = r.front();
        r.pop_front();
        ++it;
    }
}

void PmergeMe::mergeSortList(std::list<int> &arr, std::list<int>::iterator left, std::list<int>::iterator right)
{
    if (distance(left, right) > 1)
    {
        std::list<int>::iterator middle = left;
        advance(middle, distance(left, right) / 2);

        if (distance(left, middle) <= 10)
        {
            for (std::list<int>::iterator i = next(left); i != right; ++i)
            {
                int key = *i;
                std::list<int>::iterator j = prev(i);
                while (j != prev(left) && *j > key)
                {
                    *next(j) = *j;
                    --j;
                }
                *next(j) = key;
            }
        }
        else
        {
            mergeSortList(arr, left, middle);
            mergeSortList(arr, middle, right);
            mergeList(left, middle, right);
        }
    }
}

void PmergeMe::printVector(const std::vector<int> &arr)
{
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList(const std::list<int> &arr)
{
    for (std::list<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
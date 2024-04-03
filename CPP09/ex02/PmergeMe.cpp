#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

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

std::list<int> PmergeMe::mergeList(std::list<int> left, std::list<int> right)
{
	std::list<int> mergedList;
	std::list<int>::iterator l, r;

	l = left.begin();
	r = right.begin();

	while (l != left.end() && r != right.end())
	{
		if (*l < *r)
		{
			mergedList.insert(mergedList.end(), *l);
			l++;
		}
		else
		{
			mergedList.insert(mergedList.end(), *r);
			r++;
		}
	}
	mergedList.insert(mergedList.end(), l, left.end());
	mergedList.insert(mergedList.end(), r, right.end());

	return mergedList;
}

std::list<int> PmergeMe::insertSortlist(std::list<int> list)
{
	if (list.size() <= 10)
	{
		std::list<int>::iterator it, j;

		for (it = std::next(list.begin(), 1); it != list.end(); ++it)
		{
			int key = *it;
			j = it;

			while (j != list.begin() && *std::prev(j) > key)
			{
				*j = *(std::prev(j));
				--j;
			}
			*j = key;
		}
		return list;
	}
	else
	{
		unsigned long mid = list.size() / 2;
		std::list<int> left(list.begin(), std::next(list.begin(), mid));
		std::list<int> right(std::next(list.begin(), mid), list.end());

		return (mergeList(insertSortlist(left), insertSortlist(right)));
	}
}

std::vector<int> PmergeMe::mergeVector(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> mergedVector;
	std::vector<int>::iterator l, r;

	l = left.begin();
	r = right.begin();

	while (l != left.end() && r != right.end())
	{
		if (*l < *r)
		{
			mergedVector.push_back(*l);
			l++;
		}
		else
		{
			mergedVector.push_back(*r);
			r++;
		}
	}
	mergedVector.insert(mergedVector.end(), l, left.end());
	mergedVector.insert(mergedVector.end(), r, right.end());

	return mergedVector;
}

std::vector<int> PmergeMe::insertSortVector(std::vector<int> v)
{
	if (v.size() <= 10)
	{
		for (unsigned long i = 1; i < v.size(); i++)
		{
			int key = v[i];
			int j = i - 1;
			while (j > -1 && v[j] > key)
			{
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = key;
		}
		return v;
	}
	else
	{
		unsigned long mid = v.size() / 2;
		std::vector<int> left(v.begin(), v.begin() + mid);
		std::vector<int> right(v.begin() + mid, v.end());

		return mergeVector(insertSortVector(left), insertSortVector(right));
	}
}
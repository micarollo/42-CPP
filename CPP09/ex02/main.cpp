#include "PmergeMe.hpp"
// #include <iostream>
// #include <vector>
// #include <list>
// #include <cstdlib>
#include <ctime>

// void mergeVector(std::vector<int> &arr, int left, int middle, int right)
// {
//     int n1 = middle - left + 1;
//     int n2 = right - middle;

//     std::vector<int> L(n1), R(n2);

//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[middle + 1 + j];

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j])
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1)
//     {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2)
//     {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSortVector(std::vector<int> &arr, int left, int right)
// {
//     if (left < right)
//     {
//         int middle = left + (right - left) / 2;

//         if (middle - left + 1 <= 10)
//         {
//             for (int i = left + 1; i <= right; i++)
//             {
//                 int key = arr[i];
//                 int j = i - 1;
//                 while (j >= left && arr[j] > key)
//                 {
//                     arr[j + 1] = arr[j];
//                     j--;
//                 }
//                 arr[j + 1] = key;
//             }
//         }
//         else
//         {
//             mergeSortVector(arr, left, middle);
//             mergeSortVector(arr, middle + 1, right);
//             mergeVector(arr, left, middle, right);
//         }
//     }
// }

// void mergeList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
// {
//     std::list<int> l(left, middle);
//     std::list<int> r(middle, right);

//     std::list<int>::iterator it = left;

//     while (!l.empty() && !r.empty())
//     {
//         if (l.front() <= r.front())
//         {
//             *it = l.front();
//             l.pop_front();
//         }
//         else
//         {
//             *it = r.front();
//             r.pop_front();
//         }
//         ++it;
//     }

//     while (!l.empty())
//     {
//         *it = l.front();
//         l.pop_front();
//         ++it;
//     }

//     while (!r.empty())
//     {
//         *it = r.front();
//         r.pop_front();
//         ++it;
//     }
// }

// void mergeSortList(std::list<int> &arr, std::list<int>::iterator left, std::list<int>::iterator right)
// {
//     if (distance(left, right) > 1)
//     {
//         std::list<int>::iterator middle = left;
//         advance(middle, distance(left, right) / 2);

//         if (distance(left, middle) <= 10)
//         {
//             for (std::list<int>::iterator i = next(left); i != right; ++i)
//             {
//                 int key = *i;
//                 std::list<int>::iterator j = prev(i);
//                 while (j != prev(left) && *j > key)
//                 {
//                     *next(j) = *j;
//                     --j;
//                 }
//                 *next(j) = key;
//             }
//         }
//         else
//         {
//             mergeSortList(arr, left, middle);
//             mergeSortList(arr, middle, right);
//             mergeList(left, middle, right);
//         }
//     }
// }

// void printVector(const std::vector<int> &arr)
// {
//     for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// void printList(const std::list<int> &arr)
// {
//     for (std::list<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
        return 1;
    }

    std::vector<int> arrVector;
    std::list<int> arrList;
    PmergeMe p;

    // Parse the input sequence and populate both vector and list
    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);
        if (num <= 0)
        {
            std::cerr << "Error: Input sequence must contain only positive integers." << std::endl;
            return 1;
        }
        arrVector.push_back(num);
        arrList.push_back(num);
    }

    // Measure time for sorting using vector
    clock_t startVector = clock();
    p.mergeSortVector(arrVector, 0, arrVector.size() - 1);
    clock_t endVector = clock();
    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;

    // Measure time for sorting using list
    clock_t startList = clock();
    p.mergeSortList(arrList, arrList.begin(), --arrList.end());
    clock_t endList = clock();
    double listTime = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000;

    // Print sorted sequences
    std::cout << "Sorted sequence using vector: ";
    p.printVector(arrVector);
    std::cout << "Sorted sequence using list: ";
    p.printList(arrList);

    // Print time comparisons
    std::cout << "Time taken to sort using vector: " << vectorTime << " seconds" << std::endl;
    std::cout << "Time taken to sort using list: " << listTime << " seconds" << std::endl;

    return 0;
}

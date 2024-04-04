#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
        return 1;
    }

    std::vector<int> arrVector;
    std::list<int> arrList;
    std::list<int> listSorted;
    std::vector<int> vecSorted;
    PmergeMe p;

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

    // Measure time vector
    clock_t startVector = clock();
    vecSorted = p.insertSortVector(arrVector);
    clock_t endVector = clock();
    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;

    //Measure time list
    clock_t startList = clock();
    listSorted = p.insertSortlist(arrList);
    clock_t endList = clock();
    double listTime = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000;

    // Print before after
    std::cout << "Before: ";
    p.printVector(arrVector);
    std::cout << "After: ";
    p.printVector(vecSorted);

    // Print time
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << vectorTime << " seconds" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << listTime << " seconds" << std::endl;

    return 0;
}

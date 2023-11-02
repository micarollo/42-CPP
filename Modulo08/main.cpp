#include "easyfind.hpp"
#include <vector>

int main()
{
     try
    {
   std::vector<int> vec;
   vec.push_back(24);
   vec.push_back(42);
   vec.push_back(20);
   vec.push_back(13);
   vec.push_back(2);
   std::vector<int>::iterator it = easyfind(vec,-8);     
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
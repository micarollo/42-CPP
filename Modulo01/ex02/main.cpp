#include <iostream>
#include <string>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string &stringREF = s;
    std::string *stringPTR = &s;

    std::cout << "string adress: " << &s << std::endl;
    std::cout << "stringREF adress: " << &stringREF << std::endl;
    std::cout << "stringPTR adress: " << &stringPTR << std::endl;

    std::cout << "string value: " << s << std::endl;
    std::cout << "stringREF value: " << stringREF << std::endl;
    std::cout << "stringPTR value: " << *stringPTR << std::endl;
}
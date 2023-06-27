#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc != 4)
        std::cout << "usage: programm filename s1 s2" << std::endl;
    else
    {
        filename = argv[1];
        s1 = argv[2];
        s2 = argv[3];
        std::ifstream input(filename);
        if (!input)
            std::cerr << "Invalid filename" << std::endl;
        if (s1 == "" || s2 == "")
            std::cerr << "Cant work with empty input" << std::endl;
        std::ofstream output(filename + ".replace");
    }
}
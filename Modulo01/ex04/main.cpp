#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::string line;
    size_t pos;

    if (argc != 4)
        std::cout << "usage: <program> <filename> <s1> <s2>" << std::endl;
    else
    {
        filename = argv[1];
        s1 = argv[2];
        s2 = argv[3];
        std::ifdcstream input(filename);
        if (!input)
        {
            std::cerr << "Invalid filename" << std::endl;
            return (0);
        }
        if (s1 == "" || s2 == "")
            std::cerr << "Cant work with empty input" << std::endl;
        std::ofstream output(filename + ".replace");
        if (!output)
            std::cerr << "Cant open output file" << std::endl;
        while (std::getline(input, line))
        {
            pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
                pos += s2.length();
            }
            output << line << std::endl;
        }
        input.close();
        output.close();
    }
}
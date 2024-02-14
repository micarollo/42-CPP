#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;
    std::string _input;

public:
    BitcoinExchange(std::string file, std::string input);
    ~BitcoinExchange();
    void loadData(std::string const & csvFile);
    void findDate();

};
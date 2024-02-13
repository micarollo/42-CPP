#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;

public:
    BitcoinExchange(std::string file);
    ~BitcoinExchange();
    void loadData(std::string const & csvFile);
    // float getBitcoinValue(std::string const & date);
};
#include "BitcoinExchange.hpp"

static void checkDate(std::string date);

BitcoinExchange::BitcoinExchange(std::string file) 
{
    loadData(file);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(std::string const & csvFile) 
{
    std::ifstream file(csvFile);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Unable to open bitcoin data file." << std::endl;
        exit(1);
    }
    std::string line;
    while (getline(file, line)) 
    {
        std::cout << line << std::endl;
        std::string date = line.substr(0, line.find(","));
        std::cout << date << std::endl;
        checkDate(date);
        // std::string value = line.erase(0, line.find(",") + 1);
        std::string value = line.substr(line.find(",") + 1);
        std::cout << value << std::endl;
        _data[date] = stof(value);
    }
    file.close();
}

static void checkDate(std::string date)
{
    if (date.length() != 10)
        std::cout << "error lenght" << std::endl;
    for(size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-' || isdigit(date[i]))
            continue;
        else
            std::cout << "error digit" << std::endl;
    }
    std::string year = date.substr(0, date.find("-"));
    std::cout << year << std::endl;
    std::string month = date.substr(5, 2);
    std::cout << month << std::endl;
    std::string day = date.substr(8, 2);
    std::cout << day << std::endl;
    // int yy = stoi(year);
    int mm = stoi(month);
    int dd = stoi(day);
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31)
        std::cout << "error mes o dia" << std::endl;
    else if ((mm == 2) && (dd > 29))
        std::cout << "error febrero" << std::endl;
    else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd > 30))
        std::cout << "error meses 30 dias" << std::endl;
    else if (year.length() < 4)
        std::cout << "error year" << std::endl;
}

// float BitcoinExchange::getBitcoinValue(std::string const & date)
// {
//     std::map<std::string, float>::iterator it = _data.find(date);
//     if (it != _data.end())
//         return it->second;
//     return -1; // Indicate no data found
// }
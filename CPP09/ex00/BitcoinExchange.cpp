#include "BitcoinExchange.hpp"

static void checkDate(std::string date);
static float getNum(std::map<std::string, float> data, std::string fecha);

BitcoinExchange::BitcoinExchange(std::string file, std::string input) : _input(input)
{
    loadData(file);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(std::string const & csvFile) 
{
    std::ifstream file(csvFile);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Unable to open data file." << std::endl;
        exit(1);
    }
    std::string firstLine;
    std::string line;
    getline(file, firstLine);
    // std::cout << firstLine << std::endl;
    while (getline(file, line)) 
    {
        // std::cout << line << std::endl;
        std::string date = line.substr(0, line.find(","));
        // std::cout << date << std::endl;
        checkDate(date);
        std::string value = line.substr(line.find(",") + 1);
        // std::cout << value << std::endl;
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
    // std::cout << year << std::endl;
    std::string month = date.substr(5, 2);
    // std::cout << month << std::endl;
    std::string day = date.substr(8, 2);
    // std::cout << day << std::endl;
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

void BitcoinExchange::findDate()
{
    std::ifstream file(_input);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Unable to open input file." << std::endl;
        exit(1);
    }
    std::string firstLine;
    std::string line;
    getline(file, firstLine);
    // std::cout << firstLine << std::endl;
    while (getline(file, line))
    {
        // std::cout << line << std::endl;
        std::string date = line.substr(0, line.find(" | "));
        std::cout << date << std::endl;
        checkDate(date);
        std::string value = line.substr(line.find(" | ") + 1);
        // std::cout << value << std::endl;
        // float n = stof(value);
        // std::cout << n << std::endl;
        float result = getNum(_data, date);
        std::cout << result << std::endl;
    }
    file.close();
}

static float getNum(std::map<std::string, float> data, std::string date) 
{
    std::map<std::string, float>::iterator it = data.lower_bound(date);
    
    if (it == data.begin() || it == data.end()) 
    {
        return 0.0f;
    } 
    else if (it->first == date) 
    {
        return it->second;
    } 
    else 
    {
        --it;
        return it->second;
    }
}
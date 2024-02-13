#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2 && !argv[1])
        std::cout << "Usage: ./btc <input.txt>" << std::endl;
    else
        BitcoinExchange btc("data copy.csv");   
}
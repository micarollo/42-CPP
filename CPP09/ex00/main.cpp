#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2)
        std::cout << "Usage: ./btc <input.txt>" << std::endl;
    else
    {
        BitcoinExchange btc("data.csv", argv[1]);  
        btc.findDate();
    }
}
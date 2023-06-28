#include "Harl.hpp"

int option(std::string option)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (option == levels[i])
            return (i);
    }
    return (4);
}

int main(int argc, char *argv[])
{
    Harl ha;

    if (argc == 1 || argc > 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }
    else
    {
        switch (option(argv[1]))
        {
            case 0:
                ha.complain("DEBUG");
                break;
            case 1:
                ha.complain("INFO");
                break;
            case 2:
                ha.complain("WARNING");
                break;
            case 3:
                ha.complain("ERROR");
                break ;
            default :
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
                break ;
        }
    }
    return (0);
}
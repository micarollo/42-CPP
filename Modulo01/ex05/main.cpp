#include "Harl.hpp"

int main(void)
{
    Harl ha;

    ha.complain("DEBUG");
    ha.complain("ERROR");
    ha.complain("INFO");
    ha.complain("WARNING");
    ha.complain("ERROR");
    ha.complain("ERROR");
}
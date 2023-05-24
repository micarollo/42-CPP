#include "Contact.hpp"

class Phonebook {
private:
    Contact contacts[8];
    int     count;

public:
    void    Phonebook::set_num(int num);
    int     Phonebook::get_num(void);
    void	Phonebook::add_contact();
    void	Phonebook::search();
};
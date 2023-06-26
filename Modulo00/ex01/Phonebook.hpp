#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook {
private:
    Contact contacts[8];
    int     count;

public:
    Phonebook (void);
    ~Phonebook (void);
    void    set_num(int num);
    int     get_num(void);
    void	add_contact();
    void    displayContacts(int i);
    void	search();
};
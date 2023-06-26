#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook {
private:
    Contact contacts[8];
    int     count;
    int     total;

public:
    Phonebook (void);
    ~Phonebook (void);
    void    set_num(int num);
    int     get_num(void);
    void    set_total(int total);
    int     get_total(void);
    void	add_contact();
    void    displayContacts();
    void    searchContact(int i);
    int	    search();
};
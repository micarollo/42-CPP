#include "Contact.hpp"

class Phonebook {
private:
    Contact contacts[8];
    int     count;

public:
    void    set_num(int num);
    int     get_num(void);
    void	add_contact();
    void    displayContacts();
    void	search();
};
#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
      Contact _contacts[8];
      static int _nbContact;

  public:
    void add(void);
    void search(void);
    void print(int i);

    static int getNbContact(void);


};


#endif

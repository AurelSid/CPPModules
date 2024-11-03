#ifndef PHONE_H
  #define PHONE_H

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
class Phonebook
{
  public:
    Phonebook() : latest_index(0) {}
    void add_new_contact(void);
    void get_contact(void);

  private:
    Contact contacts_array[8];
    int latest_index;
};

#endif

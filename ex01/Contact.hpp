#ifndef CONTACT_H
#define CONTACT_H

#include "Contact.hpp"
#include <iostream>

class Contact
{
    private:

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;
    int number;
         
    public:
    Contact() {}
    Contact(std::string first_name, std::string last_name, std::string nickname, std::string num, std::string secret){};

    void add_contact_first_name(std::string first_name);
    void add_contact_last_name(std::string last_name);
    void add_contact_nickname(std::string nickanme);
    void add_contact_phone(int number);
    void add_contact_secret(std::string secret);
};

#endif

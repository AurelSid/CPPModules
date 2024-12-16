#include "Contact.hpp"
#include "Phonebook.hpp"

void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;

}
void Contact::set_nickname(std::string nickanme)
{
    this->nickname = nickanme;

}
void Contact::set_phone(std::string number)
{
    this->number = number;

}
void Contact::set_secret(std::string secret)
{
    this->secret = secret;

}

std::string		Contact::get_first_name() const { return this->first_name;}
std::string     Contact::get_last_name() const { return this->last_name; }
std::string		Contact::get_nickname() const { return this->nickname; }
std::string	    Contact::get_phone() const { return this->number; }
std::string		Contact::get_secret() const { return this->secret; }
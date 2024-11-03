#include "Contact.hpp"
#include "Phonebook.hpp"

void Phonebook::add_new_contact(std::string infos[8])
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string secret;
    int phone;

    if(this->latest_index == 8)
        this->latest_index == 0;
}
void Phonebook::get_contact(int index)
{

}
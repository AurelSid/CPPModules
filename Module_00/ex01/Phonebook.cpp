/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:14:03 by roko              #+#    #+#             */
/*   Updated: 2024/11/03 19:16:45 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

void Phonebook::add_new_contact()
{
    std::string data[5];
    
    Contact new_contact;

    if(this->latest_index == 8)
        this->latest_index = 0;
    this->contacts_array[latest_index] = new_contact;
    
    std::cout << "Please enter a first name:" << std::endl;
    std::getline(std::cin, data[latest_index]);
    this->contacts_array[latest_index].set_first_name(data[latest_index]);
    
    std::cout << "Please enter a last name:" << std::endl;
    std::getline(std::cin, data[1]);
    this->contacts_array[latest_index].set_last_name(data[1]);

    std::cout << "Please enter a nickname:" << std::endl;
    std::getline(std::cin, data[2]);
    this->contacts_array[latest_index].set_nickname(data[2]);

    std::cout << "Please enter a phone number:" << std::endl;
    std::getline(std::cin, data[3]);
    this->contacts_array[latest_index].set_phone(data[3]);
    
    std::cout << "Please enter a secret:" << std::endl;
    std::getline(std::cin, data[4]);
    this->contacts_array[latest_index].set_secret(data[4]);

    this->latest_index++;
}

void Phonebook::get_contact()
{
    
    std::string first_name;
    std::string last_name;
    std::string nickname;
    int index;

    index = 0;
    std::string input;
    int search_index;
    
    search_index = 0;
    std::cout << std::right << std::setw(10) << "Index" 
              << "|" << std::setw(10) << "First Name" 
              << "|" << std::setw(10) << "Last Name" 
              << "|" << std::setw(10) << "Nickname" 
              << std::endl;
    
    std::cout << std::string(45, '-') << std::endl; 

    while(index < 8)
    {
        first_name = this->contacts_array[index].get_first_name();
        last_name = this->contacts_array[index].get_last_name();
        nickname = this->contacts_array[index].get_nickname();
        
        if(first_name.length() > 10)
            first_name = first_name.substr(0,9) + ".";
        if(last_name.length() > 10)
            last_name = last_name.substr(0,9) + ".";
        if(nickname.length() > 10)
            nickname = nickname.substr(0,9) + ".";
        
        if(this->contacts_array[index].get_first_name().size() > 0)
        {
            std::cout << std::right << std::setw(10) << index;
            std::cout << "|" ;
            std::cout << std::right << std::setw(10) << first_name;
            std::cout << "|" ;
            std::cout << std::right << std::setw(10) << last_name;
            std::cout << "|" ;
            std::cout << std::right << std::setw(10) << nickname;
            std::cout << "|" ;
            std::cout << std::endl;
        }
        index++;
    }
    std::cout << "ENTER A CONTACT INDEX FOR DETAILS..." << std::endl;
    std::getline(std::cin, input);
    if(input.size() == 0)
        search_index = -1;
    else 
        search_index = std::stoi(input);
    if(search_index > 8 || search_index < 0 
    || this->contacts_array[search_index].get_first_name().size() == 0 )
     {
        std::cout << std::endl;
        std::cout << "UNVALID INDEX..BACK TO MENU..." << std::endl << std::endl;
        std::cout << std::endl;
        sleep(1);
        return;
     }
     else
     {
        std::cout << std::right << std::setw(10) << search_index;
        std::cout << "|" ;
        std::cout << std::right << std::setw(10) << this->contacts_array[search_index].get_first_name();
        std::cout << "|" ;
        std::cout << std::right << std::setw(10) << this->contacts_array[search_index].get_last_name();
        std::cout << "|" ;
        std::cout << std::right << std::setw(10) << this->contacts_array[search_index].get_nickname();
        std::cout << "|" ;
        std::cout << std::right << std::setw(10) << this->contacts_array[search_index].get_secret();
        std::cout << "|" ;
        std::cout << std::right << std::setw(10) << this->contacts_array[search_index].get_phone();
        std::cout << "|" ;
        std::cout << std::endl;
        std::cout << std::endl;
        return;
    }
    

}

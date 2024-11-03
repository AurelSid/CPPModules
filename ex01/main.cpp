/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:36 by roko              #+#    #+#             */
/*   Updated: 2024/11/03 19:04:17 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int main()
{
    Phonebook my_phonmebook;

    std::string input;
    
   while(1)
   {
     std::cout << "TYPE A COMMAND (ADD, SEARCH , EXIT)" << std::endl;
     std::getline(std::cin, input);
     if(!input.compare("ADD"))
     {
        my_phonmebook.add_new_contact();
        continue;
        }
     else if(!input.compare("SEARCH"))
     {
        my_phonmebook.get_contact();
        continue;
        }
     else if(!input.compare("EXIT"))
     {
        return(0);
        }
    else 
       {
        std::cout << "UNVALID COMMAND..." << std::endl;
        std::cout << std::endl;
        sleep(1);
        continue;
       }
   }
    return(0);
}
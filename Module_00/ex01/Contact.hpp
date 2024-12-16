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
        std::string number;
         
    public:
        Contact() {}
        ~Contact() {}
        void set_first_name(std::string first_name);
        void set_last_name(std::string last_name);
        void set_nickname(std::string nickanme);
        void set_phone(std::string number);
        void set_secret(std::string secret);

        std::string get_first_name() const;  
        std::string get_last_name() const;   
        std::string get_nickname() const;    
        std::string get_phone() const;                
        std::string get_secret() const;      

};

#endif

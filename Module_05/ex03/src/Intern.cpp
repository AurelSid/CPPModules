/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:20:21 by roko              #+#    #+#             */
/*   Updated: 2025/03/17 12:09:43 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

// Constructos
Intern::Intern()
{
}
// Copy_Constructor
Intern::Intern(Intern &other)
{
    *this = other;
    std::cout << "Intern copy constructor called." << std::endl;
}
// Destructor
Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}
// Exceptions
const char *Intern::invalidFormName::what() const throw()
{
    return ("This form does not exist INTERN do your joB!");
}
// Operator overload
Intern &Intern::operator=(Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string formName, Bureaucrat &target) const
{
    AForm *(Intern::*fnptr[3])(Bureaucrat &target) const = {
        &Intern::makePresidential, &Intern::makeShrubbery, &Intern::makeRobotomy};

    std::string names[3] = {"Pardon", "Shrubbery", "Robotomy"};

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Form" << formName << " created by the intern" << std::endl;

            return (this->*fnptr[i])(target);
        }
    }
    throw Intern::invalidFormName();
    return NULL;
}
AForm *Intern::makePresidential(Bureaucrat &target) const
{
    AForm *newForm = new PresidentialPardonForm(target);
    return newForm;
}
AForm *Intern::makeRobotomy(Bureaucrat &target) const
{
    AForm *newForm = new ShrubberyCreationForm(target);
    return newForm;
}
AForm *Intern::makeShrubbery(Bureaucrat &target) const
{
    AForm *newForm = new RobotomyRequestForm(target);
    return newForm;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:20:53 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 17:56:54 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

// CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(Bureaucrat &target)
    : AForm::AForm("Presidential pardon", 25, 5), _target(target)
{
    std::cout << "PresidentialPardon created" << std::endl;
}

// DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Pardon destroyed" << std::endl;
}
// COPY CONSTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
    : AForm::AForm(other.getName(), other.getSignGrade(),
                   other.getExecGrade()),
      _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// = OVERLOAD
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}
//
void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    if (this->getSigned() == false)
    {
        std::cout << "This pardon form must me signed before "
                  << executor.getName() << " can execute it"
                  << std::endl;
        return;
    }
    if (executor.getGrade() < this->getExecGrade())
        std::cout
            << this->_target.getName()
            << " is pardonned by president Zaphod Beeblebrox"
            << std::endl;
}

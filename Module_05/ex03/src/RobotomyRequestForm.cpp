/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:20:53 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 18:51:43 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

// CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(Bureaucrat &target)
    : AForm::AForm("Robotomy", 25, 5), _target(target)
{
    std::cout << "Robotomy created" << std::endl;
}

// DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destroyed" << std::endl;
}
// COPY CONSTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
    : AForm::AForm(other.getName(), other.getSignGrade(),
                   other.getExecGrade()),
      _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// = OVERLOAD
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}
// EXEC
void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    if (this->getSigned() == false)
    {
        std::cout << "This robotomy form must me signed before "
                  << executor.getName() << " can execute it"
                  << std::endl;
        return;
    }
    if (executor.getGrade() < this->getExecGrade())
    {
        std::cout << "BRRRRRZZZZ...rrr..bzz..Rotomizating" << std::endl;
        srand(time(0));
        int random_number = rand() % 2;

        if (random_number == 0)
        {
            std::cout << "Robotomy failed!" << std::endl;
        }
        else
        {
            std::cout << "Robotomy successful!" << std::endl;
        }
    }
}

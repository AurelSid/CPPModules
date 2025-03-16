/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:20:53 by roko              #+#    #+#             */
/*   Updated: 2025/03/16 13:20:44 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

// CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target)
    : AForm::AForm("Shrubbery", 72, 45), _target(target)
{
    std::cout << "Shrubbery Form created" << std::endl;
}

// DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery form destroyed" << std::endl;
}
// COPY CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
    : AForm::AForm(other.getName(), other.getSignGrade(),
                   other.getExecGrade()),
      _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// = OVERLOAD
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_target = other._target;
    return *this;
}
// EXEC
void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    if (this->getSigned() == false)
    {
        std::cout << "This Shrubbery form must me signed before "
                  << executor.getName() << " can execute it"
                  << std::endl;
        return;
    }
    if (executor.getGrade() < this->getExecGrade())
    {
        std::ofstream outputFile("example.txt");

        if (!outputFile)
        {
            std::cerr << "Error opening the file!" << std::endl;
            return;
        }
        outputFile << "       _-_" << std::endl;
        outputFile << "    /~~   ~~\\" << std::endl;
        outputFile << " /~~         ~~\\" << std::endl;
        outputFile << "{               }" << std::endl;
        outputFile << " \\  _-     -_  /" << std::endl;
        outputFile << "   ~  \\ //  ~" << std::endl;
        outputFile << "_- -   | | _- _" << std::endl;
        outputFile << "  _ -  | |   -_" << std::endl;
        outputFile << "      // \\\\" << std::endl;

        outputFile.close();
        return;
    }
}

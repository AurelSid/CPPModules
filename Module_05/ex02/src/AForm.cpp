/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:54:18 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 12:57:39 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

// Constructos
AForm::AForm(const std::string name, int grade_to_sign, int grade_to_exec) : name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec), _signed(false)
{
}
// Copy_Constructor
AForm::AForm(const AForm &other)
    : name(other.getName()),
      grade_to_sign(other.getSignGrade()),
      grade_to_exec(other.getExecGrade()),
      _signed(other._signed)
{
    std::cout << "AForm copy constructor called." << std::endl;
}
// Destructor
AForm::~AForm()
{
    std::cout << "AForm destructor called." << std::endl;
}
// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Beaurocrats grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Beaurocrats grade is too low!");
}
// Getters

bool AForm::getSigned(void) const { return (this->_signed); };
int AForm::getExecGrade(void) const { return (this->grade_to_exec); };
int AForm::getSignGrade(void) const { return (this->grade_to_sign); };
const std::string AForm::getName(void) const { return (this->name); };
// Operator overload
AForm &AForm::operator=(AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

// beSIgned

void AForm::beSigned(Bureaucrat &signer)
{
    if (this->_signed == true)
        return;
    if (signer.getGrade() > this->grade_to_sign)
        throw GradeTooLowException();
    else
    {
        this->_signed = true;
    }
}
// Execute

void AForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() > this->grade_to_sign)
        throw GradeTooLowException();
}
// << overload
std::ostream &operator<<(std::ostream &output_stream, AForm &AForm)
{
    output_stream << "name:" << AForm.getName() << std::endl;
    output_stream << "Grade to exec:" << AForm.getExecGrade() << std::endl;
    output_stream << "Grade to sign:" << AForm.getSignGrade() << std::endl;
    output_stream << "Signed:" << AForm.getSigned() << std::endl;
    return (output_stream);
}
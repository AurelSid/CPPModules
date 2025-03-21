/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:54:18 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 12:57:39 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructos
Form::Form(const std::string name, int grade_to_sign, int grade_to_exec) : name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec), _signed(false)
{
}
// Copy_Constructor
Form::Form(const Form &other)
    : name(other.getName()),
      grade_to_sign(other.getSignGrade()),
      grade_to_exec(other.getExecGrade()),
      _signed(other._signed)
{
    std::cout << "Form copy constructor called." << std::endl;
}
// Destructor
Form::~Form()
{
    std::cout << "Form destructor called." << std::endl;
}
// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Beaurocrats grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Beaurocrats grade is too low!");
}
// Getters

bool Form::getSigned(void) const { return (this->_signed); };
int Form::getExecGrade(void) const { return (this->grade_to_exec); };
int Form::getSignGrade(void) const { return (this->grade_to_sign); };
const std::string Form::getName(void) const { return (this->name); };
// Operator overload
Form &Form::operator=(Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

// beSIgned

void Form::beSigned(Bureaucrat &signer)
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

// << overload
std::ostream &operator<<(std::ostream &output_stream, Form &form)
{
    output_stream << "name:" << form.getName() << std::endl;
    output_stream << "Grade to exec:" << form.getExecGrade() << std::endl;
    output_stream << "Grade to sign:" << form.getSignGrade() << std::endl;
    output_stream << "Signed:" << form.getSigned() << std::endl;
    return (output_stream);
}
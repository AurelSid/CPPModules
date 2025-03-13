/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:54:18 by roko              #+#    #+#             */
/*   Updated: 2025/03/13 17:25:58 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructos
Form::Form(const std::string name, int grade_to_sign, int grade_to_exec) : name(name), grade_to_exec(grade_to_exec), grade_to_sign(grade_to_sign)
{
}
// Copy_Constructor
Form::Form(const Form &other)
    : grade_to_exec(other.getExecGrade()),
      grade_to_sign(other.getSignGrade()),
      name(other.getName()),
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
// Increments

// Operator overload
Form &Form::operator=(Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:46:27 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 17:36:11 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// EXCEPTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is higher than the maximum!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is lower than the minimum!");
}

// Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName())
{
    this->grade = other.getGrade();
    std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat: " << this->name << " destroyed" << std::endl;
}

// Copy Operator overload
Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
    if (&other != this)
        this->grade = other.grade;
    return *this;
}
// GET FUNCTIONS
int Bureaucrat::getGrade(void) const { return (this->grade); }
const std::string Bureaucrat::getName(void) const { return (this->name); }

// GRADE CHANGES
void Bureaucrat::grade_Increment(void)
{
    if (this->grade <= -1)
        throw GradeTooHighException();
    this->grade--;
}
void Bureaucrat::grade_Decrement(void)
{
    if (this->grade >= 150)
        throw GradeTooHighException();
    this->grade++;
}
std::ostream &operator<<(std::ostream &output_stream, Bureaucrat &other)
{
    output_stream << "Bureaucrat name" << other.getName()
                  << "Bureaurat grade:" << other.getGrade() << std::endl;
    return (output_stream);
};

// Sign AForm
void Bureaucrat::signAForm(AForm &AForm)
{
    if (AForm.getSigned() == true)
    {
        std::cout << "AForm already signed" << std::endl;
        return;
    }
    AForm.beSigned(*this);
    if (AForm.getSigned() == true)
        std::cout << this->name << " signed the AForm:" << AForm.getName() << std::endl;
    else
        std::cout << this->name << "couldnt signe the AForm:" << AForm.getName() << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:46:39 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 12:31:57 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    AForm *makePresidential(Bureaucrat &target) const;
    AForm *makeRobotomy(Bureaucrat &target) const;
    AForm *makeShrubbery(Bureaucrat &target) const;

public:
    class invalidFormName : public std::exception
    {
    public:
        const char *what() const throw();
    };
    Intern();
    Intern(Intern &other);
    ~Intern(void);

    AForm *makeForm(std::string formName, Bureaucrat &target) const;

    Intern &operator=(Intern &other);
};

#endif
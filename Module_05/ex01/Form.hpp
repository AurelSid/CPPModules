/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:46:39 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 12:31:57 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
    const std::string name;
    const int grade_to_sign;
    const int grade_to_exec;
    bool _signed;
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

public:
    Form(const std::string name, int grade_to_sign, int grade_to_exec);
    Form(const Form &other);
    ~Form(void);

    bool getSigned(void) const;
    int getExecGrade(void) const;
    int getSignGrade(void) const;
    const std::string getName(void) const;

    Form &operator=(Form &other);

    void beSigned(Bureaucrat &signer);
};
std::ostream &operator<<(std::ostream &output_stream, Form &form);

#endif
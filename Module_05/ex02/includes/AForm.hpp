/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:46:39 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 12:31:57 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
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
    AForm(const std::string name, int grade_to_sign, int grade_to_exec);
    AForm(const AForm &other);
    virtual ~AForm(void);

    bool getSigned(void) const;
    int getExecGrade(void) const;
    int getSignGrade(void) const;
    const std::string getName(void) const;

    AForm &operator=(AForm &other);

    virtual void beSigned(Bureaucrat &signer);
    virtual void execute(Bureaucrat const &executor) = 0;
};
std::ostream &operator<<(std::ostream &output_stream, AForm &AForm);

#endif
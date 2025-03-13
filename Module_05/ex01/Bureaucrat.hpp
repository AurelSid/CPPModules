/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:46:39 by roko              #+#    #+#             */
/*   Updated: 2025/03/05 15:58:20 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
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
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat(void);

    int getGrade(void) const;
    const std::string getName(void) const;

    void grade_Increment(void);
    void grade_Decrement(void);

    Bureaucrat &operator=(Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &output_stream, Bureaucrat &other);
#endif
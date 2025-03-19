/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:32:19 by roko              #+#    #+#             */
/*   Updated: 2025/03/15 14:33:16 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
class ShrubberyCreationForm : public AForm
{
private:
    Bureaucrat &_target;

public:
    ShrubberyCreationForm(Bureaucrat &target);
    ShrubberyCreationForm(ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);

    void execute(Bureaucrat const &executor);
};

#endif
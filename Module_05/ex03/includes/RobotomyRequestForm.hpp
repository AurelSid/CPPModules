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

#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm
{
private:
    Bureaucrat &_target;

public:
    RobotomyRequestForm(Bureaucrat &target);
    RobotomyRequestForm(RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm &other);

    void execute(Bureaucrat const &executor);
};

#endif
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

#ifndef PRESIDENTIAL_PARDON_HPP
#define PRESIDENTIAL_PARDON_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm
{
private:
    Bureaucrat &_target;

public:
    PresidentialPardonForm(Bureaucrat &target);
    PresidentialPardonForm(PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm &other);

    void execute(Bureaucrat const &executor);
};

#endif
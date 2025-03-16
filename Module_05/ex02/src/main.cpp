/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:42:11 by babreton          #+#    #+#             */
/*   Updated: 2025/03/16 13:25:03 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
int main()
{
    Bureaucrat *Donald = NULL;
    Bureaucrat *Joe = NULL;
    AForm *simpleDoc = NULL;
    AForm *robotForm = NULL;
    AForm *TreeForm = NULL;
    try
    {
        Donald = new Bureaucrat("Donald", 55);
        Joe = new Bureaucrat("Joe", 1);
        simpleDoc = new PresidentialPardonForm(*Donald);
        robotForm = new RobotomyRequestForm(*Donald);
        TreeForm = new ShrubberyCreationForm(*Donald);
        simpleDoc->execute(*Joe);
        Joe->signAForm(*simpleDoc);
        simpleDoc->execute(*Joe);
        Joe->signAForm(*robotForm);
        robotForm->execute(*Joe);
        Joe->signAForm(*TreeForm);
        TreeForm->execute(*Joe);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << *simpleDoc << std::endl;
    delete Donald;
    delete Joe;
    delete simpleDoc;
}
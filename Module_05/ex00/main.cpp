/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:46:41 by roko              #+#    #+#             */
/*   Updated: 2025/03/02 16:43:11 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Odin("Odin", 1);
    Bureaucrat Loki("Loki", 150);

    std::cout << "Just created two bureaucrat gods!" << std::endl;
    std::cout << Odin << std::endl;
    std::cout << Loki << std::endl;

    std::cout << "\nLet's try creating Thor with grade 0" << std::endl;
    /* GradeTooHighException */
    try
    {
        Bureaucrat Thor("Thor", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Cannot create Thor!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\nLet's try creating John with grade 151" << std::endl;
    /* GradeTooLowException */
    try
    {
        Bureaucrat John("Thor", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Cannot create John!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\nLet's try promoting Odin!" << std::endl;
    /* Increment throwing exception */
    try
    {
        Odin.grade_Increment();
    }
    catch (std::exception &e)
    {
        std::cout << "Cannot increment the grade of Odin!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\nLet's try demoting Loki!" << std::endl;
    /* Decrement throwing exception */
    try
    {
        Loki.grade_Decrement();
    }
    catch (std::exception &e)
    {
        std::cout << "Cannot decrement the grade of Loki!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

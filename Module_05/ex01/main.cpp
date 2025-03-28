/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:42:11 by babreton          #+#    #+#             */
/*   Updated: 2025/03/15 13:41:02 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    Bureaucrat *Donald = NULL;
    Bureaucrat *Joe = NULL;
    Form *simpleDoc = NULL;
    Form *Doc = NULL;

    try
    {
        Donald = new Bureaucrat("Donald", 55);
        Joe = new Bureaucrat("Joe", 35);
        simpleDoc = new Form("Simple Document", 50, 49);
        Joe->signForm(*simpleDoc);
        Joe->signForm(*simpleDoc);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Doc = new Form("doc", 50, 49);
        Donald->signForm(*Doc);
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
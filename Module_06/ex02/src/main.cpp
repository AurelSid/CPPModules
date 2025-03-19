/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:07:27 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 22:06:49 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
    Base *ptr;
    srand(time(0));
    int randomNum = rand() % 3;
    if (randomNum == 0)
        ptr = new A;
    if (randomNum == 1)
        ptr = new B;
    if (randomNum == 2)
        ptr = new C;

    return ptr;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Pointer is A" << std::endl;

    if (dynamic_cast<B *>(p))
        std::cout
            << "Pointer is B" << std::endl;

    if (dynamic_cast<C *>(p))
        std::cout
            << "Pointer is C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);

        std::cout << "Its of type A" << std::endl;
        (void)a;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << "Its of type B" << std::endl;
        (void)b;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << "Its of type C" << std::endl;
        (void)c;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    Base *ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

    return 0;
}

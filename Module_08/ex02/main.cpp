/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:00:34 by asideris          #+#    #+#             */
/*   Updated: 2025/03/24 17:28:45 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack top :" << mstack.top() << std::endl;
	std::cout << "Stack size :" << mstack.size() << std::endl;
	std::cout << "Popping :" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack size :" << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator itt = mstack.begin();
	MutantStack<int>::iterator itte = mstack.end();

	while (itt != itte)
	{
		std::cout << *itt << std::endl;
		++itt;
	}
	////////////////////////////////////
	std::cout << "////////////////////////////" << std::endl;
	////////////////////////////////////

	std::list<int> s;
	s.push_back(5);
	s.push_back(17);
	std::cout << "List top :" << s.front() << std::endl;
	std::cout << "List size :" << s.size() << std::endl;
	std::cout << "Popping :" << s.front() << std::endl;
	s.pop_back();
	std::cout << "List size :" << s.size() << std::endl;
	s.push_back(3);
	s.push_back(5);
	s.push_back(737);
	s.push_back(0);
	std::list<int>::iterator it = s.begin();
	std::list<int>::iterator ite = s.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}
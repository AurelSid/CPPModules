/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:00:40 by asideris          #+#    #+#             */
/*   Updated: 2025/03/24 17:08:40 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSTACK_HPP
# define MSTACK_HPP
# include <iostream>
# include <list>
# include <stack>
template <typename Type> class MutantStack : public std::stack<Type>
{
  public:
	MutantStack();
	MutantStack(MutantStack &other);
	~MutantStack();
	MutantStack<Type> &operator=(MutantStack &other);
	typedef typename std::stack<Type>::container_type::iterator iterator;
	iterator begin();
	iterator end();

  private:
};
template <typename Type> MutantStack<Type>::MutantStack()
{
}
template <typename Type> MutantStack<Type>::MutantStack(MutantStack<Type> &other)
{
	this = other;
}
template <typename Type> MutantStack<Type>::~MutantStack()
{
}
template <typename Type> MutantStack<Type> &MutantStack<Type>::operator=(MutantStack<Type> &other)
{
	this->begin = other.begin;
	this->end = other.end;
	return (*this);
}
template <typename Type> typename MutantStack<Type>::iterator MutantStack<Type>::begin()
{
	return (this->c.begin());
}

template <typename Type> typename MutantStack<Type>::iterator MutantStack<Type>::end()
{
	return (this->c.end());
}

#endif

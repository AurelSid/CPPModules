/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:18:39 by roko              #+#    #+#             */
/*   Updated: 2025/03/23 20:57:57 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    this->_maxSize = 0;
    this->_curr_size = 0;
};

Span::Span(unsigned int n)
{
    this->_maxSize = n;
    this->_curr_size = 0;
};
Span::~Span() {};
Span::Span(Span &other)
{
    *this = other;
};

Span &Span::operator=(Span &other)
{
    if (this != &other)
    {
        this->_array = other._array;
        this->_curr_size = other._curr_size;
        this->_maxSize = other._maxSize;
    }
    return (*this);
};
void Span::addNumber(unsigned int n)
{
    if (this->_curr_size == this->_maxSize)
        throw Span::maxArrayException();
    else
        this->_array.push_back(n);
    this->_curr_size++;
};
void Span::addMultNumbers(unsigned int n)
{
    if (this->_curr_size + n > this->_maxSize)
        throw Span::maxArrayException();
    unsigned int nb = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        nb = rand() % 100 + 1;
        Span::addNumber(nb);
        std::cout << "added " << nb << std::endl;
    }
};
int Span::shortestSpan()
{
    if (this->_curr_size <= 1)
        throw Span::emptyArrayException();
    std::sort(this->_array.begin(), this->_array.end());
    std::vector<int>::iterator ptr;
    int min_span = __INT_MAX__;
    for (ptr = this->_array.begin(); ptr != (this->_array.end()) - 1; ptr++)
    {
        if (((*(ptr + 1)) - *ptr) < min_span)
            min_span = *(ptr + 1) - *ptr;
    }
    return (min_span);
};
int Span::longestSpan()
{
    if (this->_array.size() < 2)
        throw Span::emptyArrayException();

    std::vector<int> sorted_array = this->_array;
    std::sort(sorted_array.begin(), sorted_array.end());

    return sorted_array.back() - sorted_array.front();
}

const char *Span::emptyArrayException::what() const throw()
{
    return "Need at least 2 nums in the array";
};
const char *Span::maxArrayException::what() const throw()
{
    return "Too many elements!";
};

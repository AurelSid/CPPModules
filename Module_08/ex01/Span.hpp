/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:44:56 by roko              #+#    #+#             */
/*   Updated: 2025/03/23 20:35:36 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
#include <list>

class Span
{
public:
    Span();
    Span(unsigned int size);
    ~Span();
    Span(Span &other);

    Span &operator=(Span &other);
    void addNumber(unsigned int);
    void addMultNumbers(unsigned int);
    int shortestSpan();
    int longestSpan();

    class emptyArrayException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class maxArrayException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    std::vector<int> _array;
    unsigned int _maxSize;
    unsigned int _curr_size;
};
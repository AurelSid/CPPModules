/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:44:56 by roko              #+#    #+#             */
/*   Updated: 2025/03/21 17:29:20 by roko             ###   ########.fr       */
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
    ~Span();
    Span(Span &other);

    Span &operator=(Span &other);
    void addNumber(int);
    int shortestSpan();
    int longestSpan();

    class emptyArrayException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class emptyArrayException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class emptyArrayException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    std::list<int> _array;
    int _maxSize;
    int _curr_size;
};
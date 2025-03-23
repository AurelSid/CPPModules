/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:18:04 by roko              #+#    #+#             */
/*   Updated: 2025/03/20 22:17:35 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array
{
private:
    T *ptr;
    int _size;

public:
    Array();
    Array(int s);
    ~Array();
    Array(Array const &src);
    Array &operator=(Array &other);
    T &operator[](int index);
    int size();
    class InvalidIndexException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

// Empty constructor
template <typename T>
Array<T>::Array()
{
    ptr = new T[0];
    _size = 0;
}

// Allocated constructor
template <typename T>
Array<T>::Array(int s)
{
    ptr = new T[s];
    for (int i = 0; i < s; i++)
        ptr[i] = 0;
}

// Copy constructor
template <typename T>
Array<T>::Array(Array const &src)
{
    *this = src;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    delete[] ptr;
}

// Size method
template <typename T>
int Array<T>::size()
{
    return _size;
}

// Assignment operator overload
template <typename T>
Array<T> &Array<T>::operator=(Array<T> &other)
{
    if (this != &other)
    {
        delete[] this->ptr;
        this->ptr = new T[other.size()];
        for (int i = 0; i < other.size(); i++)
            this->ptr[i] = other.ptr[i];
    }
    return (*this);
}

// Index operator overload
template <typename T>
T &Array<T>::operator[](int index)
{
    if (index >= _size || index < 0)
        throw Array::InvalidIndexException();
    return (this->ptr[index]);
}

// Exception class
template <typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
    return ("Index is not valid! Please use valid index!");
}

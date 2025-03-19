/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:23:49 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 14:19:18 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

// constructor
Data::Data() : data_int(10) {};
// cp constructor
Data::Data(Data &other)
{
    *this = other;
};
// = overload
Data &Data::operator=(Data &other)
{

    if (this != &other)
    {
        this->data_int = other.data_int;
    }
    return *this;
}
// getter
int Data::get_data()
{
    return this->data_int;
}
// deconstructor
Data::~Data()
{
}

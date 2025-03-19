/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serial.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:23:57 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 14:18:45 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serial.hpp"

Serializer::Serializer() {};
Serializer::Serializer(Serializer &other)
{
    *this = other;
};
Serializer::~Serializer() {};

Serializer &Serializer::operator=(Serializer &other)
{
    (void)other;
    return *this;
};

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
};
Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
};

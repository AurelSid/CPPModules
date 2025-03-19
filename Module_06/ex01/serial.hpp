/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:23:44 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 14:15:04 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIAL_HPP
#define SERIAL_HPP
#include <iostream>
#include <string>
#include <stdint.h>
#include "data.hpp"
class Serializer
{
private:
    Serializer();
    Serializer(Serializer &other);
    ~Serializer();

public:
    Serializer &operator=(Serializer &other);
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
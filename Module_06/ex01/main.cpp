/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:23:54 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 14:21:29 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babreton <babreton@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:42:23 by babreton          #+#    #+#             */
/*   Updated: 2023/09/21 13:52:31 by babreton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serial.hpp"
#include "data.hpp"

int main()
{
    Data *data = new Data;
    uintptr_t raw;

    std::cout << data->get_data() << std::endl;
    std::cout << data << std::endl;
    std::cout << "=======================" << std::endl;

    raw = Serializer::serialize(data);

    std::cout << raw << std::endl;
    std::cout << "=======================" << std::endl;

    data = Serializer::deserialize(raw);

    std::cout << data->get_data() << std::endl;
    std::cout << data << std::endl;
    std::cout << "=======================" << std::endl;

    delete data;
    return 0;
}
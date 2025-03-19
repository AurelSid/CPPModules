/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:25:58 by roko              #+#    #+#             */
/*   Updated: 2025/03/19 13:02:36 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
public:
    Data();
    ~Data();
    Data(Data &other);

    int get_data();
    Data &operator=(Data &other);

private:
    int data_int;
};

#endif
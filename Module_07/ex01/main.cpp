/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:58:23 by roko              #+#    #+#             */
/*   Updated: 2025/03/20 14:56:12 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename Type>
Type my_func_temp(Type *array_addr, int array_len, Type (*fct)(Type))
{
    Type maxVal = array_addr[0];

    for (int i = 1; i < array_len; i++)
    {
        if (fct(array_addr[i]) > fct(maxVal))
        {
            maxVal = array_addr[i];
        }
    }
    return maxVal;
}

template <typename T>
T my_func(T x)
{
    if (x < 0)
        x *= -1;

    return x;
}

int main()
{
    int arr[] = {3, -7, 2, -10, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    int maxAbs = my_func_temp(arr, length, my_func<int>);

    std::cout << "Element with max absolute value: " << maxAbs << std::endl;

    return 0;
}

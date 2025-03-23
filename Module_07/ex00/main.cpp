/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:03:37 by roko              #+#    #+#             */
/*   Updated: 2025/03/20 13:55:17 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename Type>
Type max(Type x, Type y)
{
    if (x > y)
        return x;

    else
        return y;
}

template <typename Type>
Type min(Type x, Type y)
{
    if (x < y)
        return x;

    else
        return y;
}
template <typename Type>
void swap(Type &x, Type &y)
{
    Type z;
    z = x;
    x = y;
    y = z;
    return;
}

int main()
{
    int a = 1;
    int b = 2;

    std::cout << "max" << max<float>(10, 30) << std::endl;
    std::cout << "min" << min<float>(10, 30) << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    swap(a, b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}
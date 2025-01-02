/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/02 13:03:31 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *first_zombie;
	first_zombie = zombieHorde(5, "chump");
	for (int i = 0; i < 5; i++)
		first_zombie[i].announce();
	return (0);
}
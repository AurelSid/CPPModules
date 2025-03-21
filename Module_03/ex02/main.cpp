/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:33:03 by roko              #+#    #+#             */
/*   Updated: 2025/01/07 16:30:47 by roko             ###   ########.fr       */
/*                              #                                              */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap Robin("Robin");
	ClapTrap *Romeo = new ClapTrap("Roméo");
	ScavTrap Cyril("Cyril");
	FragTrap Bryan("Bryan");

	Robin.attack("Cyril");
	Cyril.takeDamage(Robin.get_attack_damage());
	Cyril.beReapaired(18);
	Cyril.guardGate();
	Cyril.attack("Romeo");
	Romeo->takeDamage(Cyril.get_attack_damage());
	delete Romeo;
	Bryan.attack("Cyril");
	Cyril.takeDamage(Bryan.get_attack_damage());
	Bryan.highFiveGuys();
	return (0);
}
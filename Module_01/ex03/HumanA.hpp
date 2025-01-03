/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:44:54 by asideris          #+#    #+#             */
/*   Updated: 2025/01/02 18:37:33 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <iostream>
# include <unistd.h>

class HumanA
{
  public:
	HumanA(std::string human_name, Weapon &weapon_obj) : name(human_name),
		weapon(weapon_obj)
	{
	}
	~HumanA()
	{
	}
	void set_name(std::string name);
	std::string get_weapon_type();
	void attack();

  private:
	std::string name;
	Weapon &weapon;
};
#endif
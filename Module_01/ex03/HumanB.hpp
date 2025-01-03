/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/02 18:52:00 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <iostream>
# include <unistd.h>

class HumanB
{
  public:
	HumanB(std::string human_name) : name(human_name)
	{
	}
	~HumanB()
	{
	}
	void set_name(std::string name);
	void setWeapon(Weapon &weapon);

	std::string get_weapon_type();
	void attack();

  private:
	std::string name;
	Weapon *weapon;
};
#endif
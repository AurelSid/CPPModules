/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/02 17:39:21 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <unistd.h>

class Weapon
{
  public:
	Weapon(const std::string weapon_type) : type(weapon_type)
	{
	}
	~Weapon(){};

	void setType(const std::string type_name);
	const std::string &get_type();

  private:
	std::string type;
};

#endif
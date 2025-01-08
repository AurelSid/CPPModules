/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:20 by roko              #+#    #+#             */
/*   Updated: 2025/01/08 16:50:17 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
  public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &other);
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
	ScavTrap &operator=(ScavTrap const &other);

  private:
};

#endif
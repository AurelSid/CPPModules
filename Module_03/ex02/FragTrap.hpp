/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:20 by roko              #+#    #+#             */
/*   Updated: 2025/01/08 18:26:08 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
  public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &other);
	~FragTrap();
	void attack(const std::string &target);
	void guardGate();
	void highFiveGuys();
	FragTrap &operator=(FragTrap const &other);

  private:
};

#endif
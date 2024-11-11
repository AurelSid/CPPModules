/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2024/11/11 17:57:45 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEN_H
# define ZOMBIE_H

# include <iostream>
# include <unistd.h>

class Zombie
{
  public:
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	std::string get_name();

  private:
	std::string name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
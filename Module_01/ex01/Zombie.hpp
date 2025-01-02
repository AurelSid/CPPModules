/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:51:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/02 12:47:53 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEN_H
# define ZOMBIE_H

# include <iostream>
# include <unistd.h>

class Zombie
{
  public:
	~Zombie();

	void Zombie_name(std::string name);
	void announce(void);
	std::string get_name();

  private:
	std::string name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:20:00 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 19:30:10 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include "Character.hpp"

class Ice : AMateria
{
  public:
	Ice(){};
	~Ice(){};
	Ice(Ice &other){};

	Ice &operator=(Ice &other);
	void use(ICharacter &target) override;
	AMateria *clone() const override;

  private:
	std::string type = "ice";
};
#endif

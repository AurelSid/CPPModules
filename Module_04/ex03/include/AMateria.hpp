/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:12:13 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 16:18:15 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>

class AMateria
{
  public:
	// De_Constrctors
	~AMateria();
	AMateria();
	AMateria(AMateria &other);
	AMateria(std::string const &type);

	// Operator assignment
	AMateria &operator=(AMateria &other);

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

  protected:
  private:
};

#endif
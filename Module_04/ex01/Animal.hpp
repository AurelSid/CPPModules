/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:46:10 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 14:17:37 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include "Brain.hpp"
# include <iostream>
# include <string>

class Animal
{
  public:
	Animal();
	Animal(std::string const &type);
	Animal(Animal const &other);
	~Animal();

	Animal &operator=(Animal const &other);
	std::string get_type() const;

	void set_type(std::string const type);

	void makeSound();

  protected:
	std::string type;

  private:
};
#endif
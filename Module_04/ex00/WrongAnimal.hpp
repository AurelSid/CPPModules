/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:46:10 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 15:38:02 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
# include <iostream>
# include <string>

class WrongAnimal
{
  public:
	WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(WrongAnimal const &other);
	~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &other);
	std::string get_type() const;

	void set_type(std::string const type);
	void makeSound();

  protected:
	std::string type;

  private:
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:37 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 14:16:29 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(Cat const &other);
	~Cat();

	Cat &operator=(Cat const &other);
	void makeSound() override;

  private:
	std::string type = "Cat";
	Brain *brain;
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:37 by roko              #+#    #+#             */
/*   Updated: 2025/01/10 14:15:35 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_H
# define Dog_H
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(Dog const &other);
	~Dog();

	Dog &operator=(Dog const &other);
	void makeSound() override;

  private:
	std::string type = "Dog";
	Brain *brain;
};
#endif
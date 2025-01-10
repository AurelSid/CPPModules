/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:37 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 15:41:13 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_H
# define WrongCat_H
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(WrongCat const &other);
	~WrongCat();

	WrongCat &operator=(WrongCat const &other);

  private:
	std::string type = "WrongCat";
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:20:21 by roko              #+#    #+#             */
/*   Updated: 2025/01/09 22:32:31 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
# include <iostream>
# include <string>

class Brain
{
  public:
	Brain();
	~Brain();
	Brain(Brain const &other);
	Brain &operator=(Brain const &other);

  private:
	std::string _ideas[100];
};

#endif
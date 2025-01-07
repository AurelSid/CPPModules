#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>
class ClapTrap
{
  public:
	ClapTrap(std::string name) : name(name)
	{
	}
	~ClapTrap(){};
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beReapaired(unsigned int amount);

  private:
	std::string name;
	int _hit_points = 10;
	int _energy_points = 10;
	int _attack_damage = 10;
};

#endif
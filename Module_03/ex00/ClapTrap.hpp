#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>
class ClapTrap
{
  public:
	ClapTrap(std::string name);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beReapaired(unsigned int amount);

	int get_hit_points();
	int get_energy_points();
	int get_attack_damage();
	std::string get_name();

  private:
	std::string _name;
	int _hit_points = 10;
	int _energy_points = 10;
	int _attack_damage = 10;
};

#endif
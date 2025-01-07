#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>
class ClapTrap
{
  public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &other);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beReapaired(unsigned int amount);

	int get_hit_points() const;
	int get_energy_points() const;
	int get_attack_damage() const;

	void set_hit_points(int val);
	void set_energy_points(int val);
	void set_attack_damage(int val);

  private:
	std::string _name;
	int _hit_points = 10;
	int _energy_points = 10;
	int _attack_damage = 10;
};

class ScavTrap : public ClapTrap
{
  public:
	ScavTrap(std::string name) : ClapTrap(name){};

  private:
};

#endif
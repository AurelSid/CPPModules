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

	void attack(ClapTrap &target);
	void takeDamage(unsigned int amount);
	void beReapaired(unsigned int amount);

	int get_hit_points() const;
	int get_energy_points() const;
	int get_attack_damage() const;

	void set_hit_points(int val);
	void set_energy_points(int val);
	void set_attack_damage(int val);

	std::string get_name() const;

  private:
	std::string _name;
	int _hit_points = 10;
	int _energy_points = 10;
	int _attack_damage = 10;
};

#endif
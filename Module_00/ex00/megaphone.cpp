#include <iostream>

void	str_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	std::cout << str;
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
		return (1);
	}
	else
		while (argv[i])
		{
			str_to_upper(argv[i]);
			i++;
		}
	std::cout << std::endl;
	return (0);
}



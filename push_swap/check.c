#include "includes/push_swap.h"

int	ft_duplicate(int tmp, char **argv, int i)
{
	i = i + 1;
	while(argv[i])
	{
		if (ft_atoi(argv[i]) == tmp)
			return(0);
		i++;
	}
	return(1);
}

int	ft_digit(char *element)
{
	int	i;

	i = 0;
	if (element[i] == '-')
		i++;
	while(element[i])
	{
		if (!ft_isdigit(element[i]))
			return(0);
		i++;
	}
	return(1);
}

void	ft_checking(char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while(argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if(!ft_digit(argv[i]))
			error("Error");
		if(!ft_duplicate(tmp, argv, i))
			error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			error("Error");
		i++;
	}
}
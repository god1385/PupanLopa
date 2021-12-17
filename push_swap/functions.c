#include "includes/push_swap.h"

void	error(char *error)
{
	ft_putendl_fd(error, 1);
	exit(0);
}

int	sorted(t_stack **list)
{
	t_stack	*first;

	first = *list;
	while (first && first->next)
	{
		if (first->info > first->next->info)
			return (0);
		first = first->next;
	}
	return (1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	first = *stack;
	while (first)
	{
		tmp = first;
		first = first->next;
		free(tmp);
	}
	free(stack);
}

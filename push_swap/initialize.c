#include "includes/push_swap.h"

t_stack	*getminimal(t_stack	**list)
{
	t_stack	*minimal;
	int	check;
	t_stack	*first;

	first = *list;
	check = 1;
	minimal = NULL;
	while (first)
	{
		if ((first->index == -1) && (check == 1 || first->info < minimal->info))
		{
			minimal = first;
			check = 0;
		}
		else
			first = first->next;
	}
	return(minimal);
}

void	indexation(t_stack **list)
{
	t_stack *first;
	int	index;

	first = *list;
	index = 0;
	first = getminimal(list);
	while(first)
	{
		first->index = index;
		index++;
		first = getminimal(list);
	}
}
#include "includes/push_swap.h"

int	maxbites(t_stack **list)
{
	t_stack	*first;
	int	i;
	int	maxb;

	first = *list;
	i = 0;
	maxb = 0;
	while(first)
	{
		if (first->index > i)
		{
			i = first->index;
		}
		first = first->next;
	}
	while(i >> maxb)
		maxb++;
	return(maxb);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	int	max;
	int	i;
	int	size;
	int	j;

	first = *stack_a;
	size = sizelista(first);
	max = maxbites(stack_a);
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j++ < size)
		{
			first = *stack_a;
			if (((first->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while(sizelista(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
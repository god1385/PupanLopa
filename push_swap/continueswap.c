#include "includes/push_swap.h"
int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_a,t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	first = *stack;
	tail = ft_last(first);
	*stack = first->next;
	first->next = NULL;
	tail->next = first;
}

int	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
	return (0);
}
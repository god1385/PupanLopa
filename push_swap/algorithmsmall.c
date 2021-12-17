#include "includes/push_swap.h"

static int	get_min(t_stack **list, int index)
{
	t_stack	*first;
	int		min;

	first = *list;
	min = first->index;
	while (first)
	{
		if ((first->index < min) && first->index != index)
			min = first->index;
		first = first->next;
	}
	return (min);
}
int		ft_max(t_stack **list)
{
	int max;
	t_stack	*first;

	first = *list;
	max = first->info;
	while (first)
	{
		if (first->info > max)
			max = first->info;
		first = first->next;
	}
	return (max);
}

static void	sort_3(t_stack **stack_a)
{
	int max;
	int	min;
	t_stack *first;

	min = get_min(stack_a, -1);
	first = *stack_a;
	max = ft_max(stack_a);
	if (sizelista(*stack_a) == 1)
		return ;
	else if (sizelista(*stack_a) == 2)
	{
		if (first->info > first->next->info)
			sa(stack_a);
		return ;
	}
	else if (sizelista(*stack_a) == 3)
	{
		if (first->info == max && first->next->index != min)
		{
			ra(stack_a);
			sa(stack_a);
			return ;
		}
		if (first->info == max && first->next->index == min)
		{
			ra(stack_a);
			return ;
		}
		if (first->next->info == max && first->index == min)
		{
			rra(stack_a);
			sa(stack_a);
			return ;
		}
		if (first->next->info == max && first->index != min)
			rra(stack_a);
		if (first->next->index == min && first->info != max)
			sa(stack_a);
		return ;
	}
}
static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	t_stack	*first;

	first = *stack_a;
	if (sorted(stack_a))
		return ;
	min = get_min(stack_a, -1);
	if (first->next->index == min)
		ra(stack_a);
	else if (first->next->next->index == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (first->next->next->next->index == min)
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	t_stack	*first;
	first = *stack_a;
	min = get_min(stack_a, -1);
	if (first->next->index == min)
		ra(stack_a);
	else if (first->next->next->index == min)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (first->next->next->next->index == min)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (first->next->next->next->next->index == min)
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = sizelista(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

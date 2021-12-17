/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:43:57 by macbook           #+#    #+#             */
/*   Updated: 2021/12/15 03:04:34 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	first = *stack;
	next = first->next;
	if (!first && !next)
		error("Error occured while swapping!");
	tmp_val = first->info;
	tmp_index = first->index;
	first->info = next->info;
	first->index = next->index;
	first->info = tmp_val;
	first->index = tmp_index;
}
int	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{	
	if ((sizelista(*stack_a) < 2) || (sizelista(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*first_to;
	t_stack	*first_from;

	if (sizelista(*stack_from) == 0)
		return (-1);
	first_to = *stack_to;
	first_from = *stack_from;
	tmp = first_from;
	first_from = first_from->next;
	*stack_from = first_from;
	tmp->next = first_to;
	*stack_to = tmp;
	return (0);
}
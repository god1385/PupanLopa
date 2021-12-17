/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:24:09 by hjanis            #+#    #+#             */
/*   Updated: 2021/12/15 02:57:33 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((sizelista(*stack_a) < 2) || (sizelista(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverseRotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	if (sizelista(*stack) < 2)
		return (-1);
	first = *stack;
	tail = ft_last(first);
	while (first)
	{
		if (first->next->next == NULL)
		{
			 first->next = NULL;
			 break ;
		}
		first = first->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((sizelista(*stack_a) < 2) || (sizelista(*stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
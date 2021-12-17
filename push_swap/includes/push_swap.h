/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:51:22 by hjanis            #+#    #+#             */
/*   Updated: 2021/12/15 03:07:19 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int					info;
	int					index;
	struct s_stack		*next;
}	t_stack;
int	pa(t_stack **stack_a, t_stack **stack_b);
int	pb(t_stack **stack_a,t_stack **stack_b);
void	rotate(t_stack **stack);
int	ra(t_stack **stack_a);
int	rb(t_stack **stack_b);
int	rr(t_stack **stack_a, t_stack **stack_b);
int	reverseRotate(t_stack **stack);
int	rra(t_stack **stack_a);
int	rrb(t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);
int	ft_duplicate(int tmp, char **argv, int i);
int	ft_digit(char *element);
void	ft_checking(char **argv);
int	maxbites(t_stack **list);
void	radix(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
int	sa(t_stack **stack_a);
int	sb(t_stack **stack_b);
int	ss(t_stack **stack_a, t_stack **stack_b);
int	push(t_stack **stack_to, t_stack **stack_from);
void	error(char *error);
int	sorted(t_stack **list);
void	ft_free(char **str);
void	free_stack(t_stack **stack);
//static int	get_min(t_stack **list, int index);
int		ft_max(t_stack **list);
//static void	sort_3(t_stack **stack_a);
//static void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
t_stack	*getminimal(t_stack	**list);
void	indexation(t_stack **list);
t_stack	*ft_new(int newlist);
t_stack	*ft_last(t_stack *first);
void	ft_addlast(t_stack **list, t_stack *new);
int	sizelista(t_stack *first);
void	initialise(t_stack **stack, int argc, char **argv);
void	sortirovka(t_stack **stack_a, t_stack **stack_b);
int		main(int argc, char **argv);

#endif
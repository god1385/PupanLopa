/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:17:22 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/01 23:38:37 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_char(t_print *tab, char m)
{
	char	c;

	if (m == '%')
		tab->tall += write(1, "%", 1);
	if (m == 'c')
	{
		c = va_arg(tab->args, int);
		tab->tall += write(1, &c, 1);
	}
}

void	ft_string(t_print *tab)
{
	int		i;
	char	*string;

	i = 0;
	string = va_arg(tab->args, char *);
	if (!string)
		string = "(null)";
	while (string[i])
		tab->tall += write(1, &string[i++], 1);
}

void	ft_pointer(t_print *tab)
{
	unsigned long	n;

	n = (unsigned long)va_arg(tab->args, void *);
	tab->tall += write(1, "0x", 2);
	tab->tall += ft_putnbr_base(n, "0123456789abcdef");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:17:22 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/01 23:46:30 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_numlenbase(unsigned int n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += 1;
		return (count);
	}
	if (n > 0)
	{
		count++;
		base /= 10;
	}
	return (count);
}

char	*ft_itoa_base(char *str, unsigned long n, int base, int c)
{
	int		i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + c;
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (str);
}

void	ft_hex(t_print *tab, char c)
{
	unsigned int	n;
	int				l;
	int				i;

	i = 16;
	n = va_arg(tab->args, unsigned int);
	l = ft_numlenbase(n, i);
	if (c == 'x')
		tab->tall += ft_putnbr_base(n, "0123456789abcdef");
	if (c == 'X')
		tab->tall += ft_putnbr_base(n, "0123456789ABCDEF");
}

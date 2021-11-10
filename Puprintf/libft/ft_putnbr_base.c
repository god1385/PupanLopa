/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:52:56 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/04 17:59:33 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	unsigned long	nbr;
	int				l;

	l = 1;
	nbr = n;
	base_len = ft_strlen(base);
	if (nbr == 0)
	{
		ft_putchar('0');
		return (l);
	}
	if (nbr >= base_len)
	{
		l += ft_putnbr_base(nbr / base_len, base);
		ft_putchar(base[nbr % base_len]);
	}
	else if (nbr < base_len)
		ft_putchar(base[nbr]);
	return (l);
}

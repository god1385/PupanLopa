/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:17:22 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/01 23:38:37 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_unsigneditoa(unsigned int number)
{
	char	*a;
	int		l;

	l = ft_numlen(number);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	a[l--] = '\0';
	if (number == 0)
		a[l] = 0 + '0';
	while (number > 0)
	{
		a[l--] = number % 10 + '0';
		number /= 10;
	}
	return (a);
}

void	ft_int(t_print *tab, char m)
{
	int		i;
	int		j;
	char	*nbr;

	i = 0;
	j = va_arg(tab->args, int);
	if (m == 'd' || m == 'i')
		nbr = ft_itoa(j);
	else
		nbr = ft_unsigneditoa((unsigned int)j);
	if (!nbr)
		return ;
	while (nbr[i])
		tab->tall += write(1, &nbr[i++], 1);
	free (nbr);
}

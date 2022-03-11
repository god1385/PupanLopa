/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:14:21 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/16 15:22:06 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
	void	neg(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static
	int	ft_putnbr_itoa(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		n = n * -1;
		i--;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static
	void	itoachar(char *str, int n, int len)
{
	len = len - 1;
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		negative;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_putnbr_itoa(n);
	negative = 0;
	neg(&n, &negative);
	len += negative;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	itoachar(str, n, len);
	str[--len] = '\0';
	if (negative)
		str[0] = '-';
	return (str);
}

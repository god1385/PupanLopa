/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:34:53 by macbook           #+#    #+#             */
/*   Updated: 2021/11/05 00:40:47 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

char *ft_unsigneditoa(unsigned int number)
{
    char *a;
    int l;

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
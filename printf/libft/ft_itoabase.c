/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 00:50:52 by macbook           #+#    #+#             */
/*   Updated: 2021/11/05 00:51:42 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlenbase(unsigned n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += 1;
		return(count);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:15:50 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/13 15:15:46 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(p + i) = (unsigned char)c;
		i++;
	}
	return (p);
}

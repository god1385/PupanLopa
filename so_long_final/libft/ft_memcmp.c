/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:15:37 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/13 14:15:39 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;
	size_t			i;

	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	i = 0;
	if (len == 0)
		return (0);
	while (*cstr1 == *cstr2 && ++i < len)
	{
		cstr1++;
		cstr2++;
	}
	return ((int)(*cstr1 - *cstr2));
}

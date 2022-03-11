/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:43:18 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/15 21:35:12 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lendest;
	size_t	lensrc;

	lendest = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	j = lendest;
	if (lendest < (dstsize - 1) && dstsize > 0)
	{
		while (src[i] && lendest + i < (dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (lendest >= dstsize)
	{
		lendest = dstsize;
	}
	return (lendest + lensrc);
}

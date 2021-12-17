/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:41 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/15 21:45:56 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	z;
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	z = 0;
	i = len_dst;
	if (size > 0 && len_dst < (size - 1))
	{
		while (src[z] && len_dst + z < (size - 1))
		{
			dst[i] = src[z];
			z++;
			i++;
		}
		dst[i] = 0;
	}
	if (len_dst >= size)
	{
		len_dst = size;
	}
	return (len_dst + len_src);
}

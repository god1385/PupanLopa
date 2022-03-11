/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:15:50 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/13 20:04:42 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (!dst && !src)
		return (0);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (len--)
		*cdst++ = *csrc++;
	return (dst);
}

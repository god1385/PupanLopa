/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:47:56 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/13 14:55:03 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	size *= count;
	str = malloc(size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:13:16 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/24 17:49:30 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( char *string, int c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)c)
			return ((char *)string + i);
		i++;
	}
	if (string[i] == (char)c)
		return ((char *)string + i);
	return (NULL);
}

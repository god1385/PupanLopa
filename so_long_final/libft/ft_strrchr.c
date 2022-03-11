/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:27:06 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/13 21:51:24 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		i;

	i = 0;
	while (string[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (string[i] == (char)c)
			return ((char *)(string + i));
		i--;
	}
	return (NULL);
}

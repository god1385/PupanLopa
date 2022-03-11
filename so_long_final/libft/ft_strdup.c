/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:22:32 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/16 15:37:12 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char	*str)
{
	int		i;
	char	*dest;

	i = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	while (i >= 0)
	{
		dest[i] = str[i];
		i--;
	}
	return (dest);
}

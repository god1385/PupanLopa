/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:53:17 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/15 15:58:04 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*strsub;
	unsigned int	i;
	unsigned int	z;

	i = 0;
	z = 0;
	if (!s)
		return (NULL);
	if (len > (unsigned int)ft_strlen(s))
		strsub = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		strsub = (char *)malloc(sizeof(char) * len + 1);
	if (!strsub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && z < len)
		{
			strsub[z] = s[i];
			z++;
		}
		i++;
	}
	strsub[z] = '\0';
	return (strsub);
}

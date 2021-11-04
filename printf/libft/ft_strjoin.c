/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:41 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/15 15:56:41 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t;
	size_t	i;
	char	*newstr;

	t = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(sizeof(*s1) * ((ft_strlen((char *)s1))
				+ (ft_strlen((char *)s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[t++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[t++] = s2[i];
		i++;
	}
	newstr[t] = '\0';
	return (newstr);
}

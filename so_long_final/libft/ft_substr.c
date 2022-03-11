/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:20:16 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/15 15:46:40 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			a;
	char			*str;

	if (!s)
		return (NULL);
	if (len > (unsigned int)ft_strlen(s))
		str = (char *)malloc(sizeof((char)*s) * (ft_strlen(s) + 1));
	else
		str = (char *)malloc(sizeof((char)*s) * (len + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		if (i >= start && a < len)
		{
			str[a] = s[i];
			a++;
		}
		i++;
	}
	str[a] = 0;
	return ((char *)str);
}

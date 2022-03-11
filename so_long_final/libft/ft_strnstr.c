/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:13 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/15 22:13:34 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack && len)
	{
		if (*haystack != needle[i])
		{
			haystack++;
			len--;
			if (len == 0)
				return (NULL);
		}
		if (*haystack == needle[i])
			i++;
		else
			i = 0;
		if (needle[i] == '\0')
			return ((char *)(haystack - i + 1));
		haystack++;
		len--;
	}
	return (NULL);
}

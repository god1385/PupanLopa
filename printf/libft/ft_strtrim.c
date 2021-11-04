/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:53:17 by ctorrek           #+#    #+#             */
/*   Updated: 2021/10/15 12:55:15 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *string, char const *set)
{
	size_t		size;
	char		*newstring;

	if (!string || !set)
		return (NULL);
	while (*string && ft_strchr(set, *string))
		string++;
	size = ft_strlen((char *)string);
	while (size && ft_strchr(set, string[size]))
		size--;
	newstring = ft_substr((char *)string, 0, size + 1);
	return (newstring);
}

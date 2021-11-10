/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:39:44 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/04 18:46:15 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		len;
	char	*string;

	len = 0;
	while (s[len])
		len++;
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (NULL);
	while (len >= 0)
	{
		string[len] = s[len];
		len--;
	}
	return (string);
}

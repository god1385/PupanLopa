/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:20:59 by hjanis            #+#    #+#             */
/*   Updated: 2021/10/16 15:32:52 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0')
			&& (!(str[i] == charset || str[i] == '\0')))
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while (!(from[i] == charset || from[i] == '\0'))
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **split, const char *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == charset || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == charset || str[i + j] == '\0'))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[word])
				return (0);
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (1);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	write_split(res, str, c);
	return (res);
}

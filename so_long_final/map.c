/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:05:48 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 20:07:01 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "include/so_long.h"

static int	counter(char *file)
{
	int		counter;
	int		fd;
	int		reader;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	counter = 1;
	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, &c, 1);
		if (reader < 0)
			return (-1);
		if (c == '\n')
			counter++;
	}
	close(fd);
	return (counter);
}

static char	**map_memory(char *file)
{
	char	**map;
	int		lines;

	lines = counter(file);
	if (lines <= 0)
		return (NULL);
	map = NULL;
	map = malloc(sizeof(char *) * lines + 1);
	if (!map)
		return (NULL);
	return (map);
}

char	**map_reader(char *file)
{
	char	**map;
	int		fd;
	int		i;
	int		lines;

	map = NULL;
	map = map_memory(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	lines = counter(file);
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}

int	ycounter(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

void	ft_free_chartable(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

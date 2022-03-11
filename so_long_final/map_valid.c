/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:03:30 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 20:17:43 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static	t_map	initialise(char **map)
{
	t_map	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ycounter(map);
	data.player = 0;
	data.exit = 0;
	data.collectable = 0;
	data.position.x = 0;
	data.position.y = 0;
	return (data);
}

t_map	checkmap(char **map, t_map data, t_data *dat)
{
	int			x;
	int			y;
	static int	i;

	if (!i)
		i = 0;
	x = data.position.x;
	y = data.position.y;
	if (map[y][x] == 'P')
		data.player = 1;
	if (map[y][x] == 'E')
		data.exit = 1;
	if (map[y][x] == 'C')
		data.collectable = 1;
	if (map[y][x] == 'M')
		dat->enemy_count++;
	return (data);
}

int	checking(char **map, t_map data)
{
	int			x;
	int			y;
	static int	i;

	if (!i)
		i = 0;
	x = data.position.x;
	y = data.position.y;
	if (!checker_char(map[y][x]))
		exit_program("No needed chars, Error");
	if (map[y][x] == 'P')
	{
		if (i == 1)
			return (0);
		i = 1;
		data.player = 1;
	}
	if (map[y][x] == 'E')
		data.exit = 1;
	if (map[y][x] == 'C')
		data.collectable = 1;
	if (!check_borders(map[y][x], data.position, data.size))
		exit_program("Border Error");
	return (1);
}

int	validation(char **map, t_data *dat)
{
	int		check;
	t_map	data;

	data = initialise(map);
	check = 1;
	while (map[data.position.y])
	{
		if (ft_strlen(map[data.position.y]) != data.size.x)
			check = 0;
		data.position.x = 0;
		while (map[data.position.y][data.position.x])
		{
			if (!checking(map, data))
				check = 0;
			data.position.x++;
			data = checkmap(map, data, dat);
		}
		data.position.y++;
	}
	if (!data.collectable || !data.exit || !data.player)
		exit_program("No essential parametars, Error");
	return (check);
}

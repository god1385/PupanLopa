/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:01:31 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 20:06:27 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_tilestruct	**allocationoftiles(char **map)
{
	 t_tilestruct	**tiles;
	 int			i;

	 tiles = malloc(sizeof(t_tilestruct *) * ycounter(map) + 1);
	 if (!tiles)
		return (0);
	i = 0;
	while (map[i] != NULL)
	{
		tiles[i] = malloc(sizeof(t_tilestruct) * ft_strlen(*map) + 1);
		if (tiles == NULL)
		{
			while (i != 0)
				free(tiles[--i]);
			return (0);
		}
		i++;
	}
	return (tiles);
}

void	tilestart(t_tilestruct	**tiles, int x, int y)
{
	tiles[y][x].position.x = x * IMAGE;
	tiles[y][x].position.y = y * IMAGE;
	if (y != 0)
		tiles[y][x].up = &tiles[y - 1][x];
	if (tiles[y + 1] != NULL)
		tiles[y][x].down = &tiles[y + 1][x];
	if (x != 0)
		tiles[y][x].left = &tiles[y][x - 1];
	tiles[y][x].right = &tiles[y][x + 1];
}

t_tiles	tiletype(char tile)
{
	if (tile == '1')
		return (WALL);
	if (tile == 'E')
		return (EXIT);
	if (tile == 'P')
		return (PLAYER);
	if (tile == 'C')
		return (COLLECTABLE);
	if (tile == 'M')
		return (ENEMY);
	return (EMPTY);
}

t_tiles	enemy_tile(char tile, t_data *data)
{
	if (tile == 'M')
	{
		data->enemy_count++;
		return (ENEMY);
	}
	return (EMPTY);
}

void	playerandcollect(t_tilestruct *tiles, t_data *data)
{
	static int	i;

	if (!i)
	{
		i = 0;
	}
	if (tiles->type == PLAYER)
		data->player.tile = tiles;
	if (tiles->type == ENEMY)
	{
		data->enemy[i].tile = tiles;
		i++;
	}
	if (tiles->type == COLLECTABLE)
		data->collectables++;
}

t_tilestruct	**tilesinitialise(char **map, t_data *data)
{
	int					x;
	int					y;
	t_tilestruct		**tiles;

	tiles = allocationoftiles(map);
	if (!tiles)
		return (NULL);
	data->enemy = malloc(sizeof(t_player) * data->enemy_count);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tiles[y][x].type = tiletype(map[y][x]);
			tilestart(tiles, x, y);
			playerandcollect(&tiles[y][x], data);
			x++;
		}
		tiles[y][x].type = 0;
		y++;
	}
	tiles[y] = NULL;
	data->window_size.x = x * IMAGE;
	data->window_size.y = y * IMAGE;
	return (tiles);
}

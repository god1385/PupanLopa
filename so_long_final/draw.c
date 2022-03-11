/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:56:47 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 21:26:39 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	player_mov(t_data data, t_vector position)
{
	static int	frame;

	if (!frame)
		frame = 0;
	if (frame < 30)
		frame = imagestand(data, position, frame);
	if (frame >= 30 && frame < 60)
		frame = imagemid(data, position, frame);
	if (frame >= 60 && frame < 90)
	{
		mlx_put_image_to_window(data.mlx, data.win,
			data.player_sit, position.x, position.y);
		frame++;
	}
	if (frame >= 90 && frame < 120)
	{
		mlx_put_image_to_window(data.mlx, data.win,
			data.player_midd, position.x, position.y);
		frame++;
	}
	if (frame == 120)
		frame = 0;
}

void	enemy_movement(t_data data, t_vector position)
{
	static int	frame;

	if (!frame)
		frame = 0;
	if (frame < 45)
		frame = enemystand(data, position, frame);
	if (frame >= 45 && frame < 75)
		frame = enemyhalf(data, position, frame);
	if (frame >= 75 && frame < 105)
	{
		mlx_put_image_to_window(data.mlx, data.win,
			data.enenemy_sit, position.x, position.y);
		frame++;
	}
	if (frame >= 105 && frame < 135)
	{
		mlx_put_image_to_window(data.mlx, data.win,
			data.enemy_half, position.x, position.y);
		frame++;
	}
	if (frame == 135)
		frame = 0;
}

static void	drawing(t_data data, t_tilestruct tile, t_vector position)
{
	if (tile.type == EMPTY)
		mlx_put_image_to_window(data.mlx, data.win,
			data.emptyimg, position.x, position.y);
	if (tile.type == WALL)
		mlx_put_image_to_window(data.mlx, data.win,
			data.wallimg, position.x, position.y);
	if (tile.type == PLAYER)
		player_mov(data, position);
	if (tile.type == ENEMY)
		enemy_movement(data, position);
	if (tile.type == EXIT)
	{
		if (data.collectables == 0)
			mlx_put_image_to_window(data.mlx,
				data.win, data.exitfinishimg, position.x, position.y);
		else
			mlx_put_image_to_window(data.mlx, data.win,
				data.exitimg, position.x, position.y);
	}
	if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(data.mlx, data.win,
			data.collectableimg, position.x, position.y);
}

static void	text(t_data data)
{
	char	*str;

	str = ft_itoa(data.moves);
	mlx_string_put(data.mlx, data.win,
		data.window_size.x - IMAGE / 2.3, IMAGE - IMAGE / 1.5, -1, str);
	free(str);
}

void	generation(t_data data)
{
	t_tilestruct		tile;
	int					x;
	int					y;

	mlx_clear_window(data.mlx, data.win);
	y = 0;
	while (data.tiles[y] != NULL)
	{
		x = 0;
		while (data.tiles[y][x].type != 0)
		{
			tile = data.tiles[y][x];
			drawing(data, tile, tile.position);
			x++;
		}
		y++;
	}
	text(data);
}

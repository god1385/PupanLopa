/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:54:41 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 20:14:30 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	move_to_grass(t_data *data, t_tilestruct	*tile)
{
	tile->type = PLAYER;
	if (data->player.tile->type != EXIT)
		data->player.tile->type = EMPTY;
	data->player.tile = tile;
}

void	move_to_coin(t_data *data, t_tilestruct *tile)
{
	tile->type = EMPTY;
	move_to_grass(data, tile);
}

int	movement(t_data *data, t_tilestruct *tile)
{
	if (tile->type == EMPTY)
		move_to_grass(data, tile);
	if (tile->type == COLLECTABLE)
	{
		move_to_coin(data, tile);
		data->collectables--;
	}
	if (tile->type == EXIT && data->collectables == 0)
		exit(1);
	if (tile->type == ENEMY)
		exit(1);
	else
		return (0);
	return (1);
}

int	input(int key, t_data *data)
{
	ft_printf("%d\n", data->moves);
	if (key == RIGHT)
	{
		movement(data, data->player.tile->right);
		data->moves++;
	}
	if (key == END)
		exit(1);
	if (key == LEFT)
	{
		movement(data, data->player.tile->left);
		data->moves++;
	}
	if (key == DOWN)
	{
		movement(data, data->player.tile->down);
		data->moves++;
	}
	if (key == UP)
	{
		movement(data, data->player.tile->up);
		data->moves++;
	}
	return (1);
}

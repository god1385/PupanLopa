/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:57:12 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/11 13:53:45 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	imagestand(t_data data, t_vector position, int frame)
{
	mlx_put_image_to_window(data.mlx, data.win,
		data.playerimg, position.x, position.y);
	frame++;
	return (frame);
}

int	imagemid(t_data data, t_vector position, int frame)
{
	mlx_put_image_to_window(data.mlx, data.win,
		data.player_midd, position.x, position.y);
	frame++;
	return (frame);
}

int	enemystand(t_data data, t_vector position, int frame)
{
	mlx_put_image_to_window(data.mlx, data.win,
		data.enemy_stand, position.x, position.y);
	frame++;
	return (frame);
}

int	enemyhalf(t_data data, t_vector position, int frame)
{
	mlx_put_image_to_window(data.mlx, data.win,
		data.enemy_half, position.x, position.y);
	frame++;
	return (frame);
}

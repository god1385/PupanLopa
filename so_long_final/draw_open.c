/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:24:23 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 21:38:49 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	drawwallandempty(t_data *data)
{
	int	x;

	x = 50;
	data->wallimg = mlx_xpm_file_to_image(data->mlx, "images/rock.xpm", &x, &x);
	data->emptyimg = mlx_xpm_file_to_image(data->mlx,
			"images/grass.xpm", &x, &x);
	data->playerimg = mlx_xpm_file_to_image(data->mlx,
			"images/pers.xpm", &x, &x);
	data->exitimg = mlx_xpm_file_to_image(data->mlx,
			"images/portal_start.xpm", &x, &x);
	data->collectableimg = mlx_xpm_file_to_image(data->mlx,
			"images/coin.xpm", &x, &x);
	data->exitfinishimg = mlx_xpm_file_to_image(data->mlx,
			"images/portal_end.xpm", &x, &x);
	data->player_sit = mlx_xpm_file_to_image(data->mlx,
			"images/pers_sit.xpm", &x, &x);
	data->player_midd = mlx_xpm_file_to_image(data->mlx,
			"images/pers_middle.xpm", &x, &x);
}

void	drawenemy(t_data *data)
{
	int	x;

	x = 50;
	data->enemy_stand = mlx_xpm_file_to_image(data->mlx,
			"images/Enemy_stand.xpm", &x, &x);
	data->enenemy_sit = mlx_xpm_file_to_image(data->mlx,
			"images/Enemy_sit.xpm", &x, &x);
	data->enemy_half = mlx_xpm_file_to_image(data->mlx,
			"images/Enemy_middle.xpm", &x, &x);
}

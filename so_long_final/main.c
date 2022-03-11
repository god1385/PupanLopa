/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:53:09 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 20:48:10 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_tilestruct	**map_init(char **argv, t_data *data)
{
	char				**map;
	t_tilestruct		**tilemap;

	data->collectables = 0;
	map = map_reader(argv[1]);
	if (!map)
		return (0);
	if (validation(map, data) == 0)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = tilesinitialise(map, data);
	ft_free_chartable(map);
	if (!tilemap)
		return (0);
	return (tilemap);
}

int	game(t_data *data, char **argv)
{
	data->enemy_count = 0;
	data->mlx = mlx_init();
	data->tiles = map_init(argv, data);
	data->moves = 0;
	if (data->tiles == NULL)
		return (0);
	data->win = mlx_new_window(data->mlx, data->window_size.x,
			data->window_size.y, "So_long");
	mlx_hook(data->win, 53, 0, end, data);
	drawwallandempty(data);
	drawenemy(data);
	return (1);
}

int	gen(t_data *data)
{
	if (data->win == NULL)
		exit(1);
	if (data->win != NULL)
		generation(*data);
	if (data->win != NULL)
		enemy(data);
	return (1);
}

void	exit_program(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	if (argc != 2)
		return (0);
	if (!game(&mlx, argv))
		return (0);
	mlx_hook(mlx.win, 2, 0, input, (void *)&mlx);
	mlx_loop_hook(mlx.mlx, gen, (void *)&mlx);
	mlx_hook(mlx.win, 17, 1L << 2, end, game);
	mlx_loop(mlx.mlx);
	return (0);
}

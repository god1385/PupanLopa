/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:29:11 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/08 20:43:31 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_player	*create_enemy(t_tilestruct *tile)
{
	t_player	*enemy;

	enemy = malloc(sizeof(t_player));
	if (!enemy)
		return (NULL);
	enemy->tile = tile;
	return (enemy);
}

t_player	*last(t_player *enemies)
{
	if (!enemies)
		return (NULL);
	while (enemies->next != NULL)
		enemies = enemies->next;
	return (enemies);
}

void	spawn_enemy(t_tilestruct *tile, t_data *data)
{
	t_player	*new;

	ft_printf("2\n");
	new = create_enemy(tile);
	if (data->enemy == NULL)
	{
		ft_printf("4\n");
		data->enemy = new;
		ft_printf("3\n");
	}
	else
	{
		ft_printf("5\n");
		last(data->enemy)->next = new;
	}
	ft_printf("1");
}

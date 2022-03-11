/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:08:35 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/10 21:23:16 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	checker_char(char map)
{
	if (map == 'P' || map == 'C' || map == '1'
		|| map == '0' || map == 'E' || map == 'M')
		return (1);
	else
		return (0);
}

int	check_borders(char c, t_vector position, t_vector size)
{
	if (position.y == 0 || position.x == 0
		|| position.y == size.y - 1 || position.x == size.x - 1)
		if (c != '1')
			return (0);
	return (1);
}

int	end(t_data *data)
{
	(void)data;
	exit(1);
}

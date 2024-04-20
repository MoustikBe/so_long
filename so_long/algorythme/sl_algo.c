/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:58:25 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:02:48 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	local_p(char **map, t_long *store_struct)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				store_struct->y = y;
				store_struct->x = x;
			}
			x++;
		}
		y++;
	}
}

void	local_e(char **map, t_long *store_struct)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				store_struct->pos_e_y = y;
				store_struct->pos_e_x = x;
			}
			x++;
		}
		y++;
	}
}

void	fill_algo(char **map, int y, int x, t_long *game_struct)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
	{
		game_struct->comp_c = game_struct->comp_c + 1;
		map[y][x] = 'V';
	}
	else
	{
		map[y][x] = 'V';
		fill_algo(map, y +1, x, game_struct);
		fill_algo(map, y -1, x, game_struct);
		fill_algo(map, y, x +1, game_struct);
		fill_algo(map, y, x -1, game_struct);
	}
}

int	verif_exit(char **map, t_long *game_struct, int y, int x)
{
	if (game_struct->c == game_struct->comp_c)
	{
		if (map[y][x] == 'V')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	main_algo(char **map, t_long *store_struct)
{
	int	x;
	int	y;

	local_p(map, store_struct);
	local_e(map, store_struct);
	y = store_struct->y;
	x = store_struct->x;
	store_struct->comp_c = 0;
	fill_algo(map, y, x, store_struct);
	x = 0;
	y = store_struct->pos_e_y;
	x = store_struct->pos_e_x;
	if (verif_exit(map, store_struct, y, x))
		return (0);
	return (1);
}

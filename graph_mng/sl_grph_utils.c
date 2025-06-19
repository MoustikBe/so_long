/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grph_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:55:23 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:56:44 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	info_map(char **map, t_game *game)
{
	int	y;
	int	x;

	game->nb_action = 0;
	game->c_p = 0;
	game->c_tot = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->c_tot = game->c_tot + 1;
			if (map[y][x] == 'P')
			{
				game->ply_x = x;
				game->ply_y = y;
			}
			x++;
		}
		y++;
	}
	game->len_y = y;
	game->len_x = x;
}

static int	mem_line(char **map, int mem, int mem_word)
{
	while (map[mem])
	{
		mem_word = 0;
		while (map[mem][mem_word])
			mem_word++;
		mem++;
	}
	return (mem);
}

static int	mem_letter(char **map, int mem, int mem_word)
{
	while (map[mem])
	{
		mem_word = 0;
		while (map[mem][mem_word])
			mem_word++;
		mem++;
	}
	return (mem_word);
}

void	map_to_strcut(char **map, t_game *map_struct, int mem, int mem_word)
{
	int	i;
	int	j;

	mem = mem_line(map, mem, mem_word);
	mem_word = mem_letter(map, mem, mem_word);
	map_struct->map = malloc((mem + 1) * sizeof(char *));
	if (!map_struct->map)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		map_struct->map[i] = malloc((mem_word) * sizeof(char *));
		if (!map_struct->map[i])
			return ;
		while (map[i][j])
		{
			map_struct->map[i][j] = map[i][j];
			j++;
		}
		map_struct->map[i][j] = '\0';
		i++;
	}
	map_struct->map[i] = NULL;
}

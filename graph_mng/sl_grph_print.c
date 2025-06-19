/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grph_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:53:26 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:55:03 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	put_both(t_game *game, int j, int i, char *str)
{
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_0,
		j * 100, i * 100);
	mlx_put_image_to_window(game->mlx, game->wdw, str, j * 100, i * 100);
}

void	put_texture(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_0,
					j * 100, i * 100);
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_1,
					j * 100, i * 100);
			if (map[i][j] == 'C')
				put_both(game, j, i, game->img_c);
			if (map[i][j] == 'E')
				put_both(game, j, i, game->img_e);
			if (map[i][j] == 'P')
				put_both(game, j, i, game->img_p);
			j++;
		}
		i++;
	}
}

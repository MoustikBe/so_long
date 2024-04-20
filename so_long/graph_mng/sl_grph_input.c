/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grph_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:38:30 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 17:35:45 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	key_action_ud(t_game *g, int p)
{
	if (g->map[p][g->ply_x] == '1')
		return ;
	if (g->map[p][g->ply_x] == 'C')
	{
		g->map[p][g->ply_x] = '0';
		g->c_p = g->c_p + 1;
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
			g->ply_x * 100, p * 100);
	}
	if (g->map[p][g->ply_x] == 'E')
	{
		if (g->c_p == g->c_tot)
		{
			mlx_destroy_window(g->mlx, g->wdw);
			exit(1);
		}
		else
			return ;
	}
	g->nb_action = g->nb_action + 1;
	ft_put_action(g->nb_action);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_0, g->ply_x * 100,
		g->ply_y * 100);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_p, g->ply_x * 100, p * 100);
	g->ply_y = p;
}

void	key_action_lr(t_game *g, int n)
{
	if (g->map[g->ply_y][n] == '1')
		return ;
	if (g->map[g->ply_y][n] == 'C')
	{
		g->map[g->ply_y][n] = '0';
		g->c_p = g->c_p + 1;
		mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
			n * 100, g->ply_y * 100);
	}
	if (g->map[g->ply_y][n] == 'E')
	{
		if (g->c_p == g->c_tot)
		{
			mlx_destroy_window(g->mlx, g->wdw);
			exit(1);
		}
		else
			return ;
	}
	g->nb_action = g->nb_action + 1;
	ft_put_action(g->nb_action);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_0,
		g->ply_x * 100, g->ply_y * 100);
	mlx_put_image_to_window(g->mlx, g->wdw, g->img_p, n * 100, g->ply_y * 100);
	g->ply_x = n;
}

int	mng_input(int keysym, t_game *game)
{
	int	x_1;
	int	y_1;
	int	xx1;
	int	yx1;

	x_1 = game->ply_x - 1;
	y_1 = game->ply_y - 1;
	xx1 = game->ply_x + 1;
	yx1 = game->ply_y + 1;
	if (keysym == 0 || keysym == 123)
		key_action_lr(game, x_1);
	if (keysym == 2 || keysym == 124)
		key_action_lr(game, xx1);
	if (keysym == 13 || keysym == 126)
		key_action_ud(game, y_1);
	if (keysym == 1 || keysym == 125)
		key_action_ud(game, yx1);
	if (keysym == 53)
	{
		mlx_destroy_window(game->mlx, game->wdw);
		free_map(game->map);
		free(game->mlx);
		exit(1);
	}
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wdw);
	free(game->mlx);
	exit(1);
}

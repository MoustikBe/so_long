/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grph_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:51:53 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:53:17 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	texture_init(t_game *game)
{
	game->path_0 = "img/floor.xpm";
	game->path_1 = "img/wall.xpm";
	game->path_c = "img/key.xpm";
	game->path_e = "img/tardis.xpm";
	game->path_p = "img/doctor.xpm";
}

void	map_init(char **map)
{
	t_game	game;
	int		img_w;
	int		img_h;

	texture_init(&game);
	info_map(map, &game);
	map_to_strcut(map, &game, 0, 0);
	game.mlx = mlx_init();
	game.wdw = mlx_new_window(game.mlx, game.len_x * 100, game.len_y * 100,
			"so_long");
	game.img_0 = mlx_xpm_file_to_image(game.mlx, game.path_0, &img_w, &img_h);
	game.img_1 = mlx_xpm_file_to_image(game.mlx, game.path_1, &img_w, &img_h);
	game.img_c = mlx_xpm_file_to_image(game.mlx, game.path_c, &img_w, &img_h);
	game.img_e = mlx_xpm_file_to_image(game.mlx, game.path_e, &img_w, &img_h);
	game.img_p = mlx_xpm_file_to_image(game.mlx, game.path_p, &img_w, &img_h);
	put_texture(&game, map);
	mlx_key_hook(game.wdw, mng_input, &game);
	mlx_hook(game.wdw, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}

#include "so_long.h"
#include "mlx/mlx.h"


void	map_to_strcut(char **map, t_game *map_struct)
{
	int i;
	int j;
	int		mem;
	int		mem_word;

	mem = 0;
	mem_word = 0;
	while(map[mem])
	{
		mem_word = 0;
		while(map[mem][mem_word])
			mem_word++;
		mem++;
	}	
	i = 0;
	map_struct->map = malloc((mem + 1) * sizeof(char *));
	while(map[i])
	{
		j = 0;
		map_struct->map[i] = malloc((mem_word) * sizeof(char *));
		while (map[i][j])
		{
			map_struct->map[i][j] = map[i][j]; 
			j++;
		}
		map_struct->map[i][j] = '\0';
		i++;
	}
	map_struct->map[i] = NULL;
	i = 0;
	while (map_struct->map[i])
	{
		printf("structure -> %s\n", map_struct->map[i]);
		i++;
	}
	
}

int mng_input(int keysym, t_game *game)
{
	int	x_1 = game->ply_x - 1;
	int	y_1 = game->ply_y - 1;
	int	xX1 = game->ply_x + 1;
	int	yX1 = game->ply_y + 1;
	// ALLER A GAUCHE 
	if(keysym == 0 || keysym == 123)
	{
		if(game->map[game->ply_y][x_1] == '1')
			return(1);
		if(game->map[game->ply_y][x_1] == 'C')
		{	
			game->C_p = game->C_p + 1;
			mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, x_1*100, game->ply_y*100);
		}
		if(game->map[game->ply_y][x_1] == 'E')
		{
			if(game->C_p == game->C_tot)
			{
				mlx_destroy_window(game->mlx, game->wdw);
				exit(1);
			}
			else
				return(1);
		}
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, game->ply_x*100, game->ply_y*100);
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_P, x_1*100, game->ply_y*100);
		game->ply_x = x_1;
	}
	// Aller en haut 
	if(keysym == 13 || keysym == 126)
	{
		if(game->map[y_1][game->ply_x] == '1')
			return(1);
		if(game->map[y_1][game->ply_x] == 'C')
		{	
			game->C_p = game->C_p + 1;
			mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, game->ply_x*100, y_1*100);
		}
		if(game->map[y_1][game->ply_x] == 'E')
		{
			if(game->C_p == game->C_tot)
			{
				mlx_destroy_window(game->mlx, game->wdw);
				exit(1);
			}
			else
				return(1);
		}
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, game->ply_x*100, game->ply_y*100);
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_P, game->ply_x*100, y_1*100);
		game->ply_y = y_1;
	}
	// Aller en bas 
	if(keysym == 1 || keysym == 125)
	{
		if(game->map[yX1][game->ply_x] == '1')
			return(1);
		if(game->map[yX1][game->ply_x] == 'C')
		{	
			game->C_p = game->C_p + 1;
			mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, game->ply_x*100, yX1*100);
		}
		if(game->map[yX1][game->ply_x] == 'E')
		{
			if(game->C_p == game->C_tot)
			{
				mlx_destroy_window(game->mlx, game->wdw);
				exit(1);
			}
			else
				return(1);
		}
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, game->ply_x*100, game->ply_y*100);
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_P, game->ply_x*100, yX1*100);
		game->ply_y = yX1;
	}
	// ALLER A DROITE
	if(keysym == 2 || keysym == 124)
	{
		if(game->map[game->ply_y][xX1] == '1')
			return(1); 
		if(game->map[game->ply_y][xX1] == 'C')
		{	
			game->C_p = game->C_p + 1;
			mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, xX1*100, game->ply_y*100);
		}
		if(game->map[game->ply_y][xX1] == 'E')
		{
			if(game->C_p == game->C_tot)
			{
				mlx_destroy_window(game->mlx, game->wdw);
				exit(1);
			}
			else
				return(1);
		}
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, game->ply_x*100, game->ply_y*100);
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_P, xX1*100, game->ply_y*100);
		game->ply_x = xX1;
	}
	if(keysym == 53)
	{
		printf("la touche afin de partir du programme a été toucher -> %d\n", keysym);
		mlx_destroy_window(game->mlx, game->wdw);
		free(game->mlx);
		exit(1);
	}
	printf("la touche presser est -> %d\n", keysym);
	return(0);	
}

void texture_init(t_game *game)
{
	game->path_0 = "img/floor.xpm";
	game->path_1 = "img/wall.xpm";
	game->path_C = "img/key.xpm";
	game->path_E = "img/tardis.xpm";
	game->path_P = "img/doctor.xpm";
}
void put_texture(t_game *game, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, j*100, i*100);
			if(map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_1, j*100, i*100);
			if(map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, j*100, i*100);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_C, j*100, i*100);
			}
			if(map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, j*100, i*100);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_E, j*100, i*100);
			}
			if(map[i][j] == 'P')
			{	
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_0, j*100, i*100);
				mlx_put_image_to_window(game->mlx, game->wdw, game->img_P, j*100, i*100);
			}
			j++;
		}
		i++;
	}	
}


void	info_map(char **map, t_game *game)
{
	int y;
	int x;

	game->C_p = 0;
	game->C_tot = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{	
			if(map[y][x] == 'C')
				game->C_tot = game->C_tot + 1;
			if(map[y][x] == 'P')
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

void map_init(char **map)
{
	t_game	game;
	int		img_width;
	int		img_height;

	texture_init(&game);
	info_map(map, &game);
	map_to_strcut(map, &game);
	game.mlx = mlx_init();
	game.wdw = mlx_new_window(game.mlx, game.len_x*100, game.len_y*100, "test");
	
	game.img_0 = mlx_xpm_file_to_image(game.mlx, game.path_0, &img_width, &img_height);
	game.img_1 = mlx_xpm_file_to_image(game.mlx, game.path_1, &img_width, &img_height);
	game.img_C = mlx_xpm_file_to_image(game.mlx, game.path_C, &img_width, &img_height);
	game.img_E = mlx_xpm_file_to_image(game.mlx, game.path_E, &img_width, &img_height);
	game.img_P = mlx_xpm_file_to_image(game.mlx, game.path_P, &img_width, &img_height);
	// Il faut encore que je gere la partie quant il clique sur la croix le programme s'arrete
	put_texture(&game, map);
	mlx_key_hook(game.wdw, mng_input, &game);
	mlx_loop(game.mlx);
}


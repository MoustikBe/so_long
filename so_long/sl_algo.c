#include "so_long.h"

char **copy_map(char **map)
{
	char	**copy;
	int		i;
	int		j;
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
	copy = malloc((mem + 1) * sizeof(char *));
	if (!copy)
		return(NULL);
	i = 0;
	while(map[i])
	{
		j = 0;
		copy[i] = malloc((mem_word) * sizeof(char *));
		if(!copy[i])
			return(NULL);
		while(map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}	
		i++;
	}
	i = 0;
	j = 0;
	while(copy[i])
	{	
		printf("%s\n", copy[i]);
		i++;
	}
	return (copy);
}

void local_p(char **map, t_long *store_struct)
{
	int	x;
	int	y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'P')
			{
				store_struct->y = y;
				store_struct->x = x;
			}
			x++;
		}
		y++;
	}
	printf("y -> %d\n", store_struct->y);
	printf("x -> %d\n", store_struct->x);
}
void local_e(char **map, t_long *store_struct)
{
	int	x;
	int	y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'E')
			{
				store_struct->pos_e_y = y;
				store_struct->pos_e_x = x;
			}
			x++;
		}
		y++;
	}
	printf("y -> %d\n", store_struct->pos_e_y);
	printf("x -> %d\n", store_struct->pos_e_x);
}

void fill_algo(char **map, int y, int x, t_long *game_struct)
{
	//printf("%c", map[y][x]);

	if(map[y][x] == '1')
		return;
	if(map[y][x] == 'V')
		return;
	if(map[y][x] == 'C')
	{
		game_struct->comp_c = game_struct->comp_c + 1; 
		printf("valeur de C -> %d\n", game_struct->comp_c);
		map[y][x] = 'V';
	}
	else 
	{		
		map[y][x] = 'V';
		fill_algo(map, y+1, x, game_struct);
		fill_algo(map, y-1, x, game_struct);
		fill_algo(map, y, x+1, game_struct);
		fill_algo(map, y, x-1, game_struct);
	}

}
int	verif_exit(char **map, t_long *game_struct, int y, int x)
{
	if (game_struct->C == game_struct->comp_c)
		if (map[y][x] == 'V')
			return(1);
		else 
			return(0);
	else 
		return(0);
}
int main_algo(char **map, t_long *store_struct)
{
	int x; 
	int y;
 
	local_p(map, store_struct);
	local_e(map, store_struct);
	y = store_struct->y;
	x = store_struct->x;
	store_struct->comp_c = 0;
	fill_algo(map, y, x, store_struct);
	x = 0;
	while(map[x])
	{
		printf("%s\n", map[x]);
		x++;
	}
	y = store_struct->pos_e_y;
	x = store_struct->pos_e_x;
	if (verif_exit(map, store_struct, y, x))
		return(0);
	return(1);
}

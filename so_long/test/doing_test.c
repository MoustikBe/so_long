#include "test.h"
#include "../mlx/mlx.h"

int	main(void)
{
	char	**map;
	int		count = 0;
	int count_2 = 0;

	map = malloc(4 * sizeof (char *));
	map[0] = malloc(5 * sizeof (char));
	map[1] = malloc(5 * sizeof (char));
	map[2] = malloc(5 * sizeof (char));
	while(count != 3)
	{
		count_2 = 0;
		while(count_2 != 3)
		{
			map[count][count_2] = '1';
			count_2++;
		}	
		map[count][4] = '\0';
		count++;
	}
	count = 0;
	while(map[count])
	{
		printf("map -> %s\n", map[count]);
		count++;
	}

	// copy de la map dans une structure 
	int i = 0;
	int j;
	t_long *data;


	data = malloc(sizeof(t_long));
	data->map = malloc(4 * sizeof (char *));
	data->map[0] = malloc(5 * sizeof (char));
	data->map[1] = malloc(5 * sizeof (char));
	data->map[2] = malloc(5 * sizeof (char));

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			data->map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while(data->map[i])
	{
		printf("map_copy -> %s\n", data->map[i]);
		i++;
	}
}


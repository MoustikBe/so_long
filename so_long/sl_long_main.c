/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:55:42 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/19 18:02:50 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

size_t strlen_ft(const char *str)
{
	int count; 

	count = 0;
	while(str[count])
		count++;
	return(count);
}

char	*strdup_ft(char *src)
{
	char	*dest;
	int		length;
	int		count;

	length = strlen_ft(src);
	count = 0;
	dest = malloc((length + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

int check_for_duplicate(int X)
{
	if(X)
		return(2);
	else if(X == 0)
		return(1);
	return(2);
}

int check_map_compenent(char **map, int count, int count_2, t_long *store)
{
	int i;

	i = 0;
	while(map[count])
	{
		count_2 = 0;
		while(map[count][count_2])
		{
			if(map[count][count_2] == 'C')
				store->C = ++i;
			if(map[count][count_2] == 'E')
				store->E = check_for_duplicate(store->E);
			if(map[count][count_2] == 'P')
				store->P = check_for_duplicate(store->P);
			count_2++;
		}
		count++;
	}
	if(store->C > 0 && store->E == 1 && store->P == 1)
		return(0);
	else 
		return(1);
}

int check_struct(char **map, int count, int count_2)
{
	while (map[count])
	{
		count_2 = 0;
		while (map[count][count_2])
		{
			if(map[count][count_2] == '1' || map[count][count_2] == '0' || map[count][count_2] == 'E' || map[count][count_2] == 'P' || map[count][count_2] == 'C')
				count_2++;
			else 
				return(1);
		}
		count++;
	}
	return(0);
}

int check_form(char **map, int count, int count_2)
{
	while (map[0][count])
		count++;
	while (map[count_2])
	{		
		if (map[count_2][count])
			return (1);
		count_2++;
	}
	return(0);
}

int check_square(char **map, int count, int count_2)
{
	while(map[count])
		count++;
	while(map[0][count_2])
		count_2++;
	if(count == count_2)
		return(1);
	return(0);
}

int check_wall(char **map, int count, int count_2, int last)
{
	while(map[last])
		last++;
	while(map[0][count_2])
		count_2++;
	while(map[0][count])
	{
		if(map[0][count] != '1')
			return(1);	
		count++;
	}
	count = 0;
	while(map[last - 1][count])
	{
		if(map[last - 1][count] != '1')
			return(1);
		count++;
	}
	count = 1;
	while (count < last)
	{
		if(map[count][0] != '1' || map[count][count_2 - 1] != '1')		
			return(1);
		count++;
	}
	return(0);
}

char	**store_to_map(char **map, int fd)
{
	char	*line;
	char	*full_line = NULL;
	
	line = malloc(sizeof(char));
	full_line = malloc(sizeof(char));	
	if (!line || !full_line)
		return(NULL);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		full_line = ft_strjoin(full_line, line); 
	}
	printf("%s", full_line);
	map = ft_split(full_line, '\n');
	return(map);
}

int check_map_main(char **map, t_long *store)
{ 
	store->C = 0;
	store->E = 0;
	store->P = 0;
	// CHECK DE LA STRUCTURE DE LA MAP // 
	if(check_struct(map, 0, 0))
		return(printf("Error, structure issue\n"));
	// CHECK LA FORME //
	if(check_form(map, 0, 0))
		return(printf("Error, design issue\n"));
	// CHECK SI C'EST UN CARRER //
	if(check_square(map, 0, 0))
		return(printf("Error, the map is a square\n"));
	// WALL CHECK // 
	if(check_wall(map, 0, 0, 0))
		return(printf("Error, wall issue\n"));
	if(check_map_compenent(map, 0, 0, store) == 1)
		return(printf("Erreur, compenent issue\n"));
	return(0);
}

int check_ext(char *str, int count)
{
	while (str[count])
	{
		if(str[count] == '.')
			if(str[++count] == 'b')
				if(str[++count] == 'e')
					if(str[++count] == 'r')
						return(1);
			else
				return(0);
				else
					return(0);
					else
						return(0);
		else 
			count++;
	}
	return(0);
}




int main(int argc, char **argv)
{
	int		count;
	int		fd;
	char	*file_name;
	char	**map = NULL;
	char	**map_copy = NULL;
	t_long	*store_struct; 

	store_struct = malloc(sizeof(t_long));
	argv++;
	count = 0;
	file_name = *argv;
	fd = open(file_name, O_RDONLY);
	if (argc != 2)
		return(printf("Erreur, nombre d'arguments passer invalide\n"));
	if(check_ext(file_name, 0) == 0)
		return(printf("Mauvais fichier\n"));
	map = store_to_map(map, fd);
	//system("leaks a.out"); --- LEAKS A GERER ICI 
	if(check_map_main(map, store_struct) != 0)
		return(0);
	//ALGO pour voir si on peut collecter tous les C et trouver la sortie //
	printf("map valide gg\n");
	//We have to do a copy of the map
	map_copy = copy_map(map);
	if(main_algo(map_copy, store_struct))
		return(printf("Error, issus with the exit or the collectible of the map"));
	printf("The map is perfect\n");
	// Delete the replace map for avoid memory leaks
	// Afficher la map avec les textures
	map_init(map);
	// NOT FINISH WORK IN PROGRESS free_map(map_copy);
	//system("leaks so_long");
}

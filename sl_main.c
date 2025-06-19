/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:55:42 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:35:49 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

char	**store_to_map(char **map, int fd)
{
	char	*line;
	char	*full_line;

	full_line = NULL;
	line = malloc(sizeof(char));
	full_line = malloc(sizeof(char));
	if (!line || !full_line)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		full_line = ft_strjoin(full_line, line);
	}
	map = ft_split(full_line, '\n');
	free(full_line);
	return (map);
}

int	so_long(int fd)
{
	char	**map;
	char	**map_copy;
	t_long	*store_struct;

	map = NULL;
	map_copy = NULL;
	store_struct = malloc(sizeof(t_long));
	if (!store_struct)
		return (1);
	map = store_to_map(map, fd);
	if (check_map_main(map, store_struct) != 0)
	{
		free_map(map);
		return (1);
	}
	map_copy = copy_map(map, 0, 0);
	if (main_algo(map_copy, store_struct))
	{
		free_map(map);
		free_map(map_copy);
		return (ft_putstr_fd("Error\nThe map is not possible to play.\n", 2));
	}
	free_map(map_copy);
	map_init(map);
	return (0);
}

int	main(int argc, char **argv)
{
	int		count;
	int		fd;
	char	*file_name;

	argv++;
	count = 0;
	file_name = *argv;
	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		return (ft_putstr_fd("Error\nBad file name.\n", 2));
	if (argc != 2)
		return (ft_putstr_fd("Error\nNumber of argument(s) invalid.\n", 2));
	if (check_ext(file_name, 0) == 0)
		return (ft_putstr_fd("Error\nBad extension.\n", 2));
	so_long(fd);
}

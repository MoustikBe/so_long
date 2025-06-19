/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:57:03 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:57:57 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	**copy_map(char **map, int mem, int mem_word)
{
	char	**copy;
	int		i;
	int		j;

	mem = mem_line(map, mem, mem_word);
	mem_word = mem_letter(map, mem, mem_word);
	copy = malloc((mem + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		copy[i] = malloc((mem_word) * sizeof(char *));
		if (!copy[i])
			return (NULL);
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

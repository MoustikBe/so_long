/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:03:07 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:11:33 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

int	check_wall(char **map, int count, int count_2, int last)
{
	while (map[last])
		last++;
	while (map[0][count_2])
		count_2++;
	while (map[0][count])
	{
		if (map[0][count] != '1')
			return (1);
		count++;
	}
	count = 0;
	while (map[last - 1][count])
	{
		if (map[last - 1][count] != '1')
			return (1);
		count++;
	}
	count = 1;
	while (count < last)
	{
		if (map[count][0] != '1' || map[count][count_2 - 1] != '1')
			return (1);
		count++;
	}
	return (0);
}

int	check_square(char **map, int count, int count_2)
{
	while (map[count])
		count++;
	while (map[0][count_2])
		count_2++;
	if (count == count_2)
		return (1);
	return (0);
}

int	check_form(char **map, int count, int count_2)
{
	while (map[0][count])
		count++;
	while (map[count_2])
	{
		if (map[count_2][count])
			return (1);
		count_2++;
	}
	return (0);
}

int	check_struct(char **map, int count, int count_2)
{
	while (map[count])
	{
		count_2 = 0;
		while (map[count][count_2])
		{
			if (map[count][count_2] == '1' || map[count][count_2] == '0' ||
			map[count][count_2] == 'E' || map[count][count_2] == 'P' ||
			map[count][count_2] == 'C')
				count_2++;
			else
				return (1);
		}
		count++;
	}
	return (0);
}

int	check_map_compenent(char **map, int count, int count_2, t_long *store)
{
	int	i;

	i = 0;
	while (map[count])
	{
		count_2 = 0;
		while (map[count][count_2])
		{
			if (map[count][count_2] == 'C')
				store->c = ++i;
			if (map[count][count_2] == 'E')
				store->e = check_for_duplicate(store->e);
			if (map[count][count_2] == 'P')
				store->p = check_for_duplicate(store->p);
			count_2++;
		}
		count++;
	}
	if (store->c > 0 && store->e == 1 && store->p == 1)
		return (0);
	else
		return (1);
}

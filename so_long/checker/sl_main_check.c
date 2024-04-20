/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:27:54 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:28:00 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

int	check_map_main(char **map, t_long *store)
{
	store->c = 0;
	store->e = 0;
	store->p = 0;
	if (check_struct(map, 0, 0))
		return (ft_putstr_fd("Error\nStructure issue.\n", 2));
	if (check_form(map, 0, 0))
		return (ft_putstr_fd("Error\nDesign issue.\n", 2));
	if (check_square(map, 0, 0))
		return (ft_putstr_fd("Error\nThe map is a square.\n", 2));
	if (check_wall(map, 0, 0, 0))
		return (ft_putstr_fd("Error\nWall issue.\n", 2));
	if (check_map_compenent(map, 0, 0, store) == 1)
		return (ft_putstr_fd("Error\nComponent issue.\n", 2));
	return (0);
}

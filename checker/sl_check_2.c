/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 04:12:04 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 04:27:08 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

int	check_for_duplicate(int X)
{
	if (X)
		return (2);
	else if (X == 0)
		return (1);
	return (2);
}

int	check_ext(char *str, int count)
{
	while (str[count])
	{
		if (str[count] == '.')
		{
			if (str[++count] == 'b')
			{
				if (str[++count] == 'e')
				{
					if (str[++count] == 'r')
						return (1);
					else
						return (0);
				}
				else
					return (0);
			}
			else
				return (0);
		}
		else
			count++;
	}
	return (0);
}

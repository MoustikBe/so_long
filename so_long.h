/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:50:01 by misaac-c          #+#    #+#             */
/*   Updated: 2024/04/20 03:57:48 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// -- LIBR -- // 
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include "mlx/mlx.h"
// -- LIBR -- // 
// -- STRCUT -- //
typedef struct so_long
{
	char	**map;
	int		p;
	int		e;
	int		c;
	int		comp_c;
	int		x;
	int		y;
	int		pos_e_x;
	int		pos_e_y;
}				t_long;

typedef struct struct_dsp
{
	char	**map;
	int		c_p;
	int		c_tot;
	int		nb_action;
	int		len_x;
	int		len_y;
	int		ply_x;
	int		ply_y;
	void	*mlx;
	void	*wdw;
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	char	*path_0;
	char	*path_1;
	char	*path_c;
	char	*path_e;
	char	*path_p;
}				t_game;
// -- STRCUT -- //
// -- FNCT -- //
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		main_algo(char **map, t_long *store_struct);
char	**copy_map(char **map, int mem, int mem_word);
size_t	strlen_ft(const char *str);
void	free_map(char **map);
void	map_init(char **map);
void	ft_put_action(int nb);
int		ft_putstr_fd(char *s, int fd);
int		main_algo(char **map, t_long *store_struct);
void	put_texture(t_game *game, char **map);
void	info_map(char **map, t_game *game);
void	map_to_strcut(char **map, t_game *map_struct, int mem, int mem_word);
void	key_action_ud(t_game *game, int next_pos);
void	key_action_lr(t_game *game, int next_pos);
int		mng_input(int keysym, t_game *game);
int		exit_game(t_game *game);
int		check_map_main(char **map, t_long *store);
int		check_wall(char **map, int count, int count_2, int last);
int		check_square(char **map, int count, int count_2);
int		check_form(char **map, int count, int count_2);
int		check_struct(char **map, int count, int count_2);
int		check_map_compenent(char **map, int count, int count_2, t_long *store);
int		check_for_duplicate(int X);
int		check_ext(char *str, int count);
size_t	strlen_ft(const char *str);
char	*strdup_ft(char *src);
// -- FNCT -- // 
#endif
# ifndef SO_LONG_H
# define SO_LONG_H
// -- LIBR -- // 
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <../mlx/mlx.h>
// -- LIBR -- // 

// -- STRCUT -- //
typedef struct so_long
{
	char **map;
	int P;
	int E;
	int C;
	int	comp_c;
	int x;
	int y;
	int pos_e_x;
	int pos_e_y;
}				t_long;

typedef struct struct_dsp
{
	char **map;
	int	C_p;
	int C_tot;

	int len_x;
	int len_y;

	int	ply_x;
	int	ply_y;

	void *mlx;
	void *wdw;

	void *img_0;
	void *img_1;
	void *img_C;
	void *img_E;
	void *img_P;

	char *path_0;
	char *path_1;
	char *path_C;
	char *path_E;
	char *path_P;
}				t_game;
// -- STRCUT -- //

// -- BUFF -- //
// ---------- //

// -- LIST -- //
// ---------- //

// -- FNCT -- //
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		main_algo(char **map, t_long *store_struct);
char	**copy_map(char **map);
size_t	strlen_ft(const char *str);
void	free_map(char **map);
void	map_init(char **map);
// -- FNCT -- // 

#endif 
 
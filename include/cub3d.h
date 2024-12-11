/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:13:42 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 18:23:02 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define X_SIZE_SCREEN 750
# define Y_SIZE_SCREEN 480
# define WALK_STEP 0.07
# define ROTATE_STEP 3

# define WALL_COLOR 16777215 //white

# define LEFTKEY 123
# define RIGHTKEY 124
# define DOWNKEY 125
# define UPKEY 126
# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_list
{
	void	*window;

	int		playable_str_len;
	int		playable_array_len;

	char	**playable_map;
	char	**new_playable_map;
	char	**map_settings;
	char	*map2d;
	char	**map3d;
	char	pj_init_nsew;
	int		invalid_char;
	int		n;
	int		s;
	int		e;
	int		w;

	char	**map_date;

	char	**floor;
	int		*floor_int_arr;
	int		floor_size;
	int		floor_rgb;

	char	**celling;
	int		*celling_int_arr;
	int		cell_size;
	int		cell_rgb;

	char	**no_arr;
	char	**so_arr;
	char	**we_arr;
	char	**ea_arr;

	int		stop;
	int		c;
	int		f;
	int		i;
	int		n_c;
	int		s_c;
}			t_list;

typedef struct s_data
{
	int		floor_rgb;
	int		cell_rgb;
	char	**map;
	char	**pam;
	double	px;
	double	py;
	double	rx;
	double	ry;

	double	walk_step;
	double	rotate_step;

	double	dis_x;
	double	dis_y;
	double	angle_ini;
	double	ang_dist_rad;
	double	angle;
	double	angle_rad;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		contact;
	int		correct;
	char	texture;
	double	dist;
	char	*texture_n;
	char	*texture_s;
	char	*texture_w;
	char	*texture_e;

	t_img	n;
	t_img	s;
	t_img	e;
	t_img	w;
	t_img	active;

	int		walk_forw;
	int		walk_back;
	int		walk_left;
	int		walk_right;
	int		rotate;
	double	x;
	double	y;
}				t_data;

/*MAIN X*/
int		ft_read_map(char **argv, t_list *s);
int		ft_maplen(char *s);
void	ft_s_to_d(t_list *s, t_data *d);
int		ft_read_map(char **argv, t_list *s);
int		ft_get_playable_map_strlen_arraylen(t_list *s);
/*MOVE_Q1*/
int		ft_move_q1(t_data *d, int i);
/*MOVE_Q2*/
int		ft_move_q2(t_data *d, int i);
/*MOVE_Q3*/
int		ft_move_q3(t_data *d, int i);
/*MOVE_Q4*/
int		ft_move_q4(t_data *d, int i);
/*MOVE*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_set_texture_color(t_data *d, int j, int p);
void	ft_create_line(t_data *d, int x);
int		ft_move(t_data *d);

/*SCREEN*/
int		ft_key_press(int keycode, t_data *d);
int		ft_key_hook_release(int keycode, t_data *d);
void	ft_charge_image(t_data *d);
void	ft_screen(t_data *d);

/*WALK*/
void	ft_walk_colision(t_data *d, double x, double y);
void	ft_walk_left(t_data *d);
void	ft_walk_right(t_data *d);
void	ft_walk_forward(t_data *d);
void	ft_walk_backward(t_data *d);

/*UTILS_ONE (5) X*/
size_t	ft_strlen(const char *s);
size_t	ft_arraylen(char **arr);
int		ft_count_array_len(char **arr);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
/*UTILS_TWO (5) X*/
char	*ft_calloc_for_ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
int		ft_strcmp(char *s1, char *s2);

/*SPLIT (5) X*/
int		ft_wordlen(char *s, char c);
int		ft_count_words(char *s, char c);
char	*ft_word_dupe(char *s, char c);
int		ft_fill_words(char **array, char *s, char c);
char	**ft_split(char *s, char c);

/*DUAL_SPLIT (5)X*/
int		ft_dual_wordlen(char *s, char c, char d);
int		ft_dual_count_words(char *s, char c, char d);
char	*ft_dual_word_dupe(char *s, char c, char d);
int		ft_dual_fill_words(char **array, char *s, char c, char d);
char	**ft_dual_split(char *s, char c, char d);
/*CHECK_ONE (5) X*/
int		ft_check_chars_in_playable_map(t_list *s);
int		ft_check_textures(t_list *s);
int		ft_check_map_args(t_list *s);
int		ft_check_map_double_jump_line_bis(t_list *s, int i);
int		ft_check_map_double_jump_line(t_list *s);
/*CHECK_TWO (5) X*/
int		ft_check_initial_position(t_list *s);
int		ft_check_new_playable_map_bis(t_list *s, char c, int i, int e);
int		ft_check_new_playable_map_its_playable(t_list *s, char c);
int		ft_check_player_in_new_map(t_list *s);
int		ft_checks(t_list *s);

/*GET_MAPS () X */
int		ft_get_playable_map_bis(t_list *s, int i, int u);
int		ft_get_playable_map(t_list *s);
int		ft_get_maps(t_list *s, char **argv);
int		ft_get_pj_init_position_bis(t_list *s, int i, int e);
int		ft_get_pj_init_position(t_list *s);

/*CELL_AND_RGB (5) X*/
int		ft_array_check(char *s);
int		ft_cell_atoi_array(t_list *s);
int		check_celling_numbers(t_list *s, int n);
int		ft_clean_celling(t_list *s);
int		ft_transf_rgb(int r, int g, int b);
/*FLOOR (5) X*/
int		ft_check_floor_cellig_values(t_list *s);
int		ft_floor_atoi_array(t_list *s);
int		ft_clean_floor(t_list *s);
int		ft_floor_cell(t_list *s);
int		ft_check_floor_arr_int_numbers(t_list *s, int n);
/*PARSHING (5) X*/
void	ft_parshing_map_args(t_list *s);
int		ft_clean_map3d_split_bis(t_list *s, int i, int count);
int		ft_clean_map3d_split(t_list *s);
int		ft_create_new_playable_map(t_list *s);
int		ft_calloc_for_new_playable_map(t_list *s, int e);

/*ERRORS_AND_FREES X*/
int		ft_error(t_list *s, char **argv);
void	ft_free_array(char ***s);
void	ft_free_struc_s(t_list *s);
int		ft_free_struc_d(t_data *d);

/*ROTATE*/
void	ft_rotate(t_data *d);
void	ft_pam(t_data *d, char **map);

/*TOOLBOX*/
int		ft_check_no_so_we_ea_f_c_check(t_list *s);
int		ft_check_line7(char *s);

#endif
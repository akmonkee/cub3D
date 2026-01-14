/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:25:31 by msisto            #+#    #+#             */
/*   Updated: 2026/01/14 11:49:06 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <math.h>
# include <X11/X.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define ESC 65307

# define WIN_HEIGHT 480
# define WIN_WIDTH 640

# define ERR_MSG "Error\nFailed to Populate.check File Paths Or Colour inputs\n"
# define COLOR_MSG "err_files/color_order.txt"
# define TEXTURE_MSG "err_files/texture_order.txt"
# define MAP_MSG "err_files/map_order.txt"
# define EXPECTED_MSG "err_files/expected_format.txt"
# define COLOR_NEG "err_files/color_negative.txt"

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		size;
	int		index;
	double	step;
	double	pos;
	int		x;
	int		y;
}	t_texture;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_raycast
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	raydir_x;
	double	raydir_y;
}	t_ray;

typedef struct s_map
{
	char		**content;
	int			width;
	int			height;
	int			lst_itr;
	int			playr_count;
	int			floor_color;
	int			ceiling_color;
	int			content_order;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	int			**texture_pixels;
	int			**textures;
	t_map		map_info;
	char		**map;
}	t_data;

/*datasetup.c*/
void		clear_img_setup(t_img *img);
void		map_setup(t_map *map_info);
void		ray_set(t_ray *ray);
void		player_setup(t_player *player);
void		data_setup(t_data *data);
/*raycast.c*/
void		init_ray_info(int x, t_ray *ray, t_player *player);
void		start_dda(t_ray *ray, t_player *player);
void		perform_dda(t_data *data, t_ray *ray);
void		line_calc(t_data *data, t_ray *ray, t_player *player);
void		raycasting(t_player *player, t_data *data);
/*hook.c*/
void		on_key_press_exit(t_data *data);
int			on_keypress(int keysym, t_data *data);
/*parser/parse_colors.c*/
int			get_color(char *color_arr);
int			assign_colors(char **content, int i, t_map *map_info);
int			set_colors(t_map *map_info, int lines);
/*parser/parse.c*/
void		parse_data(t_data *data, char *path);
/*parser/parse_map.c*/
int			check_file_type(char *file, char *type);
int			read_map_files(t_map *map_info, char *file);
void		map_pop(t_data *data, t_map *map_info, char *path);
void		get_just_map(t_data *data, t_map *map_info);
void		parse_map(t_data *data, char *path);
/*parser/parse_texture.c*/
void		texture_setup(t_texture *texture);
void		assign_paths(char **content, int i, t_texture *textures);
void		get_text_path(t_map *map, t_texture *texture);
void		parse_textures(t_data *data);
/*parser/parse_player.c*/
void		set_player_pos(size_t x, size_t y, t_player *player);
void		get_player_pos_pl(t_map *map, t_player *player);
void		parse_player(t_data *data);
/*utils/parse_map_utils.c*/
int			check_just_chars(char c);
int			check_for_map(t_map *map_info, int lines, int i);
/*utils/utils.c*/
int			ft_strcmp(const char *s1, const char *s2);
int			count_lines(char *file);
int			str_arr_len(char **str);
int			count_lines_arr(char **arr);
void		free_char_array(char **arr);
/*utils/utils_2.c*/
int			is_present(char c);
/*get_next_line.c*/
char		*get_line(int fd, char *buf, char *buffer);
char		*clean_up(char *line);
char		*get_next_line(int fd);
/*frees/free.c*/
int			free_n_return(char **str, char *temp, char *msg);
/*errors/errors.c*/
int			err_msg_std(char *msg);
/*errors/detailed_errors.c*/
int			read_files(char *file);
void		detailed_err_msg_order(char *path);
void		mulitiple_de_msg(char *path1, char *path2);
/*main.c*/
void		mlx_setup(t_data *data);
void		m_texture_setup(t_data *data);
void		texture_setup(t_texture *texture);

#endif

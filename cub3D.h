/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:25:31 by msisto            #+#    #+#             */
/*   Updated: 2025/12/17 14:36:52 by msisto           ###   ########.fr       */
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

# define WIN_HEIGHT 480
# define WIN_WIDTH 640
# define ESC 65307

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
	t_texture	texture;
	t_ray		ray;
	char		**map;
	int			**textures;
	t_map		map_info;
}	t_data;

/*datasetup.c*/
void	ray_set(t_ray *ray);
void	player_setup(t_player *player);
void	data_setup(t_data *data);
/*raycast.c*/
void	init_ray_info(int x, t_ray *ray, t_player *player);
void	start_dda(t_ray *ray, t_player *player);
void	perform_dda(t_data *data, t_ray *ray);
void	line_calc(t_data *data, t_ray *ray, t_player *player);
void	raycasting(t_player *player, t_data *data);
/*hook.c*/
void	on_key_press_exit(t_data *data);
int		on_keypress(int keysym, t_data *data);
/*parse_map.c*/
int		check_file_type(char *file, char *type);
void	map_setup(t_map *map_info);
void	map_pop(t_map *map_info, char *path);
void	parse_map(t_data *data, char *path);
/*parse_texture.c*/
void	texture_setup(t_texture *texture);
void	parse_textures(t_data *data, void *mlx);
/*utils.c*/
int		count_lines(char *file);
int		count_lines_arr(char **arr);
void	free_char_array(char **arr);
/*main.c*/
void	mlx_setup(t_data *data);
void	m_texture_setup(t_data *data);
void	texture_setup(t_texture *texture);
void	parse_data(t_data *data, char *path);

#endif

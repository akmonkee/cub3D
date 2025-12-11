/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:25:31 by msisto            #+#    #+#             */
/*   Updated: 2025/12/11 12:19:50 by msisto           ###   ########.fr       */
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
# include <math.h>
# include "mlx/mlx.h"

# define WIN_HEIGHT 480
# define WIN_WIDTH 640

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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_player	player;
	t_ray		ray;
	char		**map;
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
/*main.c*/

#endif

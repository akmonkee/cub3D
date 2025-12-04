/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/04 12:53:20 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_set(t_ray *ray)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->camera_x = 0;
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->step_x = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->perpwalldist = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_ray_info(int x, t_ray *ray) /*neeed to add t_player struct*/
{
	ray_set(ray);
	ray->camera_x = 2 * x / /*screen height*/ - 1;
	ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = 0; /*player x*/
	ray->map_y = 0; /*player y*/
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
}

void	start_dda(t_ray *ray)
{
	if (ray->raydir_x < 0) /*neeed to add t_player struct*/
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->deltadist_y;
	}
}

void	perform_dda(t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		/*need to add a check to see if the ray hit the map border and break the while*/
		if (/*need to add a map check to see if the ray hit a wall*/)
			hit = 1;
	}
}

void	line_calc(t_ray *ray) /*need to add player struct*/
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(/*window height*/ / ray->perpwalldist);
	ray->draw_start = -ray->line_height / 2 + /*window height*/ / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + /*window height*/ / 2;
	if (ray->draw_end >= /*window height*/)
		ray->draw_end = /*window height*/ - 1;
}

int	main(void)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray->pos_x = 0;
	ray->pos_y = 0;
	ray->dir_x = -1;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	while (1)
	{
		while (x < /*screen height*/)
		{
			init_ray_info(x, &ray);
			start_dda(&ray);
			line_calc(&ray);
			x++;
		}
	}
	return (0);
}

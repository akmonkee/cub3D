/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/03 14:13:55 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	t_raycast	ray;

	ray->pos_x = 0;
	ray->pos_y = 0;
	ray->dir_x = -1;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	while (1)
	{
		int	x;

		x = 0;
		while (x < /*map width*/)
		{
			ray->camera_x = 2 * x / /*map width needs to be double here*/ - 1;
			ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
			ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
			/*---------------------------------------------------*/
			ray->map_x = (int) ray->pos_x;
			ray->map_y = (int) ray->pos_y;
			/*---------------------------------------------------*/
			ray->deltadist_x = fabs(1 / ray->raydir_x);
			ray->deltadist_y = fabs(1 / ray->raydir_y);
			ray->hit = 0;
			/*---------------------------------------------------*/
			if (ray->raydir_x < 0)
			{
				ray->step_x = -1;
				ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
			}
			else
			{
				ray->step_x = 1;
				ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
			}
			/*---------------------------------------------------*/
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
			/*---------------------------------------------------*/
			while (ray->hit == 0)
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
				if (/*check if ray hit a wall*/)
					ray->hit = 1;
			}
			/*---------------------------------------------------*/
			if (ray->side == 0)
				ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
			else
				ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
			/*---------------------------------------------------*/
			ray->line_height = (int)(/*map height*/ / ray->perpwalldist);
			ray->draw_start = -ray->line_height / 2 + /*map height*/ / 2;
			if (ray->draw_start < 0)
				ray->draw_start = 0;
			ray->draw_end = ray->line_height / 2 + /*map height*/ / 2;
			if (ray->draw_end >= /*map height*/)
				ray->draw_end = /*map height*/ - 1;
			x++;
		}
	}
	return (0);
}

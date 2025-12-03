/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/03 13:59:42 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	struct s_raycast	t_ray;

	t_ray->pos_x = 0;
	t_ray->pos_y = 0;
	t_ray->dir_x = -1;
	t_ray->dir_y = 0;
	t_ray->plane_x = 0;
	t_ray->plane_y = 0->66;
	while (1)
	{
		int	x;

		x = 0;
		while (x < /*map width*/)
		{
			t_ray->camera_x = 2 * x / /*map width needs to be double here*/ - 1;
			t_ray->raydir_x = t_ray->dir_x + t_ray->plane_x * t_ray->camera_x;
			t_ray->raydir_y = t_ray->dir_y + t_ray->plane_y * t_ray->camera_x;
			/*---------------------------------------------------*/
			t_ray->map_x = (int) t_ray->pos_x;
			t_ray->map_y = (int) t_ray->pos_y;
			/*---------------------------------------------------*/
			t_ray->deltadist_x = fabs(1 / t_ray->raydir_x);
			t_ray->deltadist_y = fabs(1 / t_ray->raydir_y);
			t_ray->hit = 0;
			/*---------------------------------------------------*/
			if (t_ray->raydir_x < 0)
			{
				t_ray->step_x = -1;
				t_ray->sidedist_x = (t_ray->pos_x - t_ray->map_x) * t_ray->deltadist_x;
			}
			else
			{
				t_ray->step_x = 1;
				t_ray->sidedist_x = (t_ray->map_x + 1->0 - t_ray->pos_x) * t_ray->deltadist_x;
			}
			/*---------------------------------------------------*/
			if (t_ray->raydir_y < 0)
			{
				t_ray->step_y = -1;
				t_ray->sidedist_y = (t_ray->pos_y - t_ray->map_y) * t_ray->deltadist_y;
			}
			else
			{
				t_ray->step_y = 1;
				t_ray->sidedist_y = (t_ray->map_y + 1->0 - t_ray->pos_y) * t_ray->deltadist_y;
			}
			/*---------------------------------------------------*/
			while (t_ray->hit == 0)
			{
				if (t_ray->sidedist_x < t_ray->sidedist_y)
				{
					t_ray->sidedist_x += t_ray->deltadist_x;
					t_ray->map_x += t_ray->step_x;
					t_ray->side = 0;
				}
				else
				{
					t_ray->sidedist_y += t_ray->deltadist_y;
					t_ray->map_y += t_ray->step_y;
					t_ray->side = 1;
				}
				if (/*check if ray hit a wall*/)
					t_ray->hit = 1;
			}
			/*---------------------------------------------------*/
			if (t_ray->side == 0)
				t_ray->perpwalldist = (t_ray->sidedist_x - t_ray->deltadist_x);
			else
				t_ray->perpwalldist = (t_ray->sidedist_y - t_ray->deltadist_y);
			/*---------------------------------------------------*/
			t_ray->line_height = (int)(/*map height*/ / t_ray->perpwalldist);
			t_ray->draw_start = -t_ray->line_height / 2 + /*map height*/ / 2;
			if (t_ray->draw_start < 0)
				t_ray->draw_start = 0;
			t_ray->draw_end = t_ray->line_height / 2 + /*map height*/ / 2;
			if (t_ray->draw_end >= /*map height*/)
				t_ray->draw_end = /*map height*/ - 1;
			x++;
		}
	}
	return (0);
}

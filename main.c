/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/15 12:24:59 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*need to add a clean exit function for the 2 if statements*/
void	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit(1);
	return ;
}

void	texture_setup(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->size = 64;
	texture->step = 0.0;
	texture->pos = 0.0;
	texture->x = 0;
	texture->y = 0;
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		exit(1);
	data_setup(&data);
	mlx_setup(&data);
	ray_set(&data.ray);
	raycasting(&data.player, &data);
	return (0);
}

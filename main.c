/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/11 14:54:21 by msisto           ###   ########.fr       */
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

int	main(void)
{
	t_data		data;

	data_setup(&data);
	mlx_setup(&data);
	ray_set(&data.ray);
	raycasting(&data.player, &data);
	return (0);
}

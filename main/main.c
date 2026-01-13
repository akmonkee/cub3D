/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2026/01/13 12:27:44 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		exit(1);
	parse_data(&data, argv[1]);
	//ray_set(&data.ray);
	//raycasting(&data.player, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

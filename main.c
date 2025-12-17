/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/17 13:24:48 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*need to add a clean exit function for the 2 if statements*/
void	mlx_setup(t_data *data)
{
	mlx_init(data->mlx);
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

/*need to add a function to convert xmp files into img for mlx*/
void	m_texture_setup(t_data *data)
{
	data->m_texture = ft_calloc(5, sizeof * data->m_texture);
	if (!data->m_texture)
		exit(1);
	data->m_texture[0] = NULL;
	data->m_texture[1] = NULL;
	data->m_texture[2] = NULL;
	data->m_texture[3] = NULL;
}

void	parse_data(t_data *data, char *path)
{
	data_setup(data);
	mlx_setup(data);
	parse_map(data, path);
	data->win_height = WIN_HEIGHT;
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		exit(1);
	free(argv);
	parse_data(&data, argv[1]);
	ray_set(&data.ray);
	raycasting(&data.player, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:53:24 by msisto            #+#    #+#             */
/*   Updated: 2026/01/16 12:28:06 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*need to add a clean exit function for the 2 if statements*/
void	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		on_key_press_exit(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
	{
		on_key_press_exit(data);
		exit(1);
	}
	return ;
}

void	parse_data(t_data *data, char *path)
{
	data_setup(data);
	mlx_setup(data);
	parse_map(data, path);
	parse_player(data);
}

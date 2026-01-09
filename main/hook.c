/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:46:55 by msisto            #+#    #+#             */
/*   Updated: 2026/01/09 13:47:10 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	on_key_press_exit(t_data *data)
{
	if (!data)
		return ;
	if (data->mlx)
	{
		if (data->win)
		{
			mlx_destroy_window(data->mlx, data->win);
			free(data->win);
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->texture.north)
		free(data->texture.north);
	if (data->texture.south)
		free(data->texture.south);
	if (data->texture.west)
		free(data->texture.west);
	if (data->texture.east)
		free(data->texture.east);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
	{
		on_key_press_exit(data);
		exit(0);
	}
	return (0);
}

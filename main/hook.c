/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:46:55 by msisto            #+#    #+#             */
/*   Updated: 2026/01/19 13:14:58 by msisto           ###   ########.fr       */
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
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map_info.content)
		free_tab((void **)data->map_info.content);
	if (data->map)
		free_tab((void **)data->map);
	if (data->texture.north)
		free(data->texture.north);
	if (data->texture.south)
		free(data->texture.south);
	if (data->texture.west)
		free(data->texture.west);
	if (data->texture.east)
		free(data->texture.east);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	if (data->textures)
		free_tab((void **)data->textures);
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

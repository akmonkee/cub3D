/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:46:55 by msisto            #+#    #+#             */
/*   Updated: 2026/01/23 14:17:30 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	t_struct_free(t_texture *texture)
{
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->west)
		free(texture->west);
	if (texture->east)
		free(texture->east);
	if (texture->floor)
		free(texture->floor);
	if (texture->ceiling)
		free(texture->ceiling);
}

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
	t_struct_free(&data->texture);
	if (data->map_info.content)
		free_tab((void **)data->map_info.content);
	if (data->map)
		free_tab((void **)data->map);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	if (data->textures)
		free_tab((void **)data->textures);
}

int	quit(t_data *data)
{
	free_exit(data);
	return (0);
}

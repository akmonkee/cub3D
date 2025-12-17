/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:56:54 by msisto            #+#    #+#             */
/*   Updated: 2025/12/17 14:37:19 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	parse_textures(t_data *data, void *mlx)
{
	texture_setup(&data->texture);
	
}

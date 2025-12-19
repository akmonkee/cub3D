/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:53:24 by msisto            #+#    #+#             */
/*   Updated: 2025/12/19 11:53:51 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_data(t_data *data, char *path)
{
	data_setup(data);
	mlx_setup(data);
	parse_map(data, path);
	parse_textures(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/11 12:19:08 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	t_data		data;

	data_setup(&data);
	ray_set(&data.ray);
	raycasting(&data.player, &data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:03:30 by msisto            #+#    #+#             */
/*   Updated: 2026/01/23 14:21:29 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_press_handler(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == ESC)
		quit(data);
	if (key == 65361)
		data->player.rotate -= 1;
	if (key == 65363)
		data->player.rotate += 1;
	return (0);
}

int	key_release_handler(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == ESC)
		quit(data);
	if (key == 65361 && data->player.rotate == -1)
		data->player.rotate = 0;
	if (key == 65363 && data->player.rotate == 1)
		data->player.rotate = 0;
	return (0);
}

void	input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quit, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release_handler, data);
}

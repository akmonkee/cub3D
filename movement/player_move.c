/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:22:53 by msisto            #+#    #+#             */
/*   Updated: 2026/01/23 14:24:50 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}

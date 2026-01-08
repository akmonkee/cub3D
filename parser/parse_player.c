/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:16:14 by msisto            #+#    #+#             */
/*   Updated: 2026/01/08 14:37:41 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_player_pos(size_t x, size_t y, t_player *player)
{
	player->pos_x = (double)x;
	player->pos_y = (double)y;
}

void	get_player_pos_pl(t_map *map, t_player *player)
{
	int		map_len;
	int		i;
	size_t	temp_len;
	size_t	j;

	i = map->lst_itr;
	map_len = str_arr_len(map->content);
	temp_len = 0;
	while (i < map_len)
	{
		j = 0;
		temp_len = ft_strlen(map->content[i]);
		while (j < temp_len)
		{
			if (is_present(map->content[i][j]))
				set_player_pos(j, (size_t)i, player);
			j++;
		}
		i++;
	}
}

void	parse_player(t_data *data)
{
	player_setup(&data->player);
	get_player_pos_pl(&data->map_info, &data->player);
}

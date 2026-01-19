/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:28:40 by msisto            #+#    #+#             */
/*   Updated: 2026/01/19 13:19:15 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_color(char *color_arr)
{
	char	**color_split;
	int		color;
	int		r;
	int		g;
	int		b;

	color_split = ft_split(color_arr, ',');
	if (!color_split || !color_split[0])
		return (free_tab((void **)color_split), -1);
	if (str_arr_len(color_split) != 3)
		return (free_tab((void **)color_split), -1);
	r = ft_atoi(color_split[0]);
	g = ft_atoi(color_split[1]);
	b = ft_atoi(color_split[2]);
	color = (r << 16) | (g << 8) | b;
	free_tab((void **)color_split);
	return (color);
}

int	assign_colors(char **content, int i, t_map *map_info)
{
	char	**split_result;

	split_result = ft_split(content[i], ' ');
	if (!split_result || !split_result[0])
		return (free_tab((void **)split_result), 0);
	if (ft_strcmp(split_result[0], "F") == 0)
		map_info->floor_color = get_color(split_result[1]);
	else if (ft_strcmp(split_result[0], "C") == 0)
		map_info->ceiling_color = get_color(split_result[1]);
	free_tab((void **)split_result);
	map_info->lst_itr = i + 1;
	return (1);
}

int	set_colors(t_map *map_info, int lines)
{
	int	i;
	int	k;

	i = 0;
	if (map_info->content_order != 1)
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	k = 0;
	while (i < lines)
	{
		if (map_info->floor_color == -1 || map_info->ceiling_color == -1)
		{
			if (map_info->content[i][0] == 'F'
					|| map_info->content[i][0] == 'C')
			{
				if (!assign_colors(map_info->content, i, map_info))
					return (detailed_err_msg_order(COLOR_MSG), 0);
				k = i + 1;
			}
		}
		i++;
	}
	if (map_info->ceiling_color < 0 || map_info->floor_color < 0)
		return (detailed_err_msg_order(COLOR_NEG), 0);
	if (!check_for_map(map_info, lines, k))
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	map_info->content_order = 2;
	return (1);
}

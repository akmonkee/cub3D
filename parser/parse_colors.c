/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:28:40 by msisto            #+#    #+#             */
/*   Updated: 2026/01/21 12:33:00 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	*get_color(char *line)
{
	char	**color_split;
	int		*rgb;

	color_split = ft_split(line, ',');
	if (!color_split || !color_split[0])
		return (free_tab((void **)color_split), NULL);
	if (str_arr_len(color_split) != 3)
		return (free_tab((void **)color_split), NULL);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (free_tab((void **)color_split), NULL);
	rgb[0] = ft_atoi(color_split[0]);
	rgb[1] = ft_atoi(color_split[1]);
	rgb[2] = ft_atoi(color_split[2]);
	free_tab((void **)color_split);
	return (rgb);
}

void	assign_colors(t_texture *tex, char *line)
{
	char	**split_result;

	split_result = ft_split(line, ' ');
	if (split_result[0][0] == 'C')
		tex->ceiling = get_color(split_result[1]);
	else
		tex->floor = get_color(split_result[1]);
	free_tab((void **)split_result);
}

int	set_colors(t_texture *tex, t_map *map_info, int lines)
{
	int	i;
	int	k;

	i = 0;
	if (map_info->content_order != 1)
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	k = 0;
	while (i < lines)
	{
		if (map_info->content[i][0] == 'C' || map_info->content[i][0] == 'F')
		{
			assign_colors(tex, map_info->content[i]);
			map_info->lst_itr = i + 1;
			k = i + 1;
		}
		i++;
	}
	if (!check_for_map(map_info, lines, k))
		return (detailed_err_msg_order(EXPECTED_MSG), 0);
	map_info->content_order = 2;
	return (1);
}

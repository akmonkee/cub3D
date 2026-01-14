/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:29:39 by msisto            #+#    #+#             */
/*   Updated: 2026/01/14 12:58:43 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_top_bot(t_map *map_info, char **map)
{
	int	j;
	int	i;

	j = 0;
	i = map_info->lst_itr;
	while (map[i][j])
	{
		if (map[map_info->lst_itr][j] != '1'
			&& map[map_info->lst_itr][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	while (map[map_info->lst_itr + map_info->height - 1][j])
	{
		if (map[map_info->lst_itr + map_info->height - 1][j] != '1'
			&& map[map_info->lst_itr + map_info->height - 1][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	check_surrounded(t_map *map_info, char **map)
{
	int	i;
	int	len;

	if (!map)
		return (0);
	i = map_info->lst_itr;
	if (!check_top_bot(map_info, map))
		return (0);
	while (i < map_info->lst_itr + map_info->height)
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (0);
		if (len > 0)
		{
			if (map[i][len - 1] != '1' && map[i][len
				- 1] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_valid_chars(t_map *map_info, char **map)
{
	int		i;
	size_t	j;
	int		map_len;
	char	c;

	i = map_info->lst_itr;
	map_len = str_arr_len(map);
	while (i < map_len)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			c = map[i][j];
			if (!check_one(c))
			{
				printf("Error\nInvalid char: %c\n", c);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_data *data, t_map *map_info)
{
	mod_lst_it(map_info);
	get_h_w(map_info);
	if (map_info->content_order != 2)
		return ;
	if (!check_surrounded(map_info, data->map))
	{
		err_msg_std("The map is not surrounded");
		return ;
	}
	if (!check_valid_chars(map_info, data->map))
		return ;
	if (!has_holes(data->map))
	{
		err_msg_std("Can not contain empty spaces inside the map");
		return ;
	}
	map_info->content_order = 3;
	return ;
}

int	has_holes(char **map)
{
	int	arr_len;
	int	i;

	arr_len = str_arr_len_eof(map);
	i = 0;
	while (i < arr_len)
	{
		if (check_instances(map[i]))
		{
			if (!check_zero(map, map[i], i))
				return (0);
		}
		i++;
	}
	i = 0;
	while (i < arr_len)
	{
		if (check_instances(map[i]))
		{
			if (!check_holes(map, map[i], i))
				return (0);
		}
		i++;
	}
	return (1);
}

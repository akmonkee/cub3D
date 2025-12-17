/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:24:17 by msisto            #+#    #+#             */
/*   Updated: 2025/12/17 14:05:21 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*need to add a check if the path is shorter than 5*/
int	check_file_type(char *file, char *type)
{
	char	*dot;
	int		i;
	int		j;

	if (!file)
		return (0);
	dot = malloc(sizeof(char) * 5);
	if (!dot)
		return (0);
	i = (int)ft_strlen(file) - 5;
	j = -1;
	while (file[i] != '\0')
	{
		dot[++j] = file[++i];
	}
	dot[j] = '\0';
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
		return (free(dot), 1);
	else
		return (free(dot), 0);
}

void	map_setup(t_map *map_info)
{
	map_info->content = NULL;
	map_info->textures = NULL;
	map_info->ceiling_color = -1;
	map_info->floor_color = -1;
	map_info->height = 0;
	map_info->width = 0;
	map_info->content_order = 0;
}

int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("cub3D");
		exit(0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	free_char_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	map_pop(t_map *map_info, char *path, void *mlx)
{
	int	lines;

	lines = count_lines(path);
	map_info->content = ft_calloc(sizeof(char *), (lines + 1));
	map_info->content[lines] = NULL;
	if (!map_info->content)
	{
		free_char_array(map_info->content);
		map_info->content = NULL;
		return ;
	}
	parse_textures(map_info, mlx);
}

void	parse_map(t_data *data, char *path)
{
	struct stat	buffer;

	if (!check_file_type(path, ".cub"))
		return ;
	if (stat(path, &buffer) != 0)
	{
		printf("Error\nFile not found %s\n", path);
		return ;
	}
	map_setup(&data->map_info);
	map_pop(&data->map_info, path, data->mlx);
}

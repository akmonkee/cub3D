/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:12:45 by msisto            #+#    #+#             */
/*   Updated: 2026/01/19 13:18:25 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

int	free_n_return(char **str, char *temp, char *msg)
{
	free_tab((void **)str);
	if (temp)
		free(temp);
	temp = NULL;
	if (msg)
		err_msg_std(msg);
	return (0);
}

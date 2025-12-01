/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:24:33 by msisto            #+#    #+#             */
/*   Updated: 2025/12/01 13:43:22 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	double	posx = 0;
	double	posy = 0;

	double	dirx = -1;
	double	diry = 0;
	double	planex = 0;
	double	planey = 0.66;

	while (1)
	{
		int	x = 0;

		while (x < /*map width*/)
		{
			double	cameraX = 2 * x / /*map width needs to be double here*/ - 1;
			double	raydirx = dirx + planex * camerax;
			double	raydiry = diry + planey * camerax;

			int	mapx = /*posx casted to int*/
			int	mapy = /*posy casted to int*/

			double	sidedistx;
			double	sidedisty;

			double	deltadistx = fabs(1 / raydirx);
			double	deltadisty = fabs(1 / raydiry);

			double	perpwalldist;

			int	stepx;
			int	stepy;

			int	hit = 0;
			int	side;

			if (raydirx < 0)
			{
				stepx = -1;
				sidedistx = (posx - mapx) * deltadistx;
			}
			else
			{
				stepx = 1;
				sidedistx = (mapx + 1.0 - posx) * deltadistx;
			}
			if (raydiry < 0)
			{
				stepy = -1;
				sidedisty = (posy - mapy) * deltadisty;
			}
			else
			{
				stepy = 1;
				sidedisty = (mapy + 1.0 - posy) * deltadisty;
			}

			while (hit == 0)
			{
				if (sidedistx < sidedisty)
				{
					sidedistx += deltadistx;
					mapx += stepx;
					side = 0;
				}
				else
				{
					sidedisty += deltadisty;
					mapy += stepy;
					side = 1;
				}
				if (/*check if ray hit a wall*/)
					hit = 1;
			}

			if (side == 0)
				perpwalldist = (sidedistx - deltadistx);
			else
				perpwalldist = (sidedisty - deltadisty);

			int	lineheight = (int)(/*map height*/ / perpwalldist);

			int	drawstart = -lineheight / 2 + /*map height*/ / 2;
			if (drawstart < 0)
				drawstart = 0;
			int	drawend = lineheight / 2 + /*map height*/ / 2;
			if (drawend >= /*map height*/)
				drawend = /*map height*/ - 1;
			x++;
		}
	}
	return (0);
}

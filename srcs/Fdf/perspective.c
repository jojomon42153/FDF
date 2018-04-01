/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   perspective.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 19:15:21 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 19:15:21 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int			perspective(t_map *map)
{
	int i;
	int j;
	int l;

	i = 0;
	l = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->tab[i][j].x = j * map->zoom + map->begx + l + map->tab[i][j].z
				* map->z_size;
			if (map->tab[i][j].z != 0)
				map->tab[i][j].y = i * map->zoom + map->begy - map->tab[i][j].z
					* map->z_size;
			else
				map->tab[i][j].y = i * map->zoom + map->begy;
			j++;
		}
		i++;
		l += map->zoom / 2;
	}
	return (SUCCESS);
}

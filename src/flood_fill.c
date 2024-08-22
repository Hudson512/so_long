/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:29:24 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/16 14:31:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(char **map, t_point size, t_point cur, char *to_fill)
{
	int	i;

	i = 0;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	while (to_fill[i])
	{
		if (to_fill[i] == (char)map[cur.y][cur.x])
		{
			map[cur.y][cur.x] = 'F';
			fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
			fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
			fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
			fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
		}
		i++;
	}
}

void	fill_exit(char **map, t_point size, t_point cur, char to_fill)
{
	if (to_fill != map[cur.y][cur.x])
	{
		map[cur.y][cur.x] = '0';
		return ;
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	map[cur.y][cur.x] = '0';
	fill_exit(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_exit(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
	fill_exit(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_exit(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, "P0C");
	fill_exit(tab, size, begin, 'F');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:22:57 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/22 16:21:16 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_border_array(char **arr, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (cols - 1))
	{
		if (arr[0][j] != '1' || arr[rows - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < rows)
	{
		if (arr[i][0] != '1' || arr[i][cols - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_flood_fill(char **map, t_point size, t_point cordenadas_p)
{
	flood_fill(map, size, cordenadas_p);
	return (have_char_in_str(map));
}

int	have_char_in_str(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'P')
				return (0);
	}
	return (1);
}

int	have_char_in_map(char **map)
{
	int x;
	int y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'C')
				return (0);
	}
	return (1);
}

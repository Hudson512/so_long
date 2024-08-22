/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 07:36:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/22 13:26:53 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_innit(t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	temp->fd = 0;
	temp->rows = 0;
	temp->cols = 0;
	temp->character = 0;
	temp->exit = 0;
	temp->collectibles = 0;
	temp->bytesRead = 0;
	temp->arr = NULL;
	temp->arr_backup = NULL;
	temp->read_line = NULL;
}

void	print_file_map(t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	ft_printf("##### Dados do ficheiro #####\n");
	ft_printf("FD: %d\n", temp->fd);
	ft_printf("Rows: %d\n", temp->rows);
	ft_printf("Cols: %d\n", temp->cols);
	ft_printf("P: %d\n", temp->character);
	ft_printf("E: %d\n", temp->exit);
	ft_printf("C: %d\n", temp->collectibles);
	print_array_map(temp->arr);
	ft_printf("#############################\n");
	print_array_map(temp->arr_backup);
	ft_printf("#############################\n");
}

int	get_map_arr(char *file_path, t_info_file **file, int state)
{
	t_info_file	*temp;
	int			len;
	int			check_fill;

	temp = *file;
	len = (temp->rows * temp->cols);
	if (!state)
		return (0);
	if (ft_check_fd(temp->fd = open(file_path, O_RDONLY)) == 0)
		return (0);
	if ((temp->read_line = (char *)ft_calloc((len), sizeof(char))) == NULL)
		return ((print_map_error(temp->read_line, file)) == 1);
	if ((temp->bytesRead = read(temp->fd, temp->read_line, len)) == -1)
		return ((print_map_error(temp->read_line, file)) == 1);
	if ((temp->arr = ft_split(temp->read_line, 10)) == NULL)
		return ((print_map_error(temp->read_line, file)) == 1);
	if ((temp->arr_backup = ft_split(temp->read_line, 10)) == NULL)
		return ((print_map_error(temp->read_line, file)) == 1);
	check_fill = check_flood_fill(temp->arr, ((t_point){temp->cols,
				temp->rows}), get_char_position('P', temp->arr));
	if (!check_fill)
		print_map_error(temp->read_line, file);
	else
		free(temp->read_line);
	return (check_border_array(temp->arr_backup, temp->rows, temp->cols)
		&& check_fill && (close(temp->fd) == 0));
}

t_point	get_char_position(char ch, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ch)
				return ((t_point){x, y});
		}
	}
	return ((t_point){0, 0});
}

void	print_array_map(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		ft_printf("The array is empty or null.\n");
	else
	{
		while (arr[++i] != NULL)
			ft_printf("%s\n", arr[i]);
	}
}

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

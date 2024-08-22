/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 07:36:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/22 17:38:57 by hmateque         ###   ########.fr       */
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
	temp->bytes_read = 0;
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

	temp = *file;
	len = (temp->rows * temp->cols);
	if (!state)
		return (0);
	temp->fd = open(file_path, O_RDONLY);
	if (ft_check_fd(temp->fd) == 0)
		return (0);
	temp->read_line = (char *)ft_calloc((len), sizeof(char));
	if (temp->read_line == NULL)
		return ((print_map_error(temp->read_line, file)) == 1);
	temp->bytes_read = read(temp->fd, temp->read_line, len);
	temp->arr = ft_split(temp->read_line, 10);
	if (temp->arr == NULL || !check_border_array(temp->arr, temp->rows, temp->cols))
		return ((print_map_error(temp->read_line, file)) == 1);
	temp->arr_backup = ft_split(temp->read_line, 10);
	temp->bytes_read = check_flood_fill(temp->arr, ((t_point){temp->cols,
				temp->rows}), get_char_position('P', temp->arr));
	if (!temp->bytes_read)
		print_map_error(temp->read_line, file);
	else
		free(temp->read_line);
	return (temp->bytes_read && (close(temp->fd) == 0));
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

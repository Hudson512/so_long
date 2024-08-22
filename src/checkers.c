/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:31:47 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/21 08:21:46 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_fd(int fd)
{
	if (fd == -1)
	{
		print_file_error();
		return (0);
	}
	return (1);
}

int	ft_check_file_extesion(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > str_len)
		return (0);
	return (ft_strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0);
}

void	check_caracter_file(t_info_file **file, char c)
{
	t_info_file	*temp;

	temp = *file;
	if (c == 'P')
		temp->character++;
	else if (c == 'E')
		temp->exit++;
	else if (c == 'C')
		temp->collectibles++;
}

int	ft_check_file_dimensions(t_info_file **file)
{
	int			temp_cols;
	t_info_file	*temp;

	temp = *file;
	while ((temp->read_line = get_next_line(temp->fd)) != NULL)
	{
		temp_cols = 0;
		while (is_valid_char(temp->read_line[temp_cols]))
			check_caracter_file(file, temp->read_line[temp_cols++]);
		temp_cols++;
		if (temp->rows == 0)
			temp->cols = temp_cols;
		else if (temp_cols != temp->cols)
			return (print_map_error(temp->read_line, file) == 1);
		temp->rows++;
		free(temp->read_line);
	}
	if (is_square(file) && (close(temp->fd) == 0))
		return (1);
	return ((print_map_error(temp->read_line, file)) == 1);
}

int	is_valid_char(char c)
{
	if ((c != '\0' && c != '\n') && (c == '1' || c == '0' || c == 'P'
			|| c == 'C' || c == 'E'))
		return (1);
	else
		return (0);
}

int	is_square(t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	if (temp->rows > (temp->cols - 1) || temp->rows < (temp->cols - 1))
		return (valid_characters(file));
	else
		return (0);
}

int	valid_characters(t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	if (temp->character == 1 && temp->exit == 1 && temp->collectibles > 0)
		return (1);
	else
		return (0);
}

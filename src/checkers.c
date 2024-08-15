/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:31:47 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/15 10:24:21 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_fd(int fd)
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
	char		*line;
	int			temp_cols;
	t_info_file	*temp;

	temp = *file;
	while ((line = get_next_line(temp->fd)) != NULL)
	{
		temp_cols = 0;
		while (line[temp_cols] != '\0' && line[temp_cols] != '\n'
			&& (line[temp_cols] == '1' || line[temp_cols] == '0'
				|| line[temp_cols] == 'P' || line[temp_cols] == 'C'
				|| line[temp_cols] == 'E'))
		{
			check_caracter_file(file, line[temp_cols]);
			temp_cols++;
		}
        temp_cols++;
		if (temp->rows == 0)
			temp->cols = temp_cols;
		else if (temp_cols != temp->cols)
			return (print_map_error(line, file) == 1);
		temp->rows++;
		free(line);
	}
	if (temp->rows > temp->cols || temp->rows < temp->cols
		&& (temp->character == 1 && temp->exit == 1 && temp->collectibles > 0))
	{
		close(temp->fd);
		return (1);
	}
	return (print_map_error(line, file) == 1);
}

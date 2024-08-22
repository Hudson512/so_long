/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:32:44 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/22 16:11:33 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_file_error(void)
{
	perror("Error opening the file");
}

int	print_map_error(char *str, t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	if (str != NULL)
		free(str);
	str = NULL;
	close(temp->fd);
	temp->bytes_read = write(2, "Error\n", 6);
	temp->bytes_read = write(2, "Check the map\n", 14);
	return (0);
}

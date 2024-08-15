/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:32:44 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/15 08:46:24 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_file_error(void)
{
	perror("Error opening the file");
}

int		print_map_error(char *str, t_info_file **file)
{
	t_info_file *temp;

	temp = *file;
	if (str != NULL)
		free(str);
	close(temp->fd);
	write(2, "Error\n", 6);
	write(2, "Check the map\n", 14);
	return (0);
}
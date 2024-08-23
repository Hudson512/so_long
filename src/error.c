/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:32:44 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/23 07:42:43 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_file_error(void)
{
	int	temp;

	temp = write(1, "Error\n", 6);
	(void)temp;
}

int	print_map_error(char *str, t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	if (str != NULL)
		free(str);
	str = NULL;
	close(temp->fd);
	return (0);
}

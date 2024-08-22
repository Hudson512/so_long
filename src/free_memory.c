/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:31:48 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/22 12:14:29 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_struct(t_info_file *file)
{
	int			i;

	if (file == NULL)
		return ;
	i = -1;
	if (file->arr != NULL)
	{
		while (file->arr[++i] != NULL)
			free(file->arr[i]);
		free(file->arr);
	}
	i = -1;
	if (file->arr_backup != NULL)
	{
		while (file->arr_backup[++i] != NULL)
			free(file->arr_backup[i]);
		free(file->arr_backup);
	}
	free(file);
	file = NULL;
}

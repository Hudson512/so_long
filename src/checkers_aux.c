/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:11:34 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/22 16:32:08 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

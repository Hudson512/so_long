/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:32:44 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/14 13:37:32 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_file_error(void)
{
	perror("Erro ao abrir o arquivo");
	exit(1);
}

void	print_map_error(void)
{
	write(2, "Error\n", 6);
	write(2, "Check the map\n", 14);
}
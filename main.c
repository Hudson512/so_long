/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/13 16:26:42 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info_file	*file;

	file = malloc(sizeof(t_info_file));
	if (ac == 2)
	{
		if(ft_check_file_extesion(av[1], ".ber"))
		{

			if ((file->fd = open(av[1], O_RDONLY)) == -1)
			{
				perror("Erro ao abrir o arquivo");
        		return 1;
			}
			//printf("%s\n", get_next_line(file->fd));
			ft_check_file_dimensions(&file);
			printf("rows: %d, cols: %d\n",file->rows, file->cols);
		}
		else
			printf("Error: <file_name>.ber\n");
	}
	return (0);
}
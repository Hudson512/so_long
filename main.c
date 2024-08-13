/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/13 13:04:17 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		if(ft_check_extesion(av[1], ".ber"))
		{

			if ((fd = open(av[1], O_RDONLY)) == -1)
			{
				perror("Erro ao abrir o arquivo");
        		return 1;
			}
			printf("OK\n");
		}
		else
			printf("Error: <file_name>.ber\n");
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/23 11:19:32 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info_mlx	*mlx;
	t_info_file	*file;
	t_database	*db;

	if (ac == 2 && ft_check_file_extesion(av[1], ".ber"))
	{
		file = malloc(sizeof(t_info_file));
		mlx = malloc(sizeof(t_info_mlx));
		db = malloc(sizeof(t_database));
		if (set_db(mlx, &file, &db, av[1]))
		{
			mlx->mlx = mlx_init();
			mlx->mlx_win = mlx_new_window(mlx->mlx, (file->cols - 1) * 50,
				file->rows * 50, "so_long");
			screen(mlx, file, 0);
			loop_mlx(mlx, db);
		}
		else
			file->bytes_read = write(1, "Error\n", 6);
		free_all(mlx, file, db);
	}
	else
		ft_printf("Error: >./so_long <file_name>.ber\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/21 16:42:26 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info_mlx *mlx;
	t_info_file *file;
	t_database	*db;

	file = malloc(sizeof(t_info_file));
	mlx = malloc(sizeof(t_info_mlx));
	db = malloc(sizeof(t_database));
	db->file = file;
	db->mlx = mlx; 
	if (ac == 2)
	{
		if (ft_check_file_extesion(av[1], ".ber"))
		{
			ft_map_innit(&file);
			file->fd = open(av[1], O_RDONLY);
			if (ft_check_fd(file->fd) && get_map_arr(av[1], &file,
				ft_check_file_dimensions(&file)))
			{
				mlx->mlx = mlx_init();
				mlx->mlx_win = mlx_new_window(mlx->mlx, (file->cols - 1) * 50, file->rows * 50,
					"so_long");
				screen(mlx, file);
				mlx_key_hook(mlx->mlx_win, key_hook, db);
				mlx_loop(mlx->mlx);
			}
		}
		else
			ft_printf("Error: <file_name>.ber\n");
	}
	free_struct(&file);
	free(mlx);
	return (0);
}

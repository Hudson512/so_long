/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/19 08:42:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info_mlx *mlx;
	t_info_file *file;

	file = malloc(sizeof(t_info_file));
	mlx = malloc(sizeof(t_info_mlx));
	mlx->img_widt = 2;
	mlx->img_heig = 2;
	if (ac == 2)
	{
		if (ft_check_file_extesion(av[1], ".ber"))
		{
			ft_map_innit(&file);
			file->fd = open(av[1], O_RDONLY);
			if (ft_check_fd(file->fd) && get_map_arr(av[1], &file,
					ft_check_file_dimensions(&file)))
			{
				// mlx->mlx = mlx_init();
				// mlx->mlx_win = mlx_new_window(mlx->mlx, 900, 800,
				// 		"Hello world!");
				// mlx->img = mlx_xpm_file_to_image(mlx->mlx, "./img/carro.xpm",
				// 		&mlx->img_widt, &mlx->img_heig);
				// mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
				// mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 150,
				// 	60);
				// mlx_loop(mlx->mlx);
			}
			else
				printf("Error: NNNN\n");
		}
		else
			printf("Error: <file_name>.ber\n");
	}
	free_struct(&file);
	free(mlx);
	return (0);
}

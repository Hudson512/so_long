/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/20 19:12:27 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info_mlx *mlx;
	t_info_file *file;

	file = malloc(sizeof(t_info_file));
	mlx = malloc(sizeof(t_info_mlx));
	
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
				mlx->img_bloco = mlx_xpm_file_to_image(mlx->mlx, "./img/will_50.xpm", &mlx->img_widt, &mlx->img_heig);
				mlx->img_estrada = mlx_xpm_file_to_image(mlx->mlx, "./img/estrada_50.xpm", &mlx->img_widt, &mlx->img_heig);
				mlx->img_saida = mlx_xpm_file_to_image(mlx->mlx, "./img/E.xpm", &mlx->img_widt, &mlx->img_heig);
				mlx->img_colecionaveis = mlx_xpm_file_to_image(mlx->mlx, "./img/C.xpm", &mlx->img_widt, &mlx->img_heig);
				mlx->img_c_b = mlx_xpm_file_to_image(mlx->mlx, "./img/TB.xpm", &mlx->img_widt, &mlx->img_heig);
				//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);

				int x = -1, y = -1;
				int i = -1, j = -1;
				while (file->arr_backup[++i])
				{
					j = -1;
					while (file->arr_backup[i][++j])
					{
						x = 50 * i;
						y = 50 * j;
						if (file->arr_backup[i][j] == '0')
							mlx->img = mlx->img_estrada;
						else if (file->arr_backup[i][j] == '1')
							mlx->img = mlx->img_bloco;
						else if (file->arr_backup[i][j] == 'E')
							mlx->img = mlx->img_saida;
						else if (file->arr_backup[i][j] == 'C')
							mlx->img = mlx->img_colecionaveis;
						else if (file->arr_backup[i][j] == 'P')
							mlx->img = mlx->img_c_b;
						mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, y, x);
					}
				}

				mlx_loop(mlx->mlx);
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

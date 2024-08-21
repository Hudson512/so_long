/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:32:18 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/21 12:53:35 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	screen(t_info_mlx **temp, t_info_file **temp2)
{
	t_point var;
	t_info_mlx *mlx;
	t_info_file *file;

	var.i = -1;
	mlx = *temp;
	file = *temp2;
	mlx->img_bloco = mlx_xpm_file_to_image(mlx->mlx, "./img/will_50.xpm", &mlx->img_widt, &mlx->img_heig);
	mlx->img_estrada = mlx_xpm_file_to_image(mlx->mlx, "./img/estrada_50.xpm", &mlx->img_widt, &mlx->img_heig);
	mlx->img_saida = mlx_xpm_file_to_image(mlx->mlx, "./img/E.xpm", &mlx->img_widt, &mlx->img_heig);
	mlx->img_colecionaveis = mlx_xpm_file_to_image(mlx->mlx, "./img/C.xpm", &mlx->img_widt, &mlx->img_heig);
	mlx->img_c_b = mlx_xpm_file_to_image(mlx->mlx, "./img/TB.xpm", &mlx->img_widt, &mlx->img_heig);
	while (file->arr_backup[++(var.i)])
	{
		var.j = -1;
		while (file->arr_backup[var.i][++(var.j)])
		{
			var.x = 50 * var.i;
			var.y = 50 * var.j;
			if (file->arr_backup[var.i][var.j] == '0')
				mlx->img = mlx->img_estrada;
			else if (file->arr_backup[var.i][var.j] == '1')
				mlx->img = mlx->img_bloco;
			else if (file->arr_backup[var.i][var.j] == 'E')
				mlx->img = mlx->img_saida;
			else if (file->arr_backup[var.i][var.j] == 'C')
				mlx->img = mlx->img_colecionaveis;
			else if (file->arr_backup[var.i][var.j] == 'P')
				mlx->img = mlx->img_c_b;
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, var.y, var.x);
		}
	}
}
void	move_w(char **arr, t_point pos)
{
	ft_printf("%d - %d -> %c\n", pos.x, pos.y, arr[pos.y - 1][pos.x]);
	if (arr[--(pos.y)][pos.x] != '1')
	{
		arr[pos.y][pos.x] = '0';
		arr[--(pos.y)][pos.x] = 'P';
	}
}

int	key_hook(int keycode, t_info_file **param)
{
	t_info_file *temp;

	temp = *param;
	
	print_array_map(temp->arr_backup);
	ft_printf("----------------------------\n");
	if (keycode == 119)
		move_w(temp->arr_backup ,get_char_position('P', temp->arr_backup));
	// else if (keycode == 97)
	// 	move_a(temp->arr_backup ,get_char_position('P', temp->arr_backup));
	// else if (keycode == 115)
	// 	move_s(temp->arr_backup ,get_char_position('P', temp->arr_backup));
	// else if (keycode == 100)
	// 	move_d(temp->arr_backup ,get_char_position('P', temp->arr_backup));
	return (0);
}

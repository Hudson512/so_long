/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:32:18 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/23 11:39:29 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_img(t_info_mlx *mlx, int react)
{
	mlx_destroy_image(mlx->mlx, mlx->img_carro);
	if (react == 1)
		mlx->img_carro = mlx_xpm_file_to_image(mlx->mlx, "./img/TC.xpm",
				&mlx->img_widt, &mlx->img_heig);
	else if (react == 2)
		mlx->img_carro = mlx_xpm_file_to_image(mlx->mlx, "./img/TE.xpm",
				&mlx->img_widt, &mlx->img_heig);
	else if (react == 3)
		mlx->img_carro = mlx_xpm_file_to_image(mlx->mlx, "./img/TB.xpm",
				&mlx->img_widt, &mlx->img_heig);
	else if (react == 4)
		mlx->img_carro = mlx_xpm_file_to_image(mlx->mlx, "./img/TD.xpm",
				&mlx->img_widt, &mlx->img_heig);
}

void	set_mlx(t_info_mlx *mlx)
{
	mlx->img_bloco = mlx_xpm_file_to_image(mlx->mlx, "./img/will_50.xpm",
			&mlx->img_widt, &mlx->img_heig);
	mlx->img_estrada = mlx_xpm_file_to_image(mlx->mlx, "./img/estrada_50.xpm",
			&mlx->img_widt, &mlx->img_heig);
	mlx->img_saida = mlx_xpm_file_to_image(mlx->mlx, "./img/E.xpm",
			&mlx->img_widt, &mlx->img_heig);
	mlx->img_colecionaveis = mlx_xpm_file_to_image(mlx->mlx, "./img/C.xpm",
			&mlx->img_widt, &mlx->img_heig);
	mlx->img_carro = mlx_xpm_file_to_image(mlx->mlx, "./img/TB.xpm",
			&mlx->img_widt, &mlx->img_heig);
}

void	rendering_img(t_info_mlx *mlx, t_info_file *file)
{
	t_point_1	var;

	var.i = -1;
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
				mlx->img = mlx->img_carro;
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, var.y,
				var.x);
		}
	}
}

void	screen(t_info_mlx *mlx, t_info_file *file, int react)
{
	if (react != 0)
		change_img(mlx, react);
	else
		set_mlx(mlx);
	rendering_img(mlx, file);
}

int	key_hook(int keycode, t_database *db)
{
	t_info_file	*file;
	t_info_mlx	*mlx;

	file = db->file;
	mlx = db->mlx;
	if (keycode == 119)
		move_w(get_char_position('P', file->arr_backup), mlx, file, db);
	else if (keycode == 97)
		move_a(get_char_position('P', file->arr_backup), mlx, file, db);
	else if (keycode == 115)
		move_s(get_char_position('P', file->arr_backup), mlx, file, db);
	else if (keycode == 100)
		move_d(get_char_position('P', file->arr_backup), mlx, file, db);
	else if (keycode == 65307)
		finished(db);
	return (0);
}

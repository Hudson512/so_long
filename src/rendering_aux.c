/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:19:08 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/23 12:01:34 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_point pos, t_info_mlx *mlx, t_info_file *file, t_database *db)
{
	if (file->arr_backup[pos.y - 1][pos.x] == 'C' || file->arr_backup[pos.y
		- 1][pos.x] == '0')
	{
		file->arr_backup[pos.y][pos.x] = '0';
		file->arr_backup[pos.y - 1][pos.x] = 'P';
		file->bytes_read++;
		ft_printf("Nº Moves: %d\n", file->bytes_read);
		screen(mlx, file, 1);
	}
	else if (file->arr_backup[pos.y - 1][pos.x] == 'E'
		&& have_char_in_map(file->arr_backup))
		finished(db);
}

void	move_s(t_point pos, t_info_mlx *mlx, t_info_file *file, t_database *db)
{
	if (file->arr_backup[pos.y + 1][pos.x] == 'C' || file->arr_backup[pos.y
		+ 1][pos.x] == '0')
	{
		file->arr_backup[pos.y][pos.x] = '0';
		file->arr_backup[pos.y + 1][pos.x] = 'P';
		file->bytes_read++;
		ft_printf("Nº Moves: %d\n", file->bytes_read);
		screen(mlx, file, 3);
	}
	else if (file->arr_backup[pos.y + 1][pos.x] == 'E'
		&& have_char_in_map(file->arr_backup))
		finished(db);
}

void	move_a(t_point pos, t_info_mlx *mlx, t_info_file *file, t_database *db)
{
	if (file->arr_backup[pos.y][pos.x - 1] == 'C'
		|| file->arr_backup[pos.y][pos.x - 1] == '0')
	{
		file->arr_backup[pos.y][pos.x] = '0';
		file->arr_backup[pos.y][pos.x - 1] = 'P';
		file->bytes_read++;
		ft_printf("Nº Moves: %d\n", file->bytes_read);
		screen(mlx, file, 2);
	}
	else if (file->arr_backup[pos.y][pos.x - 1] == 'E'
		&& have_char_in_map(file->arr_backup))
		finished(db);
}

void	move_d(t_point pos, t_info_mlx *mlx, t_info_file *file, t_database *db)
{
	if (file->arr_backup[pos.y][pos.x + 1] == 'C'
		|| file->arr_backup[pos.y][pos.x + 1] == '0')
	{
		file->arr_backup[pos.y][pos.x] = '0';
		file->arr_backup[pos.y][pos.x + 1] = 'P';
		file->bytes_read++;
		ft_printf("Nº Moves: %d\n", file->bytes_read);
		screen(mlx, file, 4);
	}
	else if (file->arr_backup[pos.y][pos.x + 1] == 'E'
		&& have_char_in_map(file->arr_backup))
		finished(db);
}

int	finished(t_database *db)
{
	t_info_file	*file;
	t_info_mlx	*mlx;

	file = db->file;
	mlx = db->mlx;
	mlx_destroy_image(mlx->mlx, mlx->img_bloco);
	mlx_destroy_image(mlx->mlx, mlx->img_estrada);
	mlx_destroy_image(mlx->mlx, mlx->img_saida);
	mlx_destroy_image(mlx->mlx, mlx->img_colecionaveis);
	mlx_destroy_image(mlx->mlx, mlx->img_carro);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free_struct(file);
	free(mlx->mlx);
	free(mlx);
	free(db);
	exit(0);
	return (0);
}

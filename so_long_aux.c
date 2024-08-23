/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:18:26 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/23 11:52:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_one(t_info_file *file, char *str)
{
	file->fd = open(str, O_RDONLY);
	if (ft_check_fd(file->fd) && get_map_arr(str, &file,
		ft_check_file_dimensions(&file)))
	{
		file->bytes_read = 0;
		return (1);
	}
	return (0);
}

int	set_db(t_info_mlx *mlx, t_info_file **file_temp, t_database  **db, char *str)
{
	int			status;
	t_info_file	*file;

	file = *file_temp;
	(*db)->file = file;
	(*db)->mlx = mlx;
	ft_map_innit(file_temp);
	status = check_one(file, str);
	return (status);
}

void	free_all(t_info_mlx *mlx, t_info_file *file, t_database  *db)
{
	free_struct(file);
	free(db);
	free(mlx);
}

void	loop_mlx(t_info_mlx *mlx, t_database *db)
{
	mlx_hook(mlx->mlx_win, 17, 0L, finished, db);
	mlx_key_hook(mlx->mlx_win, key_hook, db);
	mlx_loop(mlx->mlx);
}
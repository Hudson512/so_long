/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:17:14 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/15 10:47:56 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "src/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_file
{
	int	rows;
	int	cols;
	int	fd;
	int	character;
	int	exit;
	int	collectibles;
	char	**arr;
	int	bytesRead;
}	t_info_file;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_widt;
	int		img_heig;
}	t_info_mlx;

int		ft_check_file_extesion(const char *str, const char *suffix);
int 	ft_check_file_dimensions(t_info_file **file);
int		get_map_arr(char *file_path, t_info_file **file, int state);
int		print_map_error(char *str, t_info_file **file);
int		ft_check_fd(int fd);
void	check_caracter_file(t_info_file **file, char c);
void	ft_map_innit(t_info_file **file);
void	print_file_error(void);
void	print_array_map(char **arr);

#endif
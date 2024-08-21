/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:17:14 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/21 13:12:28 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "src/get_next_line/get_next_line.h"
# include "src/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_file
{
	int		rows;
	int		cols;
	int		fd;
	int		character;
	int		exit;
	int		collectibles;
	char	**arr;
	char	**arr_backup;
	char	*read_line;
	int		bytesRead;
}			t_info_file;

typedef struct s_temp
{
	int		x;
	int		y;
	int		i;
	int		j;
}			t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	void	*img_bloco;
	void	*img_estrada;
	void	*img_saida;
	void	*img_colecionaveis;
	void	*img_c_b;
	void	*img_c_d;
	void	*img_c_e;
	void	*img_c_c;
	int		img_widt;
	int		img_heig;
}			t_info_mlx;

typedef struct s_concat
{
	t_info_file	**file;
	t_info_mlx	**mlx;
}			t_database;

int			key_hook(int keycode, t_info_file **param);
int			ft_check_file_extesion(const char *str, const char *suffix);
int			check_border_array(char **arr, int rows, int cols);
int			ft_check_file_dimensions(t_info_file **file);
int			get_map_arr(char *file_path, t_info_file **file, int state);
int			check_flood_fill(char **map, t_point size, t_point cordenadas_p);
int			have_char_in_str(char **map);
int			is_square(t_info_file **file);
int			valid_characters(t_info_file **file);
int			print_map_error(char *str, t_info_file **file);
int			ft_check_fd(int fd);
int			is_valid_char(char c);
void		screen(t_info_mlx **temp, t_info_file **temp2);
void		fill(char **map, t_point size, t_point cur, char *to_fill);
void		fill_exit(char **map, t_point size, t_point cur, char to_fill);
void		flood_fill(char **tab, t_point size, t_point begin);
void		check_caracter_file(t_info_file **file, char c);
void		ft_map_innit(t_info_file **file);
void		print_file_error(void);
void		print_array_map(char **arr);
void		print_file_map(t_info_file **file);
void		free_struct(t_info_file **file);
t_point		get_char_position(char ch, char **map);

#endif
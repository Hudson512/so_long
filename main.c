/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:47:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/08 16:03:50 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_print_quadrado(t_data *img, int x, int y)
{
	// x = 25;
	// y = 25;
	int i = -1;
	while (++i <= 400)
		my_mlx_pixel_put(img, x++, y, 0x00FF0000);
	i = -1;
	while (++i <= 200)
		my_mlx_pixel_put(img, x, y++, 0x00FF0000);
	i = -1;
	while (++i <= 400)
		my_mlx_pixel_put(img, x--, y, 0x00FF0000);
	i = -1;
	while (++i <= 200)
		my_mlx_pixel_put(img, x, y--, 0x00FF0000);
}

void	ft_print_triangulo(t_data *img, int x, int y)
{
	x = 600;
	y = 0;
	int i = -1;
	int j = 0;
	while (++i <= 200)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		my_mlx_pixel_put(img, ++x, ++y, 0x00FF0000);
	}
	j = x;
	x = 600;
	y = 0;
	while (i-- > 0)
		my_mlx_pixel_put(img, --x, ++y, 0x00FF0000);
	// while (x < j)
	// 	my_mlx_pixel_put(img, ++x, y, 0x00FF0000);
	ft_print_quadrado(img, x, y);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_print_triangulo(&img, 0, 0);
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
	mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 07:36:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/15 10:53:13 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_innit(t_info_file **file)
{
	t_info_file	*temp;

	temp = *file;
	temp->fd = 0;
	temp->rows = 0;
	temp->cols = 0;
	temp->character = 0;
	temp->exit = 0;
	temp->collectibles = 0;
	temp->bytesRead = 0;
	temp->arr = NULL;
}

int	get_map_arr(char *file_path, t_info_file **file, int state)
{
	t_info_file	*temp;
	char		*buffer;
	int			len;
	int			i;

	temp = *file;
	len = temp->rows * temp->cols;
	if (!state)
		return (0);
	if (ft_check_fd(temp->fd = open(file_path, O_RDONLY)) == 0)
		return (0);
	if ((buffer = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	buffer[len + 1] = '\0';
	if ((temp->bytesRead = read(temp->fd, buffer, len + 1)) == -1)
		return (0);
	if ((temp->arr = ft_split(buffer, '\n')) == NULL)
		return (0);
	print_array_map(temp->arr);
	return (1);
}

void	print_array_map(char **arr)
{
	int i;

	i = -1;
	if (!arr)
		printf("The array is empty or null.\n");
	else
	{
		while (arr[++i] != NULL)
			printf("%s\n", arr[i]);
	}
}
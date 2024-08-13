/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:31:47 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/13 16:26:58 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_file_extesion(const char *str, const char *suffix)
{
	size_t str_len;
	size_t suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);

	if (suffix_len > str_len)
		return (0);
	return (ft_strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0);
}

int ft_check_file_dimensions(t_info_file **file)
{
    char *line;
    int temp_cols = 0;
    t_info_file *temp = *file;
    temp->rows = 0;
    temp->cols = 0;
    //printf("Antes do while: %s\n", get_next_line(file.fd));
    while ((line = get_next_line(temp->fd)) != NULL)
    {
        temp_cols = 0;
        printf("%s", line);
        while (line[temp_cols] != '\0' && line[temp_cols] != '\n')
            temp_cols++;
        if (temp->rows == 0)
            temp->cols = temp_cols;
        else if (temp_cols != temp->cols)
        {
            fprintf(stderr, "Erro: Linhas com números de colunas diferentes encontradas.\n");
            free(line);
            close(temp->fd);
            return -1;
        }

        temp->rows++;
        free(line);
    }
    close(temp->fd);
    return 0;
}

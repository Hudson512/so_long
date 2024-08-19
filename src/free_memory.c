/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:31:48 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/19 04:40:48 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_struct(t_info_file **file)
{
    t_info_file *temp;
    int i;
    
    if (file == NULL || *file == NULL)
        return;
    temp = *file;
    i = -1;
    if (temp->arr != NULL) {
        while (temp->arr[++i] != NULL)
            free(temp->arr[i]);
        free(temp->arr);
    }
    i = -1;
    if (temp->arr_backup != NULL) {
        while (temp->arr_backup[++i] != NULL)
            free(temp->arr_backup[i]);
        free(temp->arr_backup);
    }
    free(temp);
    *file = NULL;
}
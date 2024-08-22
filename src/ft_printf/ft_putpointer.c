/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:29:53 by hmateque          #+#    #+#             */
/*   Updated: 2024/05/24 07:57:08 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countpointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		count++;
		ptr = ptr / 16;
	}
	return (count);
}

int	ft_printpointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_printpointer(ptr / 16);
		ft_printpointer(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + 48);
		else
			ft_putchar(ptr - 10 + 'a');
	}
	return (ft_countpointer(ptr));
}

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len = write(1, "0x", 2);
	len += ft_printpointer(ptr);
	return (len);
}

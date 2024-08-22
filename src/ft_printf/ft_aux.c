/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:48 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/21 09:41:52 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_count_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static int	ft_nbrlen(long n)
{
	int	strlen;

	strlen = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		strlen++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (nbr == 0)
	{
		*(str + 0) = '0';
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		*(str + 0) = '-';
	}
	while (nbr > 0)
	{
		*(str + len--) = (48 + (nbr % 10));
		nbr /= 10;
	}
	return (str);
}

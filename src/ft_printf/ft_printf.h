/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:58:16 by hmateque          #+#    #+#             */
/*   Updated: 2024/08/21 09:41:14 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnumb(int n);
int		ft_putpointer(unsigned long long ptr);
int		ft_putunsigned(unsigned int n);
int		ft_puthexadecimal(unsigned int num, const char type);
char	*ft_itoa(int n);
size_t	ft_count_len(const char *str);

#endif

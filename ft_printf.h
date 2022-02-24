/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:19:29 by mkardes           #+#    #+#             */
/*   Updated: 2022/02/24 15:20:56 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_bas_say(unsigned int c);
int	array_print(char *str);
int	ft_putchar_v2(char g);
int	hex_print(unsigned int n, char c);
int	ptr_printer(unsigned long n);
int	ptr_print(unsigned long n);
int	ft_uitoa(unsigned int a);
int	ft_strchecker(va_list arg, int g);
int	ft_printf(const char *str, ...);

#endif

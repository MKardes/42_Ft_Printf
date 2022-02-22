/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:19:29 by mkardes           #+#    #+#             */
/*   Updated: 2022/02/22 11:19:44 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_bas_say(unsigned int c);
int	array_print(char *str);
int	hex_print(unsigned int n);
int	hex_print_capital(unsigned int n);
int	ptr_printer(unsigned long n);
int	ptr_print(unsigned long n);
int	ft_continue(va_list arg, int c);
int	ft_uitoa(unsigned int a);
int	ft_chooser(va_list arg, int c);
int	ft_strchecker(const char *str, int i);
int	ft_printf(const char *str, ...);

#endif

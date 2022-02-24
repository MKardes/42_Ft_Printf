/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:06:32 by mkardes           #+#    #+#             */
/*   Updated: 2022/02/24 15:33:40 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_v2(char g)
{
	write(1, &g, 1);
	return (1);
}

int	hex_print(unsigned int n, char c)
{
	int				i;
	int				i1;
	int				len;
	char			*a;
	unsigned int	n1;

	if (c == 'X')
		a = ft_strdup("0123456789ABCDEF");
	else
		a = ft_strdup("0123456789abcdef");
	i = 1;
	n1 = n;
	while (n1 >= 16 && i++)
		n1 = n1 / 16;
	len = i;
	while (--i >= 0)
	{
		n1 = n;
		i1 = i;
		while (--i1 >= 0)
			n1 = n1 / 16;
		ft_putchar_fd(a[n1 % 16], 1);
	}
	free(a);
	return (len);
}

int	ptr_printer(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ptr_printer(n / 16);
		ptr_printer(n % 16);
	}
	else
		ft_putchar_fd(a[n], 1);
	free(a);
	return (0);
}

int	ptr_print(unsigned long n)
{
	int	i;

	i = 1;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ptr_printer(n);
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}

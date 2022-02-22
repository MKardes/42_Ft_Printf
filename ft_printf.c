/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:06:49 by mkardes           #+#    #+#             */
/*   Updated: 2022/02/22 11:12:49 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_continue(va_list arg, int c)
{
	if (c == 6)
		return (hex_print(va_arg(arg, unsigned int)));
	if (c == 7)
		return (hex_print_capital(va_arg(arg, unsigned int)));
	if (c == 8)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_chooser(va_list arg, int c)
{
	char	*a;
	int		len;

	if (c == 1)
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return (1);
	}
	if (c == 2)
		return (array_print(va_arg(arg, char *)));
	if (c == 3)
		return (ptr_print(va_arg(arg, unsigned long)));
	if (c == 4)
	{
		a = ft_itoa(va_arg(arg, int));
		len = array_print(a);
		free(a);
		return (len);
	}
	if (c == 5)
		return (ft_uitoa(va_arg(arg, unsigned int)));
	return (ft_continue(arg, c));
}

int	ft_strchecker(const char *str, int i)
{
	if (str[i] == 'c')
		return (1);
	if (str[i] == 's')
		return (2);
	if (str[i] == 'p')
		return (3);
	if (str[i] == 'd' || str[i] == 'i')
		return (4);
	if (str[i] == 'u')
		return (5);
	if (str[i] == 'x')
		return (6);
	if (str[i] == 'X')
		return (7);
	if (str[i] == '%')
		return (8);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;
	int		c;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			c = ft_strchecker(str, i);
			len += ft_chooser(arg, c);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
/*
int main()
{
    int             as;
    int             a = 121241241;
    char            s[] = "_asrfassdgsaga_";
    char            v = 'a';
    char            *glcn;
    static char     *c;
    unsigned int    xx = 463667312;
    unsigned int    xc = 126467124;
    unsigned int    hhh = 4294967295;

    glcn = ft_strdup("asfghsgusjghsdg");

    as = ft_printf("%d, %s, %c, %s, %u, %x, %X,%%%%%%, %p", a, s, v, c, hhh, xc, xx, glcn);
    printf("\n\n%d\n\n",as);
    as = printf("%d, %s, %c, %s, %u, %x, %X,%%%%%%, %p", a, s, v, c, hhh, xc, xx, glcn);
    printf("\n\n%d\n\n",as);
}*/

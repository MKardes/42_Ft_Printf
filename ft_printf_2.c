/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:06:42 by mkardes           #+#    #+#             */
/*   Updated: 2022/02/22 11:15:39 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bas_say(unsigned int c)
{
	int	i;

	i = 0;
	while (c >= 10)
	{
		c = c / 10;
		i++;
	}
	return (i + 1);
}

int	array_print(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[len])
	{
		ft_putchar_fd(str[len], 1);
		len++;
	}
	return (len);
}

int	ft_uitoa(unsigned int a)
{
	int		len;
	char	*str;

	len = ft_bas_say(a);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = a % 10 + 48;
		a = a / 10;
		len--;
	}
	len = array_print(str);
	free(str);
	return (len);
}

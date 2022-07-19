/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkardes <mkardes@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:43:16 by mkardes           #+#    #+#             */
/*   Updated: 2022/07/19 23:11:03 by mkardes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		mlx_new_window(mlx_init(), 1000, 1000, "Heyyo");
		ft_printf("\n\nŞimdiye dek BAŞARILI.\n\n(ŞİMDİYE DEK)\n");
	}
	return (0);
}

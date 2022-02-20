#include "ft_printf.h"
#include "libft/libft.h"

void	ft_chooser(va_list arg, int c)
{
	char	*a;
	char	*b;

	a = ft_strdup("(null)");
	a[6] = '\0';
	if (c == 1)
		ft_putchar_fd(va_arg(arg, int), 1);
	if (c == 2)
	{
		b = va_arg(arg, char *);
		if (!b)
			ft_putstr_fd(a, 1);
		else
			ft_putstr_fd(b, 1);
	}
	if (c == 4)
		ft_putnbr_fd(va_arg(arg, int), 1);
}

int	ft_percentage(const char *str, int i)
{
	return (8);
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
		return(ft_percentage(str, i));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
		va_start(arg, str);
		int	i;
		int	c;

		i = 0;
		while (str[i])
		{
			if (str[i] == '%')
			{
				i++;
				c = ft_strchecker(str, i);
			}
			else
				ft_putchar_fd(str[i], 1);
			ft_chooser(arg, c);
			i++;
		}
		//ft_print_args(c, str);
		va_end(arg);
}

int	main()
{
	int	a = 121241241;
	char	s[] = "_asrfassdgsaga_";
	char	v = 'a';
	static char *c;
	ft_printf("%s, %d, %d, %d", c, a, a, a);
}

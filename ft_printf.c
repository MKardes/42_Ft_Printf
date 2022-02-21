#include "ft_printf.h"
#include "libft/libft.h"

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
		return(6);
	}
	while (str[len])
	{
		ft_putchar_fd(str[len], 1);
		len++;
	}
	return(len);
}

int hex_print_capital(unsigned int n)
{
    int             i;
    int             i1;
    int             len;
    char            *a;
    unsigned int    n1;

    a = ft_strdup("0123456789ABCDEF");
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
	return(0);
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
	return(i + 2);	
}

int	hex_print(unsigned int n)
{
	int				i;
	int				i1;
	int				len;
	char			*a;
	unsigned int	n1;

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

int	ft_continue(va_list arg, int c)
{
	if (c == 6)
		return(hex_print(va_arg(arg, unsigned int)));
	if (c == 7)
		return(hex_print_capital(va_arg(arg, unsigned int)));
	if (c == 8)
	{
		ft_putchar_fd('%', 1);
		return(1);
	}
	return (0);
}

int ft_uitoa(unsigned int a)
{
    int     len;
    char    *str;

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
    return(len);
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
		return(ptr_print(va_arg(arg, unsigned long)));
	if (c == 4)
	{
		a = ft_itoa(va_arg(arg, int));
		len = array_print(a);
		free(a);
		return (len);
	}
	if (c == 5)
			return (ft_uitoa(va_arg(arg, unsigned int)));
	return(ft_continue(arg, c));
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
		va_start(arg, str);
		int	len;
		int	i;
		int	c;

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
		//ft_print_args(c, str);
		va_end(arg);
		return(len);
}

int	main()
{
	int	a = 121241241;
	char	s[] = "_asrfassdgsaga_";
	char	v = 'a';
	unsigned int	xx = 463667312;
	static char *c;
	char	*glcn;
	glcn = ft_strdup("asfghsgusjghsdg");
	int	as;
	unsigned int hhh = 4294967295;
	as = ft_printf("%d, %s, %c, %s, %u, %X,%%%%%%, %p", a, s, v, c, hhh, xx, glcn);
	printf("\n\n%d\n\n",as);
	as = printf("%d, %s, %c, %s, %u, %X,%%%%%%, %p", a, s, v, c, hhh, xx, glcn);
    printf("\n\n%d\n\n",as);
}

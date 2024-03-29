// HEADER TO ADD
#include "../include/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstring(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	char	*num;
	int		l;

	l = 0;
	num = ft_itoa(n);
	l = ft_printstring(num);
	free(num);
	return (l);
}

int	ft_printpercent(void)
{
	write(1, "%%", 1);
	return (1);
}

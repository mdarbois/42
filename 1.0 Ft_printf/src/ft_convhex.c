// HEADER TO ADD
#include "../include/ft_printf.h"

static int	ft_hex_lex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printhexlow(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else if (num >= 16)
	{
		ft_printhexlow(num / 16);
		ft_printhexlow(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
	return (ft_hex_lex(num));
}

int	ft_printhexup(unsigned int num)
{
	if (num == 0)
	{
		return (write(1, "0", 1));
	}
	else if (num >= 16)
	{
		ft_printhexup(num / 16);
		ft_printhexup(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'A'), 1);
	}
	return (ft_hex_lex(num));
}

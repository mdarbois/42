// HEADER TO ADD
#include "../include/ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
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

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printvoidptr(unsigned long long ptr)
{
	int	l;

	l = 0;
	l += write(1, "0x", 2);
	if (ptr == 0)
		l += write (1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		l += ft_ptr_len(ptr);
	}
	return (l);
}

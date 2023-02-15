// HEADER TO ADD

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_format(va_list ptr, const char input);
int	ft_printchar(int c);
int	ft_printstring(const char *str);
int	ft_printnbr(int n);
int	ft_printpercent(void);
int	ft_printunsdec(unsigned int n);
int	ft_printvoidptr(unsigned long long ptr);
int	ft_printhexlow(unsigned int num);
int	ft_printhexup(unsigned int num);

#endif
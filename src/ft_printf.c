// HEADER TO ADD
#include "../include/ft_printf.h"

int	ft_format(va_list ptr, const char input)
{
	int	string;

	string = 0;
	if (input == 'c')
		string += ft_printchar(va_arg(ptr, int));
	else if (input == 's')
		string += ft_printstring(va_arg(ptr, char *));
	else if (input == 'p')
		string += ft_printvoidptr(va_arg(ptr, unsigned long long));
	else if (input == 'd' || input == 'i')
		string += ft_printnbr(va_arg(ptr, int));
	else if (input == 'u')
		string += ft_printunsdec(va_arg(ptr, unsigned int));
	else if (input == 'x')
		string += ft_printhexlow(va_arg(ptr, unsigned int));
	else if (input == 'X')
		string += ft_printhexup(va_arg(ptr, int));
	else if (input == '%')
		string += ft_printpercent();
	return (string);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		string;
	int		i;

	string = 0;
	i = 0;
	if (s == NULL)
		return (0);
	va_start (ptr, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			string += ft_format(ptr, s[i + 1]);
			i++;
		}
		else
		{
			string += ft_printchar(s[i]);
		}
		i++;
	}
	va_end(ptr);
	return (string);
}

/*
// 1. avancer jusqu'au premier "
int i;
i = 0; 
while (input[i] != '"')
	i++

// 2. trouver le nombre de %
int count;
count = 0; 
while (input[i] != '%' && input[i] != '\0') 
{	
	i++;
	if (input[i] == '%' && input[i+1] != '%')
		count++;
}
	return(count);
// count sera le nombre de fois ou on loopera
// 3. on print la premiere partie avant les %
i = 0;
while (input[i] != '%' && input[i] != '\0') 
{
	write(1,&input[i],1);
	i++;
}
// 4. on regarde quel est la conversion à faire

// 5. on va voir le nom de la variable
size_t length;
length = ft_len(input);
*/
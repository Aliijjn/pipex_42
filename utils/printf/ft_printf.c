/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 15:01:55 by akuijer       #+#    #+#                 */
/*   Updated: 2024/01/17 13:47:38 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_type(int *count, char *str, va_list ap)
{
	if (*str == 'c')
		print_chr(count, (char)va_arg(ap, int));
	else if (*str == 's')
		print_str(count, va_arg(ap, char *));
	else if (*str == 'p')
		print_hex(count, 0, 1, va_arg(ap, unsigned long));
	else if (*str == 'd' || *str == 'i')
		print_nbr(count, 0, va_arg(ap, int));
	else if (*str == 'u')
		print_nbr(count, 1, va_arg(ap, unsigned int));
	else if (*str == 'x')
		print_hex(count, 0, 0, va_arg(ap, unsigned int));
	else if (*str == 'X')
		print_hex(count, 1, 0, va_arg(ap, unsigned int));
	else if (*str == '%')
		print_chr(count, '%');
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_type(&count, (char *)str + i + 1, ap);
			i++;
			if (str[i])
			{
				i++;
			}
			continue ;
		}
		write(1, &str[i], 1);
		count++;
		i++;
	}
	va_end(ap);
	return (count);
}

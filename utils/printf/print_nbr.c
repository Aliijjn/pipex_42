/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_nbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 13:35:19 by akuijer       #+#    #+#                 */
/*   Updated: 2023/11/09 13:42:06 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_int_length(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
	{
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*uitoa(unsigned int n)
{
	int		length;
	char	*str;

	length = get_int_length(n);
	str = (char *)ft_calloc(length + 1, sizeof(char));
	if (!str)
	{
		return (0);
	}
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n != 0)
	{
		str[--length] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

void	print_nbr(int *count, int is_unsigned, long number)
{
	char	*str;

	if (is_unsigned)
	{
		str = uitoa((unsigned int)number);
	}
	else
	{
		str = ft_itoa((int)number);
	}
	if (!str)
	{
		return ;
	}
	(*count) += write(1, str, (int)ft_strlen(str));
	free(str);
}

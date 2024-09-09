/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 16:01:52 by akuijer       #+#    #+#                 */
/*   Updated: 2023/11/10 17:04:59 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_str(char *table, unsigned long number)
{
	unsigned long	temp_number;
	int				length;
	char			*result;

	temp_number = number;
	length = 0;
	while (temp_number)
	{
		temp_number /= 16;
		length++;
	}
	result = ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (--length >= 0)
	{
		result[length] = table[number % 16];
		number /= 16;
	}
	return (result);
}

void	print_hex(int *count, int uppercase, int adress, unsigned long number)
{
	char	*table;
	char	*result;

	table = "0123456789abcdef";
	if (uppercase)
		table = "0123456789ABCDEF";
	if (adress && !number)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	if (adress)
		*count += write(1, "0x", 2);
	if (!number)
	{
		*count += write(1, "0", 1);
		return ;
	}
	result = create_str(table, number);
	if (result)
	{
		*count += write(1, result, ft_strlen(result));
		free(result);
	}
}

// #include <stdio.h>

// int main()
// {
// 	int count = 0;
// 	print_hex(&count, 1, 1, 266);
// 	printf("\n%i", count);
// }
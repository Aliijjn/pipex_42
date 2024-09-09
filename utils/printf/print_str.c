/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 12:12:09 by akuijer       #+#    #+#                 */
/*   Updated: 2023/11/10 15:44:48 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(int *count, char *str)
{
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	*count += write(1, str, (int)ft_strlen(str));
}

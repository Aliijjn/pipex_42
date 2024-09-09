/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_chr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 13:21:51 by akuijer       #+#    #+#                 */
/*   Updated: 2023/11/09 13:43:50 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_chr(int *count, char c)
{
	*count += write(1, &c, 1);
}

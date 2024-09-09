/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 16:03:39 by akuijer       #+#    #+#                 */
/*   Updated: 2023/11/09 13:28:29 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"

void	print_str(int *count, char *str);
void	print_hex(int *count, int uppercase, int adress, unsigned long number);
void	print_nbr(int *count, int is_signed, long number);
void	print_chr(int *count, char c);
int		ft_printf(const char *str, ...);

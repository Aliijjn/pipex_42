/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 11:19:57 by akuijer       #+#    #+#                 */
/*   Updated: 2024/03/08 15:17:48 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_error(char *error_msg, char exit_val)
{
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	exit(exit_val);
}

void	ft_perror(char *error_msg, char exit_val)
{
	if (error_msg)
		perror(error_msg);
	exit(exit_val);
}

void	free_and_throw(char *err_msg, char exit_val, char **s1, char **s2)
{
	free_split(s1);
	free_split(s2);
	ft_error(err_msg, exit_val);
}

void	*ft_realloc(void *ptr_in, int size, int add)
{
	char	*ptr_out;
	int		i;

	i = 0;
	ptr_out = ft_calloc(size + add, 1);
	if (!ptr_out)
	{
		free(ptr_in);
		return (NULL);
	}
	while (i < size && i < size + add)
	{
		*((char *)ptr_out + i) = *((char *)ptr_in + i);
		i++;
	}
	free(ptr_in);
	return (ptr_out);
}

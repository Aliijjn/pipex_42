/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 15:05:53 by akuijer       #+#    #+#                 */
/*   Updated: 2024/03/08 15:55:25 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/gnl/get_next_line.h"
#include "../utils/printf/ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct t_cmd_info
{
	char	*path;
	char	**cmd;
}	t_cmd_info;

void		free_split(char **split);
void		*ft_realloc(void *ptr_in, int size, int add);
void		ft_error(char *error_msg, char exit_val);
void		ft_perror(char *error_msg, char exit_val);
void		free_and_throw(char *err_msg, char exit_val, char **s1, char **s2);
t_cmd_info	find_path(char **env, char *command);

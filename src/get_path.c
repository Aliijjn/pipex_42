/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 16:04:29 by akuijer       #+#    #+#                 */
/*   Updated: 2024/03/12 15:24:13 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **paths, char **command)
{
	char	*result;
	int		i;

	i = 0;
	while (paths[i])
	{
		paths[i] = ft_realloc(paths[i], ft_strlen(paths[i]) + 1, \
				ft_strlen(command[0]) + 1);
		if (!paths[i])
			free_and_throw("Realloc error\n", 1, paths, command);
		paths[i][ft_strlen(paths[i])] = '/';
		ft_memcpy(paths[i] + ft_strlen(paths[i]), command[0], \
				+ ft_strlen(command[0]));
		if (!access(paths[i], X_OK))
		{
			result = ft_calloc(ft_strlen(paths[i]) + 1, 1);
			if (!result)
				free_and_throw("Malloc error\n", 1, paths, command);
			ft_memcpy(result, paths[i], ft_strlen(paths[i]) + 1);
			return (free_split(paths), result);
		}
		i++;
	}
	return (free_and_throw("Command not found!\n", 127, paths, command), NULL);
}

static char	*check_dir_path(char **paths, char **command)
{
	char	*result;

	if (!access(command[0], F_OK) && !access(command[0], X_OK))
	{
		result = ft_calloc(ft_strlen(command[0]) + 1, 1);
		if (!result)
		{
			free_and_throw("Malloc error\n", 1, paths, command);
		}
		ft_memcpy(result, command[0], ft_strlen(command[0]));
		return (free_split(paths), result);
	}
	return (NULL);
}

t_cmd_info	find_path(char **env, char *command)
{
	int		i;
	char	**paths;
	char	**split_cmd;
	char	*dir_path;

	i = 0;
	paths = NULL;
	split_cmd = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			paths = ft_split(env[i] + 5, ':');
			split_cmd = ft_split(command, ' ');
			if (!paths || !split_cmd)
				free_and_throw("Split broke\n", 1, paths, split_cmd);
			dir_path = check_dir_path(paths, split_cmd);
			if (dir_path)
				return ((t_cmd_info){dir_path, split_cmd});
			return ((t_cmd_info){get_path(paths, split_cmd), split_cmd});
		}
		i++;
	}
	free_and_throw("No path found\n", 1, paths, split_cmd);
	return ((t_cmd_info){NULL, NULL});
}

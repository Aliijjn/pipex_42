/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 15:05:57 by akuijer       #+#    #+#                 */
/*   Updated: 2024/03/12 16:07:44 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *pipe, char **env)
{
	int			fd1;
	t_cmd_info	cmd_info;

	close(pipe[0]);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		ft_perror("Invalid FD", 1);
	}
	if (dup2(fd1, STDIN_FILENO) == -1 || dup2(pipe[1], STDOUT_FILENO) == -1)
	{
		ft_perror("dup2 error", 1);
	}
	cmd_info = find_path(env, argv[2]);
	close(pipe[1]);
	close(fd1);
	if (execve(cmd_info.path, cmd_info.cmd, env) == -1)
	{
		free(cmd_info.path);
		free_split(cmd_info.cmd);
		ft_perror("Error executing", 1);
	}
	free(cmd_info.path);
	free_split(cmd_info.cmd);
	exit(0);
}

void	child_process_two(char **argv, int *pipe, char **env)
{
	int			fd2;
	t_cmd_info	cmd_info;

	close(pipe[1]);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
	{
		ft_perror("Invalid FD", 1);
	}
	if (dup2(pipe[0], STDIN_FILENO) == -1 || dup2(fd2, STDOUT_FILENO) == -1)
	{
		ft_perror("dup2 error", 1);
	}
	cmd_info = find_path(env, argv[3]);
	close(pipe[0]);
	close(fd2);
	if (execve(cmd_info.path, cmd_info.cmd, env) == -1)
	{
		free(cmd_info.path);
		free_split(cmd_info.cmd);
		ft_perror("Error executing", 1);
	}
	free(cmd_info.path);
	free_split(cmd_info.cmd);
	exit(0);
}

void	fancy_fork(int *pid_ptr)
{
	*pid_ptr = fork();
	if (pid_ptr < 0)
	{
		ft_perror("Fork broke", 1);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid[2];
	int	status;

	if (argc != 5)
		ft_error("Invalid argc count\n", 1);
	if (pipe(fd) == -1)
		ft_perror("Pipe error", 1);
	fancy_fork(&pid[0]);
	if (pid[0] == 0)
		child_process(argv, fd, env);
	fancy_fork(&pid[1]);
	if (pid[1] == 0)
		child_process_two(argv, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	exit(WEXITSTATUS(status));
	return (0);
}

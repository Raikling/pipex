/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:21:01 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/03/09 11:29:00 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_param(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Wrong number of Args\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	free_string_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_2d_array(char ***arr, int size)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (i < size)
		{
			free_string_array(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	exe_child1(t_pipex *pipex, char **env)
{
	if (pipex->pid1 == -1)
	{
		perror("Fork 1");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->pipefds[0]);
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->pipefds[1], STDOUT_FILENO);
	close(pipex->fd_in);
	close(pipex->pipefds[1]);
	execve(pipex->cmd_paths[0], pipex->cmd_args[0], env);
	perror("Execve cmd 1");
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}

void	exe_child2(t_pipex *pipex, char **env)
{
	if (pipex->pid2 == -1)
	{
		perror("Fork 2");
		ft_cleanup(pipex);
		exit(EXIT_FAILURE);
	}
	close(pipex->pipefds[1]);
	dup2(pipex->pipefds[0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_out);
	close(pipex->pipefds[0]);
	execve(pipex->cmd_paths[1], pipex->cmd_args[1], env);
	perror("Execve cmd 2");
	ft_cleanup(pipex);
	exit(EXIT_FAILURE);
}

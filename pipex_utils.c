/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:15:49 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/03/09 11:20:47 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->pipefds[0] = -1;
	pipex->pipefds[1] = -1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
}

void	ft_cleanup(t_pipex *pipex)
{
	if (pipex->fd_in >= 0)
		close(pipex->fd_in);
	if (pipex->fd_out >= 0)
		close(pipex->fd_out);
	if (pipex->pipefds[0] >= 0)
		close(pipex->pipefds[0]);
	if (pipex->pipefds[1] >= 0)
		close(pipex->pipefds[1]);
	free_string_array(pipex->cmd_paths);
	free_2d_array(pipex->cmd_args, 2);
	ft_init_pipex(pipex);
}

int	ft_check_args(t_pipex *pipex, char *file1, char *file2)
{
	pipex->fd_in = open(file1, O_RDONLY);
	if (pipex->fd_in == -1)
	{
		ft_printf("Failed Reading from %s\n", file1);
		return (-1);
	}
	pipex->fd_out = open(file2, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipex->fd_out == -1)
	{
		ft_printf("Failed OUTFILE");
		close(pipex->fd_in);
		pipex->fd_in = -1;
		return (-1);
	}
	return (0);
}

char	***ft_parse_args(char *cmd1, char *cmd2)
{
	char	***args;

	args = malloc(3 * sizeof(char **));
	if (!args)
		return (NULL);
	args[0] = ft_split(cmd1, ' ');
	if (!args[0])
	{
		free(args);
		return (NULL);
	}
	args[1] = ft_split(cmd2, ' ');
	if (!args[1])
	{
		free_string_array(args[0]);
		free(args);
		return (NULL);
	}
	args[2] = NULL;
	return (args);
}
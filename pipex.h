/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:09:29 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/03/09 11:12:00 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pipefds[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd_paths;
	char	***cmd_args;
}	t_pipex;

void	ft_init_pipex(t_pipex *pipex);
void	ft_cleanup(t_pipex *pipex);
void	free_string_array(char **arr);
void	free_2d_array(char ***arr, int size);
int		ft_check_args(t_pipex *pipex, char *file1, char *file2);
char	***ft_parse_args(char *cmd1, char *cmd2);
char	**ft_parse_path(char *cmd1, char *cmd2, char **env);
void	check_param(int ac);
void	exe_child1(t_pipex *pipex, char **env);
void	exe_child2(t_pipex *pipex, char **env);

#endif

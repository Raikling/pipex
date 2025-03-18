/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <aben-hzz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:39:23 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/03/14 21:48:09 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*get_command_base(char *cmd)
{
	char	*space;

	space = ft_strchr(cmd, ' ');
	if (space)
		return (ft_substr(cmd, 0, space - cmd));
	else
		return (ft_strdup(cmd));
}


char *get_exe_path(char **dirs, char *cmd_base) 
{
    int i;
    char *path;
    char *tmp;

    if (cmd_base[0] == '/') 
	{
        if (access(cmd_base, X_OK) == 0)
            return ft_strdup(cmd_base);
        return NULL;
    }
    i = 0;
    while (dirs[i]) 
	{
        if (dirs[i][ft_strlen(dirs[i]) - 1] == '/') 
            tmp = ft_strjoin(dirs[i], cmd_base);
		else 
		{
            char *dir_with_slash = ft_strjoin(dirs[i], "/");
            tmp = ft_strjoin(dir_with_slash, cmd_base);
            free(dir_with_slash);
        }
        if (!tmp)
            return NULL;
        if (access(tmp, X_OK) == 0)
            return (tmp);
        free(tmp);
        i++;
    }
    return (NULL);
}

void	set_command_paths(char **paths, char *cmd1, char *cmd2, char **env)
{
	int		i;
	char	**dirs;
	char	*cmd1_base;
	char	*cmd2_base;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return ;
	dirs = ft_split(env[i] + 5, ':');
	cmd1_base = get_command_base(cmd1);
	cmd2_base = get_command_base(cmd2);
	paths[0] = get_exe_path(dirs, cmd1_base);
	paths[1] = get_exe_path(dirs, cmd2_base);
	free_string_array(dirs);
	free(cmd1_base);
	free(cmd2_base);
}

char	**ft_parse_path(char *cmd1, char *cmd2, char **env)
{
	char	**paths;

	paths = malloc(3 * sizeof(char *));
	if (!paths || !env)
	{
		free(paths);
		return (NULL);
	}
	paths[2] = NULL;
	set_command_paths(paths, cmd1, cmd2, env);
	if (!paths[0] || !paths[1])
	{
		// free_string_array(paths);
		// return (NULL);
		if (paths[0])
			free(paths[0]);
		if (paths[1])
			free(paths[1]);
		free(paths);
		return (NULL);
	}
	return (paths);
}


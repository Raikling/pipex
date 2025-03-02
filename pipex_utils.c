#include "pipex.h"

void ft_init_pipex(t_pipex *pipex)
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
void ft_cleanup(t_pipex *pipex)
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

int ft_check_args(t_pipex *pipex, char *file1, char *file2)
{
    pipex->fd_in = open(file1, O_RDONLY);
    if (pipex->fd_in == -1)
    {
        perror("open infile");
        return (-1);
    }
    pipex->fd_out = open(file2, O_WRONLY);
    if (pipex->fd_out == -1)
    {
        perror("open outfile");
        close(pipex->fd_in);
        pipex->fd_in = -1;
        return (-1);
    }
    return (0);
}


char ***ft_parse_args(char *cmd1, char *cmd2)
{
    char ***args = malloc(3 * sizeof(char **));
    if (!args) return (NULL);

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



char **ft_parse_cmds(char *cmd1, char *cmd2, char **env) {
    char **paths = malloc(3 * sizeof(char *));
    if (!paths) return (NULL);
    paths[0] = NULL;
    paths[1] = NULL;
    paths[2] = NULL;
    if (!env)
    { 
        free(paths);
        return (NULL);
    }
    int i = 0;
    while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0) i++;
    if (!env[i]) { free(paths); return (NULL); }
    char **dirs = ft_split(env[i] + 5, ':');
    char *space1 = ft_strchr(cmd1, ' ');
    char *cmd1_base;
    if (space1) cmd1_base = ft_substr(cmd1, 0, space1 - cmd1);
    else cmd1_base = ft_strdup(cmd1);
    char *space2 = ft_strchr(cmd2, ' ');
    char *cmd2_base;
    if (space2) cmd2_base = ft_substr(cmd2, 0, space2 - cmd2);
    else cmd2_base = ft_strdup(cmd2);
    i = 0;
    while (dirs[i] && !paths[0]) {
        char *tmp = ft_strjoin(dirs[i++], "/");
        paths[0] = ft_strjoin(tmp, cmd1_base);
        free(tmp);
        if (paths[0] && access(paths[0], X_OK) == 0) break;
        free(paths[0]); paths[0] = NULL;
    }
    if (!paths[0]) paths[0] = ft_strdup(cmd1_base);
    i = 0;
    while (dirs[i] && !paths[1]) { 
        char *tmp = ft_strjoin(dirs[i++], "/");
        paths[1] = ft_strjoin(tmp, cmd2_base);
        free(tmp);
        if (paths[1] && access(paths[1], X_OK) == 0) break;
        free(paths[1]); paths[1] = NULL;
    }
    if (!paths[1]) paths[1] = ft_strdup(cmd2_base);
    free_string_array(dirs);
    free(cmd1_base);
    free(cmd2_base);
    if (!paths[0] || !paths[1])
    { 
        free_string_array(paths);
        return (NULL);
    }
    return (paths);
}



